#include "BangEditor/CIWPointLight.h"

#include "Bang/PointLight.h"
#include "Bang/UIInputNumber.h"
#include "Bang/GameObjectFactory.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

void CIWPointLight::InitInnerWidgets()
{
    CIWLight::InitInnerWidgets();

    p_rangeInput = GameObjectFactory::CreateUIInputNumber();
    p_rangeInput->EventEmitter<IValueChangedListener>::RegisterListener(this);
    AddWidget("Range", p_rangeInput->GetGameObject());
}

void CIWPointLight::UpdateFromReference()
{
    CIWLight::UpdateFromReference();

    if (!p_rangeInput->HasFocus())
    {
        p_rangeInput->SetValue( GetPointLight()->GetRange() );
    }
}

PointLight *CIWPointLight::GetPointLight() const
{
    return SCAST<PointLight*>( GetLight() );
}

void CIWPointLight::OnValueChanged(Object *object)
{
    CIWLight::OnValueChanged(object);

    GetPointLight()->SetRange( p_rangeInput->GetValue() );
}
