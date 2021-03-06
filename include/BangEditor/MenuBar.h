#ifndef MENUBAR_H
#define MENUBAR_H

#include "Bang/Array.h"
#include "Bang/GameObject.h"

#include "BangEditor/BangEditor.h"
#include "BangEditor/ShortcutManager.h"

FORWARD NAMESPACE_BANG_BEGIN
FORWARD class UICanvas;
FORWARD class UIFocusable;
FORWARD class UIHorizontalLayout;
FORWARD NAMESPACE_BANG_END

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

FORWARD class MenuItem;

class MenuBar : public GameObject
{
    GAMEOBJECT_EDITOR(MenuBar);

public:
    void Update() override;

    MenuItem* AddItem();
    MenuItem* GetItem(int i);

    static constexpr int GetFixedHeight() { return 18; }

protected:
    MenuBar();
    virtual ~MenuBar();

private:
    MenuItem *m_fileItem = nullptr;
    MenuItem *m_editItem = nullptr;
    MenuItem *m_assetsItem = nullptr;
    MenuItem *m_componentsItem  = nullptr;
    MenuItem *m_gameObjectsItem = nullptr;

    Array<MenuItem*> m_items;
    UIFocusable *p_focusable = nullptr;
    MenuItem *p_currentTopItemBeingShown = nullptr;
    UIHorizontalLayout *m_horizontalLayout = nullptr;

    void RegisterShortcut(const Shortcut &shortcut);

    static void OnShortcutPressed(const Shortcut &shortcut);

    static void OnNewProject  (MenuItem *item);
    static void OnOpenProject (MenuItem *item);
    static void OnNewScene    (MenuItem *item);
    static void OnSaveScene   (MenuItem *item);
    static void OnSaveSceneAs (MenuItem *item);
    static void OnOpenScene   (MenuItem *item);
    static void OnBuild       (MenuItem *item);
    static void OnBuildAndRun (MenuItem *item);

    static void OnCreateMaterial (MenuItem *item);

    static void OnAddAudioListener        (MenuItem *item);
    static void OnAddAudioSource          (MenuItem *item);
    static void OnAddNewBehaviour         (MenuItem *item);
    static void OnAddExistingBehaviour    (MenuItem *item);
    static void OnAddEmptyBehaviour       (MenuItem *item);
    static void OnAddCamera               (MenuItem *item);
    static void OnAddPointLight           (MenuItem *item);
    static void OnAddDirectionalLight     (MenuItem *item);
    static void OnAddLineRenderer         (MenuItem *item);
    static void OnAddMeshRenderer         (MenuItem *item);
    static void OnAddTransform            (MenuItem *item);
    static void OnAddRectTransform        (MenuItem *item);
    static void OnAddPostProcessEffect    (MenuItem *item);
    static void OnAddUIAutoFocuser        (MenuItem *item);
    static void OnAddUIButton             (MenuItem *item);
    static void OnAddUICanvas             (MenuItem *item);
    static void OnAddUICheckBox           (MenuItem *item);
    static void OnAddUIComboBox           (MenuItem *item);
    static void OnAddUIFocusable          (MenuItem *item);
    static void OnAddUIHorizontalLayout   (MenuItem *item);
    static void OnAddUIImageRenderer      (MenuItem *item);
    static void OnAddUIInputText          (MenuItem *item);
    static void OnAddUILabel              (MenuItem *item);
    static void OnAddUILayoutElement      (MenuItem *item);
    static void OnAddUILayoutIgnorer      (MenuItem *item);
    static void OnAddUIMask               (MenuItem *item);
    static void OnAddUIRectMask           (MenuItem *item);
    static void OnAddUISlider             (MenuItem *item);
    static void OnAddUIScrollPanel        (MenuItem *item);
    static void OnAddUITextRenderer       (MenuItem *item);
    static void OnAddUIVerticalLayout     (MenuItem *item);

    static void OnCreateEmpty                    (MenuItem *item);
    static void OnCreateCone                     (MenuItem *item);
    static void OnCreateCube                     (MenuItem *item);
    static void OnCreatePlane                    (MenuItem *item);
    static void OnCreateSphere                   (MenuItem *item);
    static void OnCreateDirectionalLightGO       (MenuItem *item);
    static void OnCreatePointLightGO             (MenuItem *item);
    static UICanvas* OnCreateUICanvasGO          (MenuItem *item);
    static void OnCreateUIEmptyGO                (MenuItem *item);
    static void OnCreateUIImageGO                (MenuItem *item);
    static void OnCreateUITextGO                 (MenuItem *item);
    static void OnEndCreateGameObjectFromMenuBar   (GameObject *primitive);
    static void OnEndCreateUIGameObjectFromMenuBar (GameObject *uiGo);

    static void OpenProject(const Path& projectFileFilepath);

    static MenuBar* GetInstance();

    friend class ProjectManager;
    friend class SceneOpenerSaver;
};

NAMESPACE_BANG_EDITOR_END

#endif // MENUBAR_H
