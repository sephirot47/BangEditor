#ifndef TRANSLATEGIZMO_H
#define TRANSLATEGIZMO_H

#include "Bang/Axis.h"
#include "Bang/GameObject.h"

#include "BangEditor/SelectionGizmo.h"

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

FORWARD class TranslateGizmoAxis;

class TranslateGizmo : public SelectionGizmo
{
    GAMEOBJECT_EDITOR(TranslateGizmo);

public:
    // SelectionGizmo
    void SetReferencedGameObject(GameObject *referencedGameObject) override;

private:
    TranslateGizmoAxis *p_axisX = nullptr;
    TranslateGizmoAxis *p_axisY = nullptr;
    TranslateGizmoAxis *p_axisZ = nullptr;

    TranslateGizmo();
    virtual ~TranslateGizmo();
};


NAMESPACE_BANG_EDITOR_END

#endif // TRANSLATEGIZMO_H

