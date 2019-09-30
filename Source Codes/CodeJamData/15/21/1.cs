using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem1A
{
    class Program
    {
        static int[] best = new int[100000001];

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines(@"G:\A-large (1).in");
            List<string> output = new List<string>();
            //fillArray();
            int N = int.Parse(input[0]);
            for (int i = 0; i < N; i++)
            {
                long x = long.Parse(input[i + 1]);
                long res = getResult(x);
                output.Add("Case #" + (i + 1) + ": " + res);
            }
            File.WriteAllLines(@"G:\ProblemAoutput.txt", output);
        }

        static void fillArray()
        {
            Queue<int> next = new Queue<int>();
            best[1] = 1;
            for (int i = 2; i <= 1000000; i++) best[i] = 999999999;
            next.Enqueue(1);
            while (next.Count > 0)
            {
                int x = next.Dequeue();
                //Console.WriteLine(x);
                if (x >= 1000000) continue;
                if (best[x] + 1 < best[x + 1])
                {
                    best[x + 1] = best[x] + 1;
                    next.Enqueue(x + 1);
                }
                char[] chars = x.ToString().ToCharArray();
                Array.Reverse(chars);
                int x2 = int.Parse(new string(chars));
                if (best[x] + 1 < best[x2])
                {
                    best[x2] = best[x] + 1;
                    next.Enqueue(x2);
                }
            }
            for (int i = 2; i <= 100000; i++)
            {
                if (best[i] <= best[i - 1]) Console.WriteLine(i);
            }
            Console.ReadLine();
        }

        static long getResult(long x)
        {
            if (x < 21) return x;
            int digits = x.ToString().Length;
            if (digits > getDigits(x - 1)) return 1 + getResult(x - 1);
            int mod10 = (digits + 1) / 2;
            long mod = 1;
            for (int i = 0; i < mod10; i++) mod *= 10;
            long curMod = x % mod;
            long total = curMod - 1;
            if (total == -1) total += mod;
            long rem = x - total;
            if (isPal(rem)) return total + 2 + getResult(rem - 2);
            return total + 1 + getResult(reverse(rem));
        }

        static long reverse(long x)
        {
            char[] chars = x.ToString().ToCharArray();
            Array.Reverse(chars);
            return long.Parse(new string(chars));
        }

        static bool isPal(long x)
        {
            return reverse(x) == x;
        }

        static int getDigits(long x)
        {
            return x.ToString().Length;
        }
    }
}
