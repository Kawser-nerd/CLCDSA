using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CodeJamSharp
{

    class Program
    {

        const int Z = 2 * 3 * 5 * 7;
        static ulong[,] cache;
        static bool[] visited;

        static int mod(ulong number)
        {
            ulong ret = number % Z;
            if (ret < 0) return (int) (Z + ret);
            return (int)ret;
        }

        static int mod(int number)
        {
            int ret = number % Z;
            if (ret < 0) return Z + ret;
            return (int)ret;
        }

        static void calc(int pos, ulong number)
        {
            if (visited[pos]) return;
            ulong part = 0;
            cache[pos, mod(number)] += 1;
            ulong mul = 1;
            for (int i = pos+1; i < visited.Length; i++)
            {
                part += mul * (number % 10);
                mul *= 10;
                number /= 10;
                calc(i, number);
                int mpart = mod(part);
                for (int ii = 0; ii < Z; ii++)
                {
                    cache[pos, mod(ii - mpart)] += cache[i, ii];
                    cache[pos, mod(ii + mpart)] += cache[i, ii];
                }
            }

/*            Console.WriteLine("Pos = {0} N = {1}", pos, number);
            for (int ii = 0; ii < Z; ii++)
                if (cache[pos, ii] != 0)
                {
                    Console.WriteLine("{0}, {1} = {2}", pos, ii, cache[pos, ii]);
                } */

            visited[pos] = true;
        }

        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\B.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\B.out"))
            {
                string line = sr.ReadLine();
                int N = int.Parse(line);
                for (int c = 1; c <= N; c++)
                {
                    line = sr.ReadLine();
                    ulong val = ulong.Parse(line);
                    cache = new ulong[line.Length, Z];
                    visited = new bool[line.Length];
                    calc(0, val);
                    ulong count = 0;
                    for (int i = 0; i < Z; i++)
                    {
                        if (i % 2 == 0)
                        {
                            count += cache[0, i];
                        }
                        else if (i % 3 == 0)
                        {
                            count += cache[0, i];
                        }
                        else if (i % 5 == 0)
                        {
                            count += cache[0, i];
                        }
                        else if (i % 7 == 0)
                        {
                            count += cache[0, i];
                        }
                        
                    }
                    sout.WriteLine("Case #{0}: {1}", c, count);
                }
            }
        }
    }
}
