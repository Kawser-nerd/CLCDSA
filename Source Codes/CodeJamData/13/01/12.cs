using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		// Tic-Tac-Toe-Tomek is a game played on a 4 x 4 square board.
		// The board starts empty, except that a single 'T' symbol may appear in one of the 16 squares.
		// There are two players: X and O. They take turns to make moves, with X starting.
		// In each move a player puts her symbol in one of the empty squares. Player X's symbol is 'X', and player O's symbol is 'O'.

		// After a player's move, if there is a row, column or a diagonal containing 4 of that player's symbols,
		// or containing 3 of her symbols and the 'T' symbol, she wins and the game ends.
		// Otherwise the game continues with the other player's move.
		// If all of the fields are filled with symbols and nobody won, the game ends in a draw.
		// See the sample input for examples of various winning positions.

		// Given an 4 x 4 board description containing 'X', 'O', 'T' and '.' characters (where '.' represents an empty square),
		// describing the current state of a game, determine the status of the Tic-Tac-Toe-Tomek game going on.
		// The statuses to choose from are:

		// "X won" (the game is over, and X won)
		// "O won" (the game is over, and O won)
		// "Draw" (the game is over, and it ended in a draw)
		// "Game has not completed" (the game is not over yet)
		// Even if the outcome of the game is inevitable -- for example, if there are empty cells, but neither X nor O can win 
		// -- if there are empty cells, and the game is not over, you should output "Game has not completed".

		// Each test case consists of 4 lines with 4 characters each, with each character
		// being 'X', 'O', '.' or 'T' (quotes for clarity only).
		// Each test case is followed by an empty line.
		// The game board provided will represent a valid state that was reached through play of the game Tic-Tac-Toe-Tomek
		// as described above.

		char[,] Board = new char[4, 4];

		public TestCase(TextReader input)
		{
			Enumerable.Range(0, 4).ForEach(i => input.ReadLine().ForEach((ch, j) => Board[i, j] = ch));
			input.ReadLine();
		}

		public string GetResult()
		{
			// Return one of the statuses given above.
			// Make sure to get the statuses exactly right.
			// When you run your code on the sample input, it should create the sample output exactly, including the "Case #1: ", the capital letter "O" rather than the number "0", and so on.
			if (IsWinner('X'))
				return "X won";
			if (IsWinner('O'))
				return "O won";
			if (IsFull())
				return "Draw";
			return "Game has not completed";
		}

		private bool IsWinner(char p)
		{
			return Board.GetRows().Concat(Board.GetColumns()).Concat(Board.GetDiagonals())
				.Any(v => v.All(ch => ch == p || ch == 'T'));
		}

		private bool IsFull()
		{
			return Board.GetElements().All(ch => ch != '.');
		}
	}
}