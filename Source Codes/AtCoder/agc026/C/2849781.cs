using System;
using System.Collections.Generic;
using System.Linq;

namespace AGC026C
{
    internal class Solver
    {
        public int N;
        public string S;
        public Dictionary<string, long> FrontDic;
        public Dictionary<string, long> BackDic;

        public void Run()
        {
            N = ConsoleInput.Int();
            S = ConsoleInput.String();

            char[] front = new char[N];
            for (int i = 0; i < N; i++)
            {
                front[i] = S[i];
            }

            char[] back = new char[N];
            for (int i = 0; i < N; i++)
            {
                back[i] = S[2 * N - 1 - i];
            }

            FrontDic = new Dictionary<string, long>();
            BackDic = new Dictionary<string, long>();
            long Max = (long) Math.Pow(2, N);
            for (int i = 0; i < Max; i++)
            {
                string key = "";
                for (int j = 0; j < N; j++)
                {
                    if ((1 & i >> j) == 0)
                    {
                        key += front[j].ToString();
                    }
                }
                key += " ";

                for (int j = 0; j < N; j++)
                {
                    if ((1 & i >> j) != 0)
                    {
                        key += front[j].ToString();
                    }
                }

                if (FrontDic.ContainsKey(key))
                {
                    FrontDic[key]++;
                }
                else
                {
                    FrontDic.Add(key, 1);
                }
            }
            
            for (int i = 0; i < Max; i++)
            {
                string key = "";
                for (int j = 0; j < N; j++)
                {
                    if ((1 & i >> j) == 0)
                    {
                        key += back[j].ToString();
                    }
                }

                key += " ";
                for (int j = 0; j < N; j++)
                {
                    if ((1 & i >> j) != 0)
                    {
                        key += back[j].ToString();
                    }
                }
                if (BackDic.ContainsKey(key))
                {
                    BackDic[key]++;
                }
                else
                {
                    BackDic.Add(key, 1);
                }
            }

            long count = 0;
            foreach (KeyValuePair<string, long> kv in FrontDic)
            {
                //Console.WriteLine(kv.Key + " " + kv.Value);
                if (BackDic.ContainsKey(kv.Key))
                {
                    //Console.WriteLine("" + kv.Value + " " + BackDic[kv.Key]);
                    count += kv.Value * BackDic[kv.Key];
                }
            }
            Console.WriteLine(count);
        }
    }

    internal static class ConsoleInput
    {
        public static string String()
        {
            return Console.ReadLine();
        }

        public static int Int()
        {
            return int.Parse(Console.ReadLine());
        }

        public static int[] IntArray()
        {
            return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }

        public static long Long()
        {
            return long.Parse(Console.ReadLine());
        }

        public static long[] LongArray()
        {
            return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] DoubleArray()
        {
            return Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
        }
    }

    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solver();
            s.Run();
        }
    }
}