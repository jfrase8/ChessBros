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
            int movesMade = 0;

            // Constructor
            ChessPiece(const char* pieceName, int teamColor)
            {
                piece = pieceName;
                team = teamColor;

            }

            // Gets rid of piece (Turns it into empty square)
            void PieceTaken()
            {
                piece = "";
                team = -1;
            }

            // King is in check
            void Checked()
            {
                if (team == 0) whiteInCheck = true;
                else blackInCheck = true;
            }

            // Finds all possible moves of this specific piece, and returns true if move is valid
            bool FindValidMoves(int payload_n, int n, ChessPiece board[])
            {

                // Find row and column of old space
                int oldRow = payload_n / 8;
                cout << "Old Row: " << oldRow << endl;
                int oldColumn = payload_n % 8;
                cout << "Old Column: " << oldColumn << endl;

                // Find row and column of new space
                int newRow = n / 8;
                cout << "New Row: " << newRow << endl;
                int newColumn = n % 8;
                cout << "New Column: " << newColumn << endl;

                // Find valid moving squares //

                #pragma region Knight
                if (strcmp(piece, "Q") == 0 || strcmp(piece, "W") == 0)
                {
                    // Valid knight moves
                    int rows[] = { 2,2,-2,-2,1,1,-1,-1 };
                    int columns[] = { -1,1,1,-1,2,-2,2,-2 };

                    // Creates array of all possible moves
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        rows[i] += oldRow;
                        cout << "Valid Row: " << rows[i];
                        

                        columns[i] += oldColumn;
                        cout << " Valid Column: " << columns[i] << endl;
                    }

                    // Checks if move is equal to a valid move
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        if (newRow == rows[i] && newColumn == columns[i])
                        {
                            cout << "Returned True";
                            return true;
                        }
                        
                    }
                    return false;
                }
                #pragma endregion Moves

                #pragma region Bishop
                if (strcmp(piece, "R") == 0 || strcmp(piece, "Z") == 0)
                {
                    // Valid bishop moves
                    int rows[28] =    { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                        1, 2, 3, 4, 5, 6, 7,-1,-2,-3,-4,-5,-6,-7 };

                    int columns[28] = { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                       -1,-2,-3,-4,-5,-6,-7, 1, 2, 3, 4, 5, 6, 7 };

                    // Creates array of all possible moves
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        rows[i] += oldRow;
                        cout << "Valid Row: " << rows[i];


                        columns[i] += oldColumn;
                        cout << " Valid Column: " << columns[i] << endl;
                    }

                    // Checks if move is equal to a valid move
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        if (newRow == rows[i] && newColumn == columns[i])
                        {
                            cout << "Returned True" << endl;
                            cout << endl;
                            return true;
                        }

                    }
                    return false;
                }
                #pragma endregion Moves

                #pragma region Rook
                if (strcmp(piece, "P") == 0 || strcmp(piece, "V") == 0)
                {
                    // Valid rook moves
                    int rows[28] =    { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                        0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0 };

                    int columns[28] = { 0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,
                                        1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7 };

                    // Creates array of all possible moves
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        rows[i] += oldRow;
                        cout << "Valid Row: " << rows[i];


                        columns[i] += oldColumn;
                        cout << " Valid Column: " << columns[i] << endl;
                    }

                    // Checks if move is equal to a valid move
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        if (newRow == rows[i] && newColumn == columns[i])
                        {
                            cout << "Returned True" << endl;
                            cout << endl;
                            return true;
                        }

                    }
                    return false;
                }
                #pragma endregion Moves

                #pragma region Queen
                if (strcmp(piece, "T") == 0 || strcmp(piece, "Y") == 0)
                {
                    // Valid queen moves
                    int rows[56] =    { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                            0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,
                                        1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                            1, 2, 3, 4, 5, 6, 7,-1,-2,-3,-4,-5,-6,-7 };

                    int columns[56] = { 0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0,
                                            1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                        1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7,
                                           -1,-2,-3,-4,-5,-6,-7, 1, 2, 3, 4, 5, 6, 7 };

                    // Creates array of all possible moves
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        rows[i] += oldRow;
                        cout << "Valid Row: " << rows[i];


                        columns[i] += oldColumn;
                        cout << " Valid Column: " << columns[i] << endl;
                    }

                    // Checks if move is equal to a valid move
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        if (newRow == rows[i] && newColumn == columns[i])
                        {
                            cout << "Returned True" << endl;
                            cout << endl;
                            return true;
                        }

                    }
                    return false;
                }
                #pragma endregion Moves

                #pragma region King
                if (strcmp(piece, "S") == 0 || strcmp(piece, "X") == 0)
                {
                    // Valid king moves
                    int rows[] =    { 1,1, 1,0,-1,-1, 0,-1};
                    int columns[] = { 0,1,-1,1,-1, 1,-1, 0 };

                    // Creates array of all possible moves
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        rows[i] += oldRow;
                        cout << "Valid Row: " << rows[i];


                        columns[i] += oldColumn;
                        cout << " Valid Column: " << columns[i] << endl;
                    }

                    // Checks if move is equal to a valid move
                    for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                    {
                        if (newRow == rows[i] && newColumn == columns[i])
                        {
                            cout << "Returned True";
                            return true;
                        }

                    }
                    return false;
                }
                #pragma endregion Moves

                #pragma region Pawn

                    #pragma region White Pawn
                    
                if (strcmp(piece, "O") == 0)
                {
                    // Check if pawn has not moved yet
                    if (movesMade == 0)
                    {
                        // Valid pawn moves
                        int rows[] =    { 1,2 };
                        int columns[] = { 0,0 };

                        // Creates array of all possible moves
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            rows[i] += oldRow;
                            cout << "Valid Row: " << rows[i];


                            columns[i] += oldColumn;
                            cout << " Valid Column: " << columns[i] << endl;
                        }

                        // Checks if move is equal to a valid move
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            if (newRow == rows[i] && newColumn == columns[i])
                            {
                                cout << "Returned True";
                                return true;
                            }

                        }
                    }
                    // If pawn has already moved, it can only move up
                    else
                    {
                        // Valid pawn moves
                        int rows[] =    { 1 };
                        int columns[] = { 0 };

                        // Creates array of all possible moves
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            rows[i] += oldRow;
                            cout << "Valid Row: " << rows[i];


                            columns[i] += oldColumn;
                            cout << " Valid Column: " << columns[i] << endl;
                        }

                        // Checks if move is equal to a valid move
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            if (newRow == rows[i] && newColumn == columns[i])
                            {
                                cout << "Returned True";
                                return true;
                            }

                        }
                    }
                        #pragma region White Pawn

                    // If pawn is able to move diagnally right
                    if (payload_n + 9 <= 63)
                    {
                        // Check if there is a piece diagnally right
                        if (board[payload_n + 9].team == 1)
                        {
                            oldRow += 1;
                            oldColumn += 1;

                            if (oldColumn == newColumn && oldRow == newRow)
                            {
                                return true;
                            }
                        }
                    }

                    // If pawn is able to move diagnally left
                    if (payload_n + 7 <= 63)
                    {
                        // Check if there is a piece diagnally left
                        if (board[payload_n + 7].team == 1)
                        {

                            oldRow += 1;
                            oldColumn -= 1;

                            if (oldColumn == newColumn && oldRow == newRow)
                            {
                                return true;
                            }
                        }
                    }
                    return false;
                        #pragma endregion Attacks

                }
                    #pragma endregion Moves & Attacks

                    #pragma region Black Pawn

                if (strcmp(piece, "U") == 0)
                {
                    // Check if pawn has not moved yet
                    if (movesMade == 0)
                    {
                        // Valid pawn moves
                        int rows[] =    { -1,-2 };
                        int columns[] = { 0,0 };

                        // Creates array of all possible moves
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            rows[i] += oldRow;
                            cout << "Valid Row: " << rows[i];


                            columns[i] += oldColumn;
                            cout << " Valid Column: " << columns[i] << endl;
                        }

                        // Checks if move is equal to a valid move
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            if (newRow == rows[i] && newColumn == columns[i])
                            {
                                cout << "Returned True";
                                return true;
                            }

                        }
                    }
                    // If pawn has already moved, it can only move up
                    else
                    {
                        // Valid pawn moves
                        int rows[] =    { -1 };
                        int columns[] = { 0 };

                        // Creates array of all possible moves
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            rows[i] += oldRow;
                            cout << "Valid Row: " << rows[i];


                            columns[i] += oldColumn;
                            cout << " Valid Column: " << columns[i] << endl;
                        }

                        // Checks if move is equal to a valid move
                        for (int i = 0; i < sizeof(rows) / sizeof(rows[0]); i++)
                        {
                            if (newRow == rows[i] && newColumn == columns[i])
                            {
                                cout << "Returned True";
                                return true;
                            }
                        }
                    }
                        #pragma region Black Pawn

                    // If pawn is able to move diagnally left
                    if (payload_n - 9 >= 0)
                    {
                        // Check if there is a piece diagnally left
                        if (board[payload_n - 9].team == 0)
                        {
                            oldRow -= 1;
                            oldColumn -= 1;

                            if (oldColumn == newColumn && oldRow == newRow)
                            {
                                return true;
                            }
                        }
                    }

                    // If pawn is able to move diagnally right
                    if (payload_n - 7 >= 0)
                    {
                        // Check if there is a piece diagnally right
                        if (board[payload_n - 7].team == 0)
                        {

                            oldRow -= 1;
                            oldColumn += 1;

                            if (oldColumn == newColumn && oldRow == newRow)
                            {
                                return true;
                            }
                        }
                    }
                    return false;
                        #pragma endregion Attacks

                    #pragma endregion Moves & Attacks
                }
                #pragma endregion Moves

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
                                if (board[payload_n].FindValidMoves(payload_n, n, board))
                                {
                                    // Take piece
                                    board[n] = board[payload_n];
                                    board[payload_n].PieceTaken();

                                    // Switch turns
                                    whitesTurn = false;

                                    // Increase this piece's moves
                                    board[n].movesMade++;
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
                                if (board[payload_n].FindValidMoves(payload_n, n, board))
                                {
                                    // Take piece
                                    board[n] = board[payload_n];
                                    board[payload_n].PieceTaken();

                                    // Switch Turns
                                    whitesTurn = true;

                                    // Increase this piece's moves
                                    board[n].movesMade++;
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

