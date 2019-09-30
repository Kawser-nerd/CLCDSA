using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C084
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int[]> list = new List<int[]>();
            for (int i = 0; i < N-1; i++)
            {
                int[] a0 = Console.ReadLine().Split(' ').Select(k => int.Parse(k)).ToArray();
                list.Add(a0);
            }

            List<int> xlist = new List<int>();
            for (int i = 0; i < N; i++)
            {
                int time = 0;
                int current = i;
                while (current < N - 1)
                {
                    int departTime = Math.Max(list[current][1], time);
                    int hasuu = departTime % list[current][2];
                    if (hasuu != 0)
                    {
                        departTime += list[current][2] - hasuu;
                    }

                    time = departTime + list[current][0];
                    current++;
                }
                xlist.Add(time);
            }


            foreach(int v in xlist)
            {
                Console.WriteLine(v);
            }
        }

    }
}