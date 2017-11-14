#ifndef CWTRANSFORM_H
#define CWTRANSFORM_H

#include "Bang/IValueChangedListener.h"

#include "BangEditor/ComponentWidget.h"

FORWARD NAMESPACE_BANG_BEGIN
FORWARD class Transform;
FORWARD NAMESPACE_BANG_END

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

FORWARD class UIInputVector;

class CWTransform : public ComponentWidget,
                    public IValueChangedListener
{
public:
    CWTransform(Transform *transform);
	virtual ~CWTransform();

private:
    Transform *p_relatedTransform = nullptr;

    UIInputVector *p_posIV   = nullptr;
    UIInputVector *p_rotIV   = nullptr;
    UIInputVector *p_scaleIV = nullptr;

    void OnValueChanged(Object *object) override;
};

NAMESPACE_BANG_EDITOR_END

#endif // CWTRANSFORM_H
