using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace Round2A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("F:\\in.in");
            StreamWriter sw = new StreamWriter("F:\\out.out");
            sw.AutoFlush = true;
            int n = int.Parse(sr.ReadLine());
            Console.WriteLine(n);
            for (int i = 0; i < n; i++)
            {
                sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
                Console.WriteLine(i);
            }
            sw.Close();
            sr.Close();
            Console.WriteLine("Finished");
            Console.ReadLine();
        }


        static int C(int[] A, int x, int y)
        {
            bool b = false;
            for (int i = x; i < y; i++)
            {
                if (A[i] > 0)
                {
                    A[i]--;
                    b = true;
                }
            }
            if (!b)
                return 0;
            return 1 + C(A, x, (x + y) / 2) + C(A, (x + y) / 2, y);
        }


        static string Solution(StreamReader sr)
        {
            int P = int.Parse(sr.ReadLine());
            int N = 1 << P;
            int[] A = new int[N];
            string[] t = sr.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < P; i++)
            {
                sr.ReadLine();
            }
            for (int i = 0; i < N; i++)
            {
                A[i] =P- int.Parse(t[i]);
            }
            return C(A, 0, N).ToString();
        }
    }
}
