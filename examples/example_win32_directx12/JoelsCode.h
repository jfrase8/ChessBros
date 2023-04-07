#pragma once

#include "imgui.h"

namespace JCode
{
    void RenderJoelUI()
    {
        static float f = 0.0f;
        static int counter = 0;
        static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

        ImGui::Begin("PianoMen");

        ImGui::End();


        // ME AND STEVE'S PROGRAM
        ImGui::Begin("Note Type Choices");                      // Create a window called "Note Type Choices" and append into it.

        ImGui::Text("These are different types of notes");      // Display some text (you can use a format strings too)

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::End();
    }
}

