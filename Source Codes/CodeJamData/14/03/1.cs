using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            //Console.Write("Case #{0}: ", i + 1);
            Console.WriteLine("Case #{0}:", i + 1);

            run();
        }
    }


    int H, W, B;
    char[,] board;
    void run()
    {
        H = cin.nextInt();
        W = cin.nextInt();
        B = cin.nextInt();

        board = new char[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                board[i, j] = '.';
            }
        }
        board[0, 0] = 'c';


        if (H * W - 1 == B)
        {
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    board[i, j] = '*';
                }
            }
            board[0, 0] = 'c';
            print();
            return;
        }
        int nokori = H * W - B;

        if (H == 1 || W == 1)
        {
            for (int i = H - 1; i >= 0; i--)
            {
                for (int j = W - 1; j >= 0; j--)
                {
                    if (B > 0)
                    {
                        board[i, j] = '*';
                        B--;
                    }
                }
            }
            print();
            return;
        }

        if (H == 2)
        {
            if (B % 2 == 1 || nokori == 2)
            {
                Console.WriteLine("Impossible");
                return;
            }
            for (int j = W - 1; j >= 0; j--)
            {
                for (int i = H - 1; i >= 0; i--)
                {
                    if (B > 0)
                    {
                        board[i, j] = '*';
                        B--;
                    }
                }
            }
            print();
            return;
        }

        if (W == 2)
        {
            if (B % 2 == 1 || nokori == 2)
            {
                Console.WriteLine("Impossible");
                return;
            }
            for (int i = H - 1; i >= 0; i--)
            {
                for (int j = W - 1; j >= 0; j--)
                {
                    if (B > 0)
                    {
                        board[i, j] = '*';
                        B--;
                    }
                }
            }
            print();
            return;
        }

        if (nokori == 0 || nokori == 2 || nokori == 3 || nokori == 5 || nokori == 7)
        {
            Console.WriteLine("Impossible");
            return;
        }

        nokori -= 4;
        for (int j = W - 1; j >= 0; j--)
        {
            for (int i = H - 1; i >= 0; i--)
            {
                board[i, j] = '*';
            }
        }
        board[0, 0] = 'c';
        board[0, 1] = board[1, 0] = board[1, 1] = '.';

        int h = 2; int w = 2;
        while (nokori >= 2 && (h < H || w < W))
        {
            if (nokori >= 2 && h < H)
            {
                nokori -= 2;
                board[h, 0] = board[h, 1] = '.';
                h++;
            }
            if (nokori >= 2 && w < W)
            {
                nokori -= 2;
                board[0, w] = board[1, w] = '.';
                w++;
            }
        }
        for (int i = 2; i < H; i++)
        {
            for (int j = 2; j < W; j++)
            {
                if (nokori > 0)
                {
                    board[i, j] = '.';
                    nokori--;
                }
            }
        }
        print();
    }



    void print()
    {
        int h = board.GetLength(0);
        int w = board.GetLength(1);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                Console.Write(board[i,j]);
            }
            Console.WriteLine();
        }
    }
}

class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}
