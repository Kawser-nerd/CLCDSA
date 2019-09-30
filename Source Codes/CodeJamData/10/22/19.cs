using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Round1B
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

        static string Solution(StreamReader sr)
        {
            string[] h = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            int N = int.Parse(h[0]);
            int K = int.Parse(h[1]);
            int B = int.Parse(h[2]);
            int T = int.Parse(h[3]);
            int[] X = new int[N];
            int[] V = new int[N];
            h = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < N; i++)
            {
                X[i] = int.Parse(h[i]);
            }
            h = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < N; i++)
            {
                V[i] = int.Parse(h[i]);
            }
            bool[] D = new bool[N];
            for (int i = 0; i < N; i++)
            {
                D[i] = ((B - X[i]) <= (T * V[i]));
            }

            Array.Reverse(D);
            int r = 0;
            int bad = 0;
            int good = 0;
            for (int i = 0; i < N; i++)
            {
                if (D[i])
                {
                    good++;
                    r += bad;
                    if (good == K)
                        break;
                }
                else
                    bad++;
            }
            if (good != K)
                return "IMPOSSIBLE";
            return r.ToString();

        }
    }
}
