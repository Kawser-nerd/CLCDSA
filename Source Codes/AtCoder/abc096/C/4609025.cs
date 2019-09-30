using System;
using System.Collections.Generic;
using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ');
            var H = int.Parse(input[0]);
            var W = int.Parse(input[1]);

            var maps = new List<List<char>>();

            for (int i = 0; i < H; i++)
            {
                var tmp = Console.ReadLine().ToCharArray().ToList();
                maps.Add(tmp);
            }

            for(int i=0;i<H;i++)
            {
                for(int k=0;k<W;k++)
                {
                    if(maps[i][k]=='#')
                    {
                        if(!((k > 0 && maps[i][k - 1] == '#') ||
                           (k < W - 1 && maps[i][k + 1] == '#') ||
                           (i > 0 && maps[i-1][k] == '#') ||
                           (i < H - 1 && maps[i+1][k] == '#')) )
                        {
                            Console.WriteLine("No");
                            return;
                        }
                    }
                }
            }

            Console.WriteLine("Yes");
        }
    }