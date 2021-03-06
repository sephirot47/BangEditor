#include "BangEditor/EditorApplication.h"

#include "Bang/Paths.h"
#include "Bang/Debug.h"
#include "Bang/Scene.h"
#include "Bang/Window.h"
#include "Bang/SceneManager.h"
#include "Bang/ImportFilesManager.h"

#include "BangEditor/Project.h"
#include "BangEditor/EditorPaths.h"
#include "BangEditor/EditorScene.h"
#include "BangEditor/EditorWindow.h"
#include "BangEditor/ProjectManager.h"
#include "BangEditor/EditorSceneManager.h"
#include "BangEditor/EditorBehaviourManager.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

EditorApplication::EditorApplication() : Application()
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::Init(const Path &engineRootPath)
{
    Application::Init(engineRootPath);

    GetEditorPaths()->InitEditorPath( Paths::GetExecutablePath().GetDirectory() );
    ImportFilesManager::CreateMissingImportFiles( EditorPaths::GetEditorAssetsDir() );
    ImportFilesManager::LoadImportFilepathGUIDs( EditorPaths::GetEditorAssetsDir() );
}

EditorPaths *EditorApplication::GetEditorPaths() const
{
    return SCAST<EditorPaths*>(GetPaths());
}

void EditorApplication::OpenEditorScene()
{
    EditorScene *edScene = GameObject::Create<EditorScene>();
    EditorSceneManager::LoadSceneInstantly(edScene, false);
    edScene->Init();
}

EditorApplication *EditorApplication::GetInstance()
{
    return SCAST<EditorApplication*>( Application::GetInstance() );
}

Paths *EditorApplication::CreatePaths()
{
    return new EditorPaths();
}
