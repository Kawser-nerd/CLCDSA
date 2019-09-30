using System;

namespace ABC004 {
  class ProblemB {
    static void Main(string[] args) {
      string[][] board = {
        new string[4], new string[4], new string[4], new string[4]
      }, copy = {
        new string[4], new string[4], new string[4], new string[4]
      };
      for (int i = 0; i < 4; i++) {
        board[i] = Console.ReadLine().Split(' ');
      }

      for (int i = 0; i < board.Length; i++) {
        for (int j = 0; j < board[i].Length; j++) {
          copy[i][j] = board[board.Length - i - 1][board[i].Length - j - 1];
        }
      }

      for (int i = 0; i < copy.Length; i++) {
        for (int j = 0; j < copy[i].Length; j++) {
          Console.Write(copy[i][j] + " ");
        }
        Console.WriteLine();
      }
    }
  }
}