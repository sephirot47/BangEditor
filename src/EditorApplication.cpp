#include "BangEditor/EditorApplication.h"

#include "Bang/Debug.h"
#include "Bang/Scene.h"
#include "Bang/Window.h"
#include "Bang/Project.h"
#include "Bang/SceneManager.h"
#include "Bang/ProjectManager.h"
#include "BangEditor/EditorScene.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

EditorApplication::EditorApplication(int argc, char **argv,
                                     const Path &engineRootPath)
    : Application(argc, argv, engineRootPath)
{
}

EditorApplication::~EditorApplication()
{
}

void EditorApplication::OpenEditorScene(Window *containingWindow)
{
    m_editorScene = new EditorScene();
    containingWindow->GetSceneManager()->LoadScene(m_editorScene);

    Scene *scene = new Scene();
    Project *proj = ProjectManager::GetCurrentProject();
    if (proj)
    {
        scene->ImportXMLFromFile(proj->GetFirstFoundScenePath());
    }
    m_editorScene->SetOpenScene(scene);
}

void EditorApplication::SetupWindow(Window *window)
{
    Application::SetupWindow(window);
}



EditorScene *EditorApplication::GetEditorScene() const
{
    return m_editorScene;
}
