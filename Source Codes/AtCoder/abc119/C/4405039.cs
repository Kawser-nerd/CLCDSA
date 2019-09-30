using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC119C
{
    class Program
    {
        static int N;
        static int A;
        static int B;
        static int C;
        static int[] data;
        static int INF = (int)Math.Pow(10, 9);
        static int[] bmp;

        static int Solve(int current, int a, int b, int c)
        {

            if (current == N)
            {
                List<int> tmp = new List<int>();

                tmp.Add(a);
                tmp.Add(b);
                tmp.Add(c);

                tmp.Sort();

                if (tmp.First() > 0)
                {
                    return Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c) - 30;
                }
                else
                {
                    return INF;
                }

            }

            List<int> list = new List<int>();

            list.Add(Solve(current + 1, a, b, c));
            list.Add(Solve(current + 1, a + bmp[current], b, c) + 10);
            list.Add(Solve(current + 1, a, b + bmp[current], c) + 10);
            list.Add(Solve(current + 1, a, b, c + bmp[current]) + 10);

            list.Sort();

            return list.First();

        }

        static void Main(string[] args)
        {
            string[] temp = System.Console.ReadLine().Split(' ');
            N = int.Parse(temp[0]);
            A = int.Parse(temp[1]);
            B = int.Parse(temp[2]);
            C = int.Parse(temp[3]);
            bmp = new int[N];
            for (int i = 0; i < N; i++)
            {
                bmp[i]=(int.Parse(System.Console.ReadLine()));
            }



            Console.WriteLine(Solve(0, 0, 0, 0));
        }
    }
}