using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

public class Hello
{

    public static void Main()
    {
        char[][] board = new char[8][];

        for(int i = 0; i < 8; i++)
        {
            board[i] = Console.ReadLine().ToCharArray();
        }

        if(DFS(0, 8, board))
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

        


        Console.ReadKey();
    }

    public static bool DFS(int current, int remains, char[][] board)
    {
        if (remains == 0) return true; // ????????????????true 
        if (current == 64) return false;  // ??????????????????????????????? false

        // ?????? current ?????????
        int y = current / 8;
        int x = current % 8;

        if(board[y][x] == 'Q') // ???????????Q??????????
        {
            if(isPuttable(y, x, board)) // ????????Q????????
            {
                // ?????????????????????
                if (DFS(current + 1, remains - 1, board)) return true;
            }
        }
        else
        {
            // ??????Q??????
            if(isPuttable(y, x, board))
            {
                // ??????Q???????????????
                board[y][x] = 'Q';
                if (DFS(current + 1, remains - 1, board)) return true;
                board[y][x] = '.';
            }
            if (DFS(current + 1, remains, board)) return true;
        }
        return false;
    }

    public static bool isInside(int y, int x)
    {
        return x >= 0 && y >= 0 && x < 8 && y < 8;
    }

    public static bool isPuttable(int y, int x, char[][] board)
    {
        /*
         * ??????????
         * vy ? -1 vx ? -1 ??????? vy ? 0 vx ? -1 ?????
         * vy , vx ??? 0??????????????????
         * vy ??0 vx ? 1 ????????
         * ???????????????????????????????
         * ??????????????????????y? -1 or 8 x ? -1 or 8??
         */
        for (int vy = -1; vy <= 1; vy++)
        {
            for(int vx = -1; vx <= 1; vx++)
            {
                if (vy == 0 && vx == 0) continue;
                int ty = y; int tx = x;
                while(true)
                {
                    ty += vy; tx += vx;
                    if (!isInside(ty, tx)) break;
                    if (board[ty][tx] == 'Q') return false;
                }
            }
        }
        return true;
    }
}