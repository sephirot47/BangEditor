#ifndef CIWUIIMAGERENDERER_H
#define CIWUIIMAGERENDERER_H

#include "Bang/IValueChangedListener.h"

#include "BangEditor/ComponentInspectorWidget.h"

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

FORWARD class UIInputFile;
FORWARD class UIInputColor;

class CIWUIImageRenderer : public ComponentInspectorWidget
{
    GAMEOBJECT_EDITOR(CIWUIImageRenderer);

public:
    // InspectorWidget
    virtual void InitInnerWidgets() override;
    virtual void UpdateFromReference() override;

protected:
    UIImageRenderer *GetUIImageRenderer() const;

    // IValueChangedListener
    void OnValueChanged(Object *object) override;

private:
    UIInputFile *p_imageInput = nullptr;
    UIInputColor *p_tintInput = nullptr;

	CIWUIImageRenderer();
	virtual ~CIWUIImageRenderer();
};

NAMESPACE_BANG_EDITOR_END

#endif // CIWUIIMAGERENDERER_H

