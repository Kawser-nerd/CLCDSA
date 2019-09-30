using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Collections;

public class Hello
{

    static char[][] board;

    public static void Main(string[] args)
    {

        board = new char[8][];

        for(int i = 0; i < 8; i++)
        {
            board[i] = Console.ReadLine().ToArray();
        }

        if(DFS(0,8))
        {
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    Console.Write(board[i][j]);
                }
                Console.WriteLine();
            }
        }
        else
        {
            Console.WriteLine("No Answer");
        }

    }

    public static bool withinRange(int x, int y)
    {
        return x >= 0 && y >= 0 && x < 8 && y < 8;
    }

    public static bool isPuttable(int x, int y)
    {
        for(int vx = -1; vx <= 1; vx++)
            for(int vy = -1; vy <= 1; vy++)
            {
                if (vy == 0 && vx == 0) continue;
                int tx = x;
                int ty = y;
                while(true)
                {
                    tx += vx; ty += vy;
                    if (!withinRange(tx, ty)) break;
                    if (board[ty][tx] == 'Q') return false;
                }
                
            }
        return true;
    }
    // x vertical line 0 <= x < 8
    // y horizontal line 0 <= y < 8
    public static bool DFS (int current, int remain)
    {

        if (remain == 0) return true;
        if (current == 64) return false;

        int x = current % 8;
        int y = current / 8;

        if(board[y][x] == 'Q')
        {
            if (isPuttable(x, y))
                if (DFS(current + 1, remain - 1)) return true;
        }
        else
        {
            if (isPuttable(x, y))
            {
                board[y][x] = 'Q';
                if (DFS(current + 1, remain - 1)) return true;
                board[y][x] = '.';
            }

            if (DFS(current + 1, remain)) return true;
        }

        return false;
    }
}