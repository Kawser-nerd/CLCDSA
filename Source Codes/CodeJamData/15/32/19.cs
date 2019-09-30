using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Monkey
    {
        static char[] keys;
        static char[] target;
        static int k, l, s;
        static char[] test;
        static int best;
        static long total;
        static int cases;

        static bool substr(int start)
        {
            for (int i = 0; i < l; i++)
                if (target[i] != test[start + i])
                    return false;
            return true;
        }

        static void Process()
        {
            int count = 0;
            for (int start = s - l; start >= 0; start--)
            {
                if (substr(start))
                    count++;
            }

            cases++;
            total += count;
            if (count > best)
                best = count;
        }

        static void Gen(int i)
        {
            if (i == s)
            {
                // process case
                Process();
            }
            else
            {
                for (int j = 0; j < k; j++)
                {
                    test[i] = keys[j];
                    Gen(i + 1);
                }
            }
        }

        static double Test()
        {
            if (s < l) return 0;
            best = 0;
            total = 0;
            cases = 0;

            Gen(0);

            Console.WriteLine("Best case: " + best);
            Console.WriteLine("Total: " + total + " over " + cases + " cases");

            return (double)best - (double)total / (double)cases;
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("monkey_in.txt");
            int t = int.Parse(lines[0]);
            string[] res = new string[t];
            test = new char[7];
            for (int i = 0; i < t; i++)
            {
                int[] vars = lines[3 * i + 1].Split(' ').Take(3).Select(str => int.Parse(str)).ToArray();
                k = vars[0];
                l = vars[1];
                s = vars[2];
                keys = lines[3 * i + 2].ToCharArray();
                target = lines[3 * i + 3].ToCharArray();
                res[i] = string.Format("Case #{0}: {1}", i + 1, Test());
                Console.WriteLine("Test #{0} done", i + 1);
            }

            File.WriteAllLines("monkey_out.txt", res);
            Console.ReadKey();
        }
    }
}
