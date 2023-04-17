#pragma once

#include "imgui.h"
#include <stdio.h>
#include <string>

using namespace std;

namespace JCode
{

    bool whitesTurn = true;

    class ChessPiece
    {
        public:
            const char* piece;
            int team;

            ChessPiece(const char* pieceName, int teamColor)
            {
                piece = pieceName;
                team = teamColor;
            }

            
    };

    void RenderJoelUI()
    {


        static float f = 0.0f;
        static int counter = 0;
        static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

        ImGui::Begin("PianoMen");

        ImGui::End();


        // ME AND STEVE'S PROGRAM
        ImGui::Begin("Chess"); // Create a window called "Note Type Choices" and append into it.


        static const char* names[64] =
        {
            "Rook", "Knight", "Bishop", "Queen", "King", "Bishop", "Knight", "Rook",
            "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn",
            "", "", "", "", "", "", "", "",
            "", "", "", "", "", "", "", "",
            "", "", "", "", "", "", "", "",
            "", "", "", "", "", "", "", "",
            "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn",
            "Rook", "Knight", "Bishop", "Queen", "King", "Bishop", "Knight", "Rook",
        };

        static ChessPiece board[4] =
        {
           ChessPiece("Rook", 1), ChessPiece("Knight", 1), ChessPiece("Bishop", 0), ChessPiece("Queen", 0)
        };


        for (int n = 0; n < IM_ARRAYSIZE(board); n++)
        {
            ImGui::PushID(n);
            if ((n % 8) != 0)
                ImGui::SameLine();
            ImGui::Button(board[n].piece, ImVec2(60, 60));

            // Our buttons are both drag sources and drag targets here!
            if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None))
            {
                // Set payload to carry the index of our item (could be anything)
                ImGui::SetDragDropPayload("DND_DEMO_CELL", &n, sizeof(int));

                // Display preview (could be anything, e.g. when dragging an image we could decide to display
                // the filename and a small preview of the image, etc.)
                ImGui::Text("Move %s", board[n]);
                ImGui::EndDragDropSource();
            }
            if (ImGui::BeginDragDropTarget())
            {
                if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DND_DEMO_CELL"))
                {
                    IM_ASSERT(payload->DataSize == sizeof(int));
                    int payload_n = *(const int*)payload->Data;

                    if (board[payload_n].team == 0 && whitesTurn)
                    {
                        board[n] = board[payload_n];
                        board[payload_n].piece = "";
                        whitesTurn = false;
                    }
                    else if (board[payload_n].team == 1 && !whitesTurn)
                    {
                        board[n] = board[payload_n];
                        board[payload_n].piece = "";
                        whitesTurn = true;
                    }
                }
                ImGui::EndDragDropTarget();
            }
            ImGui::PopID();
        }
        ImGui::End();
    }
}

