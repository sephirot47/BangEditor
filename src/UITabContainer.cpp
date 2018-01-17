#include "BangEditor/UITabContainer.h"

#include "Bang/RectTransform.h"
#include "Bang/UITextRenderer.h"
#include "Bang/UILayoutElement.h"
#include "Bang/UIVerticalLayout.h"
#include "Bang/GameObjectFactory.h"
#include "Bang/UIHorizontalLayout.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

UITabContainer::UITabContainer()
{
    GameObjectFactory::CreateUIGameObjectInto(this);

    UIVerticalLayout *mainVL = AddComponent<UIVerticalLayout>();

    p_titleBar = GameObjectFactory::CreateUIGameObject();
    UIHorizontalLayout *titleBarHL = p_titleBar->AddComponent<UIHorizontalLayout>();
    titleBarHL->SetChildrenVerticalStretch(Stretch::None);
    titleBarHL->SetChildrenVerticalAlignment(VerticalAlignment::Bot);

    UILayoutElement *titleBarLE = p_titleBar->AddComponent<UILayoutElement>();
    titleBarLE->SetMinHeight(15);
    titleBarLE->SetLayoutPriority(2);

    p_currentTabContainer = GameObjectFactory::CreateUIGameObject();

    UILayoutElement *containerLE =
                    p_currentTabContainer->AddComponent<UILayoutElement>();
    containerLE->SetFlexibleSize(Vector2::One);

    p_currentTabContainer->AddComponent<UIHorizontalLayout>();

    p_titleBar->SetParent(this);
    GameObjectFactory::CreateUIHSeparator(LayoutSizeType::Flexible,
                                          1, 1.0f)->SetParent(this);
    p_currentTabContainer->SetParent(this);
}

UITabContainer::~UITabContainer()
{
}

void UITabContainer::AddTab(const String &title, GameObject *tabbedChild)
{
    if (!GetChildrenInTabs().Contains(tabbedChild))
    {
        GameObject *titleWrapper = GameObjectFactory::CreateUIGameObject();
        UIHorizontalLayout *titleHL = titleWrapper->AddComponent<UIHorizontalLayout>();
        titleHL->SetPaddings(3, 0, 3, 2);

        GameObject *titleGo = GameObjectFactory::CreateUIGameObject();
        UITextRenderer *titleText = titleGo->AddComponent<UITextRenderer>();
        titleText->SetHorizontalAlign(HorizontalAlignment::Left);
        titleText->SetVerticalAlign(VerticalAlignment::Bot);
        titleText->SetTextSize(11);
        titleText->SetContent(title);

        titleWrapper->SetParent(p_titleBar);
        titleGo->SetParent(titleWrapper);
        tabbedChild->SetParent( GetCurrentTabContainer() );

        p_childrenInTabs.PushBack(tabbedChild);
        m_childrenToTitleGo.Add(tabbedChild, titleGo);

        tabbedChild->SetEnabled(false);
        if (!GetCurrentTabChild()) { SetCurrentTabChild(tabbedChild); }
    }
}

void UITabContainer::SetTabTitle(GameObject *tabbedChild, const String &title)
{
    if (m_childrenToTitleGo.ContainsKey(tabbedChild))
    {
        GameObject *titleGo = m_childrenToTitleGo.Get(tabbedChild);
        UITextRenderer *titleText = titleGo->GetComponent<UITextRenderer>();
        titleText->SetContent(title);
    }
}

GameObject *UITabContainer::GetCurrentTabChild() const
{
    GameObject *currentTabChild = nullptr;
    if (GetCurrentTabIndex() >= 0 &&
        GetCurrentTabIndex() <= SCAST<int>(GetChildrenInTabs().Size()))
    {
        auto it = p_childrenInTabs.Begin();
        std::advance(it, GetCurrentTabIndex());
        currentTabChild = *it;
    }
    return currentTabChild;
}

int UITabContainer::GetCurrentTabIndex() const
{
    return m_currentTabIndex;
}

void UITabContainer::RemoveTab(GameObject *tabbedChild)
{
    p_childrenInTabs.Remove(tabbedChild);
    m_childrenToTitleGo.Remove(tabbedChild);
}

void UITabContainer::SetCurrentTabIndex(int index)
{
    if (index != GetCurrentTabIndex())
    {
        m_currentTabIndex = index;

        int i = 0;
        for(GameObject *tabbedChild : GetChildrenInTabs())
        {
            tabbedChild->SetEnabled( i == index );
            ++i;
        }
    }
}

void UITabContainer::SetCurrentTabChild(GameObject *currentTabChild)
{
    int index = GetChildrenInTabs().IndexOf(currentTabChild);
    SetCurrentTabIndex(index);
}

const List<GameObject*>& UITabContainer::GetChildrenInTabs() const
{
    return p_childrenInTabs;
}

GameObject *UITabContainer::GetCurrentTabContainer() const
{
    return p_currentTabContainer;
}

