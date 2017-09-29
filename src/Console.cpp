#include "BangEditor/Console.h"

#include "Bang/UILayoutElement.h"

USING_NAMESPACE_BANG
USING_NAMESPACE_BANG_EDITOR

Console::Console() : EditorUITab("Console")
{
    UILayoutElement *le = GetComponent<UILayoutElement>();
    le->SetMinSize( Vector2i(100, 100) );
    le->SetPreferredWidth(250);
    le->SetFlexibleWidth(9999);
}

Console::~Console()
{

}
