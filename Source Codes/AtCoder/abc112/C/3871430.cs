using System;
using System.Linq;
using System.Collections.Generic;

namespace _0030
{

    struct ID
    {
        internal int X;
        internal int Y;
        internal long Hight;
    }
    

    class Program
    {
        

        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());

            string[] str;
            int[] x = new int[n];
            int[] y = new int[n];
            long[] h = new long[n];
            int xx = 0;
            int yy = 0;
            long hh = 0;
            for (int i = 0; i < n; i++)
            {
                str = Console.ReadLine().Split(' ');
                x[i] = int.Parse(str[0]);
                y[i] = int.Parse(str[1]);
                h[i] = long.Parse(str[2]);
                if(h[i] >= 1)
                {
                    xx = x[i];
                    yy = y[i];
                    hh = h[i];
                }
            }

            //Console.WriteLine($"{xx} {yy} {hh}");

            long H;                      
            bool find = true;
            long HH = 0;

            var list = new List<ID>();

            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {                    
                    find = true;
                    H = hh + Math.Abs(xx - i) + Math.Abs(yy - j);
                    H = Math.Max(H, 0);
                    for (int k = 0; k < n; k++)
                    {
                        HH = H - Math.Abs(x[k] - i) - Math.Abs(y[k] - j);
                        HH = Math.Max(HH, 0);
                        if(HH != h[k])
                        {
                            find = false;
                        }                       
                    }
                    if (find)
                    {
                        var id = new ID
                        {
                            X = i,
                            Y = j,
                            Hight = H
                        };
                        list.Add(id);
                    }

                }
            }

            if(list.Count == 1)
            {
                Console.WriteLine($"{list[0].X} {list[0].Y} {list[0].Hight}");
            }



        }
    }
}