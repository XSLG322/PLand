#pragma once
#include "IComponent.h"
#include "ImGuiColorTextEdit/TextEditor.h"
#include <string>


namespace devtool {


class CodeEditor : public IWindow {
protected:
    TextEditor editor_;
    int        windowId_;

public:
    explicit CodeEditor(std::string const& code);

    virtual void renderMenuElement();

    virtual void renderMenuBar();

    virtual void render() override;
};


} // namespace devtool
