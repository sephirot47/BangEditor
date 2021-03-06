#ifndef BEHAVIOURTRACKER_H
#define BEHAVIOURTRACKER_H

#include "Bang/Set.h"
#include "Bang/List.h"
#include "Bang/Path.h"
#include "Bang/FileTracker.h"

#include "BangEditor/ProjectManager.h"

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

class BehaviourTracker : public IFileTrackerListener
{
public:
	BehaviourTracker();
	virtual ~BehaviourTracker();

    void Update();
    void ForceCheckNow();

    bool HasBeenModified(const Path &sourcePath) const;
    List<Path> GetIncludeDirs() const;

    const FileTracker& GetFileTracker() const;

    // IFileTrackerListener
    void OnPathAdded(const Path &addedPath) override;
    void OnPathModified(const Path &modifiedPath) override;
    void OnPathRemoved(const Path &removedPath) override;

private:
    FileTracker m_fileTracker;
    Path m_previousProjectPath = Path::Empty;
    Set<Path> m_changedPathsFromLastUpdate;
};

NAMESPACE_BANG_EDITOR_END

#endif // BEHAVIOURTRACKER_H

