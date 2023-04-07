#pragma once

#include "imgui.h"

namespace SCode
{
    void RenderSteveUI()
    {
        ImGui::Begin("Buttons");
        ImGui::Button("Whole Note");
        ImGui::Button("Half Note");
        ImGui::Button("Quarter Note");
        ImGui::End();
    }
}
