#ifndef COMPONENTINSPECTORWIDGET_H
#define COMPONENTINSPECTORWIDGET_H

#include "Bang/Bang.h"
#include "Bang/ResourceHandle.h"
#include "Bang/IValueChangedListener.h"

#include "BangEditor/UIContextMenu.h"
#include "BangEditor/InspectorWidget.h"

FORWARD NAMESPACE_BANG_BEGIN
FORWARD class Texture2D;
FORWARD class UICheckBox;
FORWARD NAMESPACE_BANG_END

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

class ComponentInspectorWidget : public InspectorWidget,
                                 public IValueChangedListener
{
    GAMEOBJECT_EDITOR(InspectorWidget);

protected:
    ComponentInspectorWidget();
    virtual ~ComponentInspectorWidget();

    // InspectorWidget
    virtual void InitInnerWidgets() override;
    virtual void UpdateFromReference() override;

    virtual void SetComponent(Component *comp);

protected:
    Component *GetComponent() const;
    GameObject *GetInspectedGameObject() const;

    virtual void SetTitle(const String& title) override;
    virtual GameObject *CreateTitleGameObject() override;

    virtual bool CanBeRemovedFromContextMenu() const;
    virtual void OnValueChanged(Object *object) override;
    virtual RH<Texture2D> GetComponentIconTexture() const;

private:
    Component *p_component = nullptr;

    UIContextMenu *p_contextMenu = nullptr;

    UIImageRenderer *p_icon = nullptr;
    UITextRenderer *p_titleText = nullptr;
    UICheckBox *p_enabledCheckBox = nullptr;

    virtual void OnCreateContextMenu(MenuItem *menuRootItem);
    void MoveComponent(Component *comp, int offset);

    virtual bool MustShowEnabledCheckbox() const;

    friend class ComponentInspectorWidgetFactory;
};

NAMESPACE_BANG_EDITOR_END

#endif // COMPONENTINSPECTORWIDGET_H

