#include "BangEditor/CIWBehaviourContainer.h"

#include "Bang/UIButton.h"
#include "Bang/Extensions.h"
#include "Bang/UITextRenderer.h"
#include "Bang/BehaviourContainer.h"

#include "BangEditor/EditorPaths.h"
#include "BangEditor/UIInputFile.h"
#include "BangEditor/EditorBehaviourManager.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

CIWBehaviourContainer::CIWBehaviourContainer() {}
CIWBehaviourContainer::~CIWBehaviourContainer() {}

void CIWBehaviourContainer::InitInnerWidgets()
{
    ComponentInspectorWidget::InitInnerWidgets();

    SetName("CIWBehaviourContainer");
    SetTitle("Behaviour");

    p_sourceInputFile = GameObject::Create<UIInputFile>();
    p_sourceInputFile->SetExtensions(Extensions::GetSourceFileExtensions());
    p_sourceInputFile->EventEmitter<IValueChangedListener>::RegisterListener(this);
    AddWidget("Source", p_sourceInputFile);

    SetLabelsWidth(60);
}

void CIWBehaviourContainer::UpdateFromReference()
{
    ComponentInspectorWidget::UpdateFromReference();

    const Path &srcPath = GetBehaviourContainer()->GetSourceFilepath();
    if (srcPath.IsFile())
    {
        SetTitle(srcPath.GetName());
        p_sourceInputFile->SetPath(srcPath);
    }
}

void CIWBehaviourContainer::OnValueChanged(Object *object)
{
    ComponentInspectorWidget::OnValueChanged(object);

    GetBehaviourContainer()->SetSourceFilepath( p_sourceInputFile->GetPath() );
}

BehaviourContainer *CIWBehaviourContainer::GetBehaviourContainer() const
{
    return SCAST<BehaviourContainer*>( GetComponent() );
}
