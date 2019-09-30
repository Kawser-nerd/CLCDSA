using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D109
    {
        static void Main(string[] args)
        {
            int[] h = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
            int H = h[0], W = h[1];

            List<int[]> list = new List<int[]>();

            int[] col = new int[H];
            for (int i = 0; i < H; i++)
            {
                int[] a = Console.ReadLine().Split(' ').Select(z => int.Parse(z)).ToArray();
                int[] b = (int[])a.Clone();
                for (int j = 0; j < W - 1; j++)
                {
                    if (b[j] % 2 == 1)
                    {
                        int[] r = { i + 1, j + 1, i + 1, j + 2 };
                        list.Add(r);
                        b[j]--; b[j + 1]++;
                    }
                }
                col[i] = b[W - 1];
            }

            for(int i = 0; i < H - 1; i++)
            {
                if(col[i] % 2 == 1)
                {
                    int[] r = { i+1, W, i + 2, W };
                    list.Add(r);
                    col[i]--; col[i + 1]++;
                }
            }

            Console.WriteLine(list.Count);
            foreach(int[] r in list)
            {
                Console.WriteLine(string.Join(" ", r));
            }

        }

    }
}