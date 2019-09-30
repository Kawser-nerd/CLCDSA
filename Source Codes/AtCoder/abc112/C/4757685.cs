using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    struct Pos
    {
        public int x;
        public int y;
        public int h;

        public Pos(int X,int Y,int H)
        {
            x = X;
            y = Y;
            h = H;
        }
    }
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        List<Pos> pos = new List<Pos> { Capacity = N };
        for(int i = 0; i < N; i++)
        {
            string[] p = Console.ReadLine().Split(' ');
            pos.Add(new Pos(int.Parse(p[0]), int.Parse(p[1]), int.Parse(p[2])));
        }
        pos.Sort((x, y) => y.h - x.h);
        bool cont = true;
        int Cx=0;
        int Cy=0;
        int H=0;
        for (int cx = 0; cx <= 100; cx++)
        {
            for (int cy = 0; cy <= 100; cy++)
            {
                cont = true;
                int hpredict = Math.Abs(pos[0].x - cx) + Math.Abs(pos[0].y - cy) + pos[0].h;
                for (int i = 1; i < N; i++)
                {
                    if (Math.Max(hpredict - Math.Abs(pos[i].x - cx) - Math.Abs(pos[i].y - cy), 0) != pos[i].h)
                    {
                        cont = false;
                        break;
                    }
                }
                if (cont)
                {
                    Cx = cx;
                    Cy = cy;
                    H = hpredict;
                    break;
                }
            }
            if (cont)
                break;
        }
        Console.WriteLine(Cx + " " + Cy + " " + H);
    }
}