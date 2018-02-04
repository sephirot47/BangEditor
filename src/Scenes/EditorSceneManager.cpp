#include "BangEditor/EditorSceneManager.h"

#include "Bang/Time.h"
#include "Bang/Scene.h"
#include "Bang/AudioManager.h"
#include "Bang/UILayoutManager.h"

#include "BangEditor/Editor.h"
#include "BangEditor/EditorScene.h"
#include "BangEditor/EditorBehaviourManager.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

EditorSceneManager::~EditorSceneManager()
{
    // Dont delete active scene because ~SceneManager does it
    if (GetOpenScene() && GetOpenScene() != GetActiveScene())
    {
        GameObject::Destroy( GetOpenScene() );
    }

    if (GetEditorScene() && GetEditorScene() != GetActiveScene())
    {
        GameObject::Destroy( GetEditorScene() );
    }
}

Scene *EditorSceneManager::GetOpenScene()
{
    EditorSceneManager *esm = EditorSceneManager::GetActive();
    return esm ? esm->_GetOpenScene() : nullptr;
}

EditorScene *EditorSceneManager::GetEditorScene()
{
    EditorSceneManager *esm = EditorSceneManager::GetActive();
    return esm ? esm->_GetEditorScene() : nullptr;
}

EditorBehaviourManager* EditorSceneManager::GetEditorBehaviourManager() const
{
    return DCAST<EditorBehaviourManager*>( SceneManager::GetBehaviourManager() );
}

Scene *EditorSceneManager::_GetOpenScene() const
{
    EditorScene *edScene = GetEditorScene();
    return edScene ? edScene->GetOpenScene() : nullptr;
}

EditorScene *EditorSceneManager::_GetEditorScene() const
{
    return p_editorScene;
}

void EditorSceneManager::_LoadSceneInstantly(Scene *scene)
{
    EditorScene *edScene = _GetEditorScene();
    if (edScene)
    {
        if (edScene->GetOpenScene() == scene) { return; }
        edScene->SetOpenScene(scene);
    }
    else // Load editor scene
    {
        p_editorScene = SCAST<EditorScene*>(scene);
        SceneManager::_LoadSceneInstantly(scene);
    }
}

void EditorSceneManager::SetActiveScene(Scene *activeScene)
{
    GetActive()->_SetActiveScene(activeScene);
}

void EditorSceneManager::_Update()
{
    GetEditorBehaviourManager()->Update();
    SceneManager::_Update();
}

BehaviourManager *EditorSceneManager::CreateBehaviourManager() const
{
    return new EditorBehaviourManager();
}

EditorSceneManager *EditorSceneManager::GetActive()
{
    SceneManager *sm = SceneManager::GetActive();
    return sm ? Cast<EditorSceneManager*>(sm) : nullptr;
}
