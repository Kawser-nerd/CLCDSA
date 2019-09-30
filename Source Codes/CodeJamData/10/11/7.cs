using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using bigint = System.Numerics.BigInteger;

class ProblemA
{
    static StreamReader input;
    static StreamWriter output;

    public static void Main()
    {
        string testSet = "A-large";
        using (input = new StreamReader(testSet + ".in"))
        {
            using (output = new StreamWriter(testSet + ".out"))
            {
                run();
            }
        }
    }

    private static void run()
    {
        int T = readInt();
        for (int i = 1; i <= T; i++)
        {
            run(i);
        }
    }

    private static int N = 0, K = 0;
    private static void run(int caseNum)
    {
        int[] ii = readInts();
        N = ii[0];
        K = ii[1];
        char[][] board = new char[N][];
        for (int i = 0; i < N; i++)
        {
            board[i] = input.ReadLine().ToCharArray();
        }
        print(board);
        board = rotate(board);
        print(board);
        board = gravity(board);
        print(board);
        output.WriteLine("Case #{0}: {1}", caseNum, winner(board));
    }

    private static void print(char[][] board)
    {
        for (int i = 0; i < N; i++)
            Console.WriteLine(new string(board[i]));
        Console.WriteLine();
    }

    private static string winner(char[][] board)
    {
        bool rw = false, bw = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!rw && board[i][j] == 'R' && win(board, 'R', j, i)) rw = true;
                else if (!bw && board[i][j] == 'B' && win(board, 'B', j, i)) bw = true;
        if (rw && bw) return "Both";
        else if (rw) return "Red";
        else if (bw) return "Blue";
        else return "Neither";
    }

    private static bool win(char[][] board, char c, int x, int y)
    {
        int[] dx = { 0, 1, -1, 1 };
        int[] dy = { 1, 0, 1, 1 };
        for (int k = 0; k < 4; k++)
        {
            bool ok = true;
            for (int i = 1; ok && i < K; i++)
            {
                if (x + i * dx[k] < 0 || x + i * dx[k] >= N) ok = false;
                else if (y + i * dy[k] >= N) ok = false;
                else if (board[y + i * dy[k]][x + i * dx[k]] != c) ok = false;
            }
            if (ok) return true;
        }
        return false;
    }

    private static char[][] gravity(char[][] board)
    {
        for (int i = 0; i < N; i++)
        {
            int p = N - 1;
            for (int j = N - 1; j >= 0; j--)
            {
                if (board[j][i] != '.' && j != p)
                {
                    board[p][i] = board[j][i];
                    board[j][i] = '.';
                    p--;
                }
                else if (board[j][i] != '.')
                {
                    p--;
                }
            }
        }
        return board;
    }

    private static char[][] rotate(char[][] board)
    {
        char[][] rot = new char[N][];
        for (int i = 0; i < N; i++)
        {
            rot[i] = new char[N];
            for (int j = 0; j < N; j++)
                rot[i][j] = board[N - j - 1][i];
        }
        return rot;
    }

    private static int readInt()
    {
        string line = input.ReadLine();
        return int.Parse(line);
    }

    private static int[] readInts()
    {
        string line = input.ReadLine();
        return Array.ConvertAll(line.Split(), int.Parse);
    }
}
