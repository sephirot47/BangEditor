#ifndef EDITORCLIPBOARD_H
#define EDITORCLIPBOARD_H

#include "Bang/Bang.h"
#include "BangEditor/BangEditor.h"

FORWARD NAMESPACE_BANG_BEGIN
FORWARD class Component;
FORWARD class GameObject;
FORWARD NAMESPACE_BANG_END

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

class EditorClipboard
{
public:
    EditorClipboard() = default;
    virtual ~EditorClipboard() = default;

    static void CopyComponent(Component *component);
    static Component *GetCopiedComponent();
    static bool HasCopiedComponent();
    static void ClearCopiedComponent();

    static void CopyGameObject(GameObject *gameObject);
    static GameObject *GetCopiedGameObject();
    static bool HasCopiedGameObject();
    static void ClearCopiedGameObject();

private:
    Component *m_copiedComponent = nullptr;
    GameObject *m_copiedGameObject = nullptr;

    static EditorClipboard *GetInstance();
};

NAMESPACE_BANG_EDITOR_END

#endif // EDITORCLIPBOARD_H

