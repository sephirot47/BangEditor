#ifndef CIWAUDIOSOURCE_H
#define CIWAUDIOSOURCE_H

#include "Bang/Bang.h"

#include "BangEditor/ComponentInspectorWidget.h"

FORWARD NAMESPACE_BANG_BEGIN
FORWARD class UIButton;
FORWARD class UISlider;
FORWARD class AudioSource;
FORWARD class UIInputNumber;
FORWARD NAMESPACE_BANG_END

USING_NAMESPACE_BANG
NAMESPACE_BANG_EDITOR_BEGIN

FORWARD class UIInputFile;

class CIWAudioSource : public ComponentInspectorWidget
{
    GAMEOBJECT_EDITOR(CIWAudioSource);

public:
    // InspectorWidget
    virtual void InitInnerWidgets() override;

    // ComponentInspectorWidget
    virtual void UpdateFromReference() override;

private:
    UIInputNumber *p_rangeInput          = nullptr;
    UISlider      *p_pitchSlider         = nullptr;
    UISlider      *p_volumeSlider        = nullptr;
    UIButton      *p_playStopButton      = nullptr;
    UICheckBox    *p_loopingCheckbox     = nullptr;
    UICheckBox    *p_playOnStartCheckbox = nullptr;
    UIInputFile   *p_audioClipFileInput  = nullptr;

    void OnPlayClicked();

    // IValueChangedListener
    virtual void OnValueChanged(Object *object) override;

    AudioSource *GetAudioSource() const;

    CIWAudioSource() = default;
    virtual ~CIWAudioSource() = default;
};

NAMESPACE_BANG_EDITOR_END

#endif // CIWAUDIOSOURCE_H

