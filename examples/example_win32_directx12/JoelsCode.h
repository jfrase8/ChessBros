#pragma once

#include "imgui.h"
#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;

namespace JCode
{

    bool whitesTurn = true;
    bool whiteInCheck = false;
    bool blackInCheck = false;


    class ChessPiece
    {
        public:
            const char* piece;
            int team; // 0 = White, 1 = Black, -1 = Empty
            bool inCheck = false;

            ChessPiece(const char* pieceName, int teamColor)
            {
                piece = pieceName;
                team = teamColor;

            }

            void PieceTaken()
            {
                piece = "";
                team = -1;
            }

            void Checked()
            {
                if (team == 0) whiteInCheck = true;
                else blackInCheck = true;
            }

            bool FindValidMoves(int payload_n, int n)
            {

                cout << payload_n;
                cout << n;


                cout << "Function Called";

                // Find row and column of old space
                int oldRow = payload_n / 8;
                int oldColumn = payload_n % 8;

                // Find row and column of new space
                int newRow = n / 8;
                int newColumn = n % 8;


                // Find valid moving squares //
                
                //Knight
                /*if (strcmp(piece, "Q") == 0 || strcmp(piece, "W") == 0)
                {
                    int rows[] = { 2,2,-2,-2,1,1,-1,-1 };
                    int columns[] = { -1,1,1,-1,2,-2,2,-2 };

                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        rows[i] += oldRow;
                        cout << "Valid Row: " + rows[i];
                        

                        columns[i] += oldColumn;
                        cout << " Valid Column: " + columns[i] << endl;
                    }

                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        if (newRow == rows[i] && newColumn == columns[i])
                        {
                            return true;
                        }
                        return false;
                    }
                }*/

                return true;
            }

    };

    class ChessBoard
    {
        public:

            // Default Constructor
            ChessBoard() = default;
            ChessBoard(int arr[]);
            ChessPiece board[64] = {

                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1),
                ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1), ChessPiece("", 1)
            };

            // Constructor
            ChessBoard(ChessPiece guiBoard[])
            {

                for (int i = 0; i < 8; i++)
                {
                    board[i] = guiBoard[i];
                }
            }
    };

    void RenderJoelUI()
    {


        static float f = 0.0f;
        static int counter = 0;
        static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;

        //ImGui::Begin("PianoMen");

        //ImGui::End();


        // ME AND STEVE'S PROGRAM
        ImGui::Begin("Chess"); // Create a window called "" and append into it.

        static ChessPiece board[] =
        {

            // Key //

            // White:
            // Pawn - O, Rook - P, Knight - Q, Bishop - R, King - S, Queen - T

            // Black:
            // Pawn - U, Rook - V, Knight - W, Bishop - Z, King - X, Queen - Y


           ChessPiece("P", 0), ChessPiece("Q", 0), ChessPiece("R", 0), ChessPiece("T", 0), ChessPiece("S", 0), ChessPiece("R", 0), ChessPiece("Q", 0), ChessPiece("P", 0),
           ChessPiece("O", 0), ChessPiece("O", 0), ChessPiece("O", 0), ChessPiece("O", 0), ChessPiece("O", 0), ChessPiece("O", 0), ChessPiece("O", 0), ChessPiece("O", 0),
           ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1),
           ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1),
           ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1),
           ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1), ChessPiece("", -1),
           ChessPiece("U", 1), ChessPiece("U", 1), ChessPiece("U", 1), ChessPiece("U", 1), ChessPiece("U", 1), ChessPiece("U", 1), ChessPiece("U", 1), ChessPiece("U", 1),
           ChessPiece("V", 1), ChessPiece("W", 1), ChessPiece("Z", 1), ChessPiece("Y", 1), ChessPiece("X", 1), ChessPiece("Z", 1), ChessPiece("W", 1), ChessPiece("V", 1)
        };

        // Copy of chess board
        ChessBoard logicBoard = ChessBoard(board);


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
                    // payload_n is a reference to the original space that the dragged piece was in
                    IM_ASSERT(payload->DataSize == sizeof(int));
                    int payload_n = *(const int*)payload->Data;

                    // If statement makes sure empty spaces cannot be dragged
                    if (board[payload_n].team != -1)
                    {

                        //// Taking pieces ////

                        // if statement arguments:
                        // -Team is White
                        // -It is White's turn
                        // -Piece being taken is not White
                        // -White is not in check

                        if (board[payload_n].team == 0 && whitesTurn && board[n].team != 0)
                        {
                            // Check if white is in check
                            if (!whiteInCheck)
                            {
                                // Check if piece being dragged is king
                                //if ()

                                // Check for valid move
                                if (board[payload_n].FindValidMoves(payload_n, n))
                                {
                                    // Take piece
                                    board[n] = board[payload_n];
                                    board[payload_n].PieceTaken();
                                    whitesTurn = false;
                                }
                            }
                        }

                        // Blacks Turn
                        else if (board[payload_n].team == 1 && !whitesTurn)
                        {
                            // If statement makes sure White doesn't take its own piece
                            if (board[n].team != 1)
                            {

                                // Check for valid move
                                if (board[payload_n].FindValidMoves(payload_n, n))
                                {
                                    // Take piece
                                    board[n] = board[payload_n];
                                    board[payload_n].PieceTaken();
                                    whitesTurn = true;
                                }
                            }
                        }
                    }
                }
                ImGui::EndDragDropTarget();
            }
            ImGui::PopID();
        }
        ImGui::End();
    }
}

