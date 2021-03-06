#include "BangEditor/UITabHeader.h"

#include "Bang/UICanvas.h"
#include "Bang/UIFocusable.h"
#include "Bang/UITextRenderer.h"
#include "Bang/UILayoutElement.h"
#include "Bang/UIImageRenderer.h"
#include "Bang/GameObjectFactory.h"
#include "Bang/UIHorizontalLayout.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

UITabHeader::UITabHeader()
{
    GameObjectFactory::CreateUIGameObjectInto(this);
    UIHorizontalLayout *titleHL = AddComponent<UIHorizontalLayout>();
    titleHL->SetPaddings(3, 0, 3, 2);

    UILayoutElement *le = AddComponent<UILayoutElement>();
    le->SetFlexibleHeight( 1.0f );
    le->SetLayoutPriority(1);

    p_bg = AddComponent<UIImageRenderer>();

    GameObject *titleGo = GameObjectFactory::CreateUIGameObject();
    p_titleText = titleGo->AddComponent<UITextRenderer>();
    p_titleText->SetHorizontalAlign(HorizontalAlignment::Left);
    p_titleText->SetVerticalAlign(VerticalAlignment::Bot);
    p_titleText->SetTextSize(11);
    p_titleText->SetContent( GetTitle() );

    p_focusable = AddComponent<UIFocusable>();
    p_focusable->AddClickedCallback([this](IFocusable*)
    {
        EventEmitter<ITabHeaderListener>::PropagateToListeners(
                    &ITabHeaderListener::OnTabHeaderClicked, this);
    });

    titleGo->SetParent(this);

    SetInForeground(false);
}

UITabHeader::~UITabHeader()
{
}

void UITabHeader::Update()
{
    GameObject::Update();

    UICanvas *canvas = UICanvas::GetActive(this);
    bool mouseOver = (canvas->IsMouseOver(p_focusable));
    p_bg->SetTint(mouseOver ? m_currentHeaderColor.WithValue(1.5f) :
                              m_currentHeaderColor);
}

void UITabHeader::SetInForeground(bool inForeground)
{
    m_currentHeaderColor = (inForeground ? ForegroundColor : BackgroundColor);
    p_bg->SetTint(m_currentHeaderColor);
}

void UITabHeader::SetTitle(const String &title)
{
    if (title != GetTitle())
    {
        m_title = title;
        p_titleText->SetContent( GetTitle() );
    }
}

const String &UITabHeader::GetTitle() const
{
    return m_title;
}

