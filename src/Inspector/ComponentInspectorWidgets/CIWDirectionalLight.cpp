#include "BangEditor/CIWDirectionalLight.h"

#include "Bang/UISlider.h"
#include "Bang/DirectionalLight.h"
#include "Bang/GameObjectFactory.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

void CIWDirectionalLight::InitInnerWidgets()
{
    CIWLight::InitInnerWidgets();

    SetName("CIWDirectionalLight");
    SetTitle("DirectionalLight");

    p_shadowDistanceInput = GameObjectFactory::CreateUISlider();
    p_shadowDistanceInput->SetMinMaxValues(1.0f, 2000.0f);
    p_shadowDistanceInput->EventEmitter<IValueChangedListener>::RegisterListener(this);
    AddWidget("Shadow dist.", p_shadowDistanceInput->GetGameObject());

    SetLabelsWidth(90);
}

void CIWDirectionalLight::UpdateFromReference()
{
    CIWLight::UpdateFromReference();

    if (!p_shadowDistanceInput->HasFocus())
    {
        p_shadowDistanceInput->SetValue( GetDirectionalLight()->GetShadowDistance() );
    }
}

DirectionalLight *CIWDirectionalLight::GetDirectionalLight() const
{
    return SCAST<DirectionalLight*>( GetLight() );
}

void CIWDirectionalLight::OnValueChanged(Object *object)
{
    CIWLight::OnValueChanged(object);

    GetDirectionalLight()->SetShadowDistance( p_shadowDistanceInput->GetValue() );
}
