using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        static string[] a = new string[4];

        static bool All(int y, int x, int dy, int dx, char c)
        {
            for (int i = 0; i < 4; i++)
            {
                if (a[y][x] != c && a[y][x] != 'T')
                    return false;
                y += dy; x += dx;
            }
            return true;
        }

        static bool Winning(char c)
        {
            for (int i = 0; i < 4; i++)
                if(All(i, 0, 0, 1, c))
                    return true;

            for (int i = 0; i < 4; i++)
                if (All(0, i, 1, 0, c))
                    return true;

            if(All(0, 0, 1, 1, c))
                return true;

            if (All(3, 0, -1, 1, c))
                return true;

            return false;
        }

        static string Solve()
        {
            if(Winning('X'))
                return "X won";

            if(Winning('O'))
                return "O won";

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if(a[i][j] == '.')
                        return "Game has not completed";

            return "Draw";
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                for (int i = 0; i < 4; i++)
                    a[i] = Console.ReadLine();
                Console.ReadLine();

                Console.WriteLine("Case #{0}: {1}", t, Solve());
            }
        }
    }
}
