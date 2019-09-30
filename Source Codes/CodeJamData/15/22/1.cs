using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem1B
{
    class Program
    {
        static int[] countN = new int[5];
        
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"G:\B-large.in");
            List<string> output = new List<string>();
            int N = int.Parse(input[0]);
            for (int i = 0; i < N; i++)
            {
                string[] s = input[i + 1].Split(' ');
                int r = int.Parse(s[0]);
                int c = int.Parse(s[1]);
                int n = int.Parse(s[2]);
                int res = getResult(r, c, n);
                output.Add("Case #" + (i + 1) + ": " + res);
            }
            File.WriteAllLines(@"G:\ProblemBoutput.txt", output);
            //Console.ReadLine();
        }

        static int getResult(int r, int c, int n)
        {
            if (n <= (r * c + 1) / 2) return 0;
            int r1 = getResultBuildup(r, c, n);
            int r2 = getResultTeardown(r, c, n);
            int r3 = getResultBuildup(r, c, n, 1);
            int r4 = getResultTeardown(r, c, n, 1);
            //Console.WriteLine(r + ", " + c + ", " + n + ": " + r1 + ", " + r2 + ", " + r3 + ", " + r4);
            return Math.Min(Math.Min(r1, r2), Math.Min(r3, r4));
        }

        static int getResultBuildup(int r, int c, int n, int b = 0)
        {
            countN = new int[5];
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if ((i + j) % 2 == b) continue;
                    int count = 0;
                    if (i > 0) count++;
                    if (j > 0) count++;
                    if (i < r - 1) count++;
                    if (j < c - 1) count++;
                    countN[count]++;
                }
            }
            int unhappiness = 0;
            int startCount = (r * c + 1) / 2;
            if (b == 1) startCount = (r * c - 1) / 2;
            n -= startCount;
            for (int count = 1; count <= 4; count++)
            {
                int thisCount = Math.Min(n, countN[count]);
                n -= thisCount;
                unhappiness += thisCount * count;
            }
            //Console.WriteLine(countN[1] + ", " + countN[2] + ", " + countN[3] + ", " + countN[4]);
            return unhappiness;
        }

        static int getResultTeardown(int r, int c, int n, int b = 0)
        {
            countN = new int[5];
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if ((i + j) % 2 == b) continue;
                    int count = 0;
                    if (i > 0) count++;
                    if (j > 0) count++;
                    if (i < r - 1) count++;
                    if (j < c - 1) count++;
                    countN[count]++;
                }
            }
            int unhappiness = 2 * r * c - c - r;
            n = r * c - n;
            for (int count = 4; count >= 1; count--)
            {
                int thisCount = Math.Min(n, countN[count]);
                n -= thisCount;
                unhappiness -= thisCount * count;
            }
            //Console.WriteLine(countN[1] + ", " + countN[2] + ", " + countN[3] + ", " + countN[4]);
            return unhappiness;
        }
    }
}
