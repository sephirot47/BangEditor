#include "BangEditor/Project.h"

#include <string>

#include "Bang/Paths.h"
#include "Bang/Time.h"
#include "Bang/XMLNode.h"
#include "Bang/Extensions.h"
#include "Bang/SceneManager.h"

#include "BangEditor/EditorSceneManager.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

Project::Project()
{
    m_id = GUID::GetRandomGUID();
}

Project::~Project()
{
}

const Path&  Project::GetProjectDirPath() const
{
    return m_projectRootFilepath;
}

Path Project::GetProjectAssetsRootFilepath() const
{
    return Path(m_projectRootFilepath + "/Assets");
}

Path Project::GetProjectFileFilepath() const
{
    return Path(m_projectRootFilepath + "/" +
                GetProjectName() + "." + Extensions::GetProjectExtension());
}

String Project::GetProjectName() const
{
    return m_projectRootFilepath.GetName();
}

const GUID& Project::GetProjectRandomId() const
{
    return m_id;
}

void Project::SetProjectRootFilepath(const Path &projectDir)
{
    m_projectRootFilepath = projectDir;
}

bool Project::OpenFirstFoundScene() const
{
    Path firstFoundScene = GetFirstFoundScenePath();
    if (firstFoundScene.IsFile())
    {
        EditorSceneManager::LoadScene(firstFoundScene);
    }

    return (firstFoundScene.IsFile());
}

Path Project::GetFirstFoundScenePath() const
{
    List<Path> sceneFilepaths = GetProjectAssetsRootFilepath()
                                .FindFiles(Path::FindFlag::Recursive,
                                           {Extensions::GetSceneExtension()});
    return !sceneFilepaths.IsEmpty() ? sceneFilepaths.Front() : Path::Empty;
}


void Project::ImportXML(const XMLNode &xmlInfo)
{
    if (xmlInfo.Contains("RandomID"))
    { m_id = xmlInfo.Get<GUID>("RandomID"); }
}

void Project::ExportXML(XMLNode *xmlInfo) const
{
    xmlInfo->SetTagName("Project");
    xmlInfo->Set("RandomID", m_id);
}