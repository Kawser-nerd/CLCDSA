using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleJam
{
    class Program
    {
        private const string Problem = "Box Factory";
        
        private static void Solve(int T)
        {
            for ( int test = 1; test <= T; test++)
            {
                var input = ReadIntArray();
                var n = input[0];
                var m = input[1];
                var b = new List<KeyValuePair<long, int>>();
                var s = ReadArray();
                for (int i = 0; i < n; i++)
                {
                    b.Add(new KeyValuePair<long, int>(long.Parse(s[2*i]), int.Parse(s[2*i+1])));
                }
                var t = new List<KeyValuePair<long, int>>();
                s = ReadArray();
                for (int i = 0; i < m; i++)
                {
                    t.Add(new KeyValuePair<long, int>(long.Parse(s[2*i]), int.Parse(s[2*i + 1])));
                }
                var answer = Find(0, 0, 0, 0, b, t);

                Console.WriteLine(String.Format(OUPUT_STRING_FORMAT, test, answer));
            }
        }

        private static long Find(int bI, int tI, long bC, long tC, List<KeyValuePair<long, int>> b, List<KeyValuePair<long, int>> t)
        {
            if(bI >= b.Count || tI >= t.Count)
                return 0;

            var res = 0L;
            if (b[bI].Value == t[tI].Value)
            {
                var min = Math.Min(b[bI].Key - bC, t[tI].Key - tC);
                res += min;
                bC += min;
                tC += min;
                res += Find((bC == b[bI].Key) ? bI + 1 : bI, (tC == t[tI].Key) ? tI + 1 : tI, (bC == b[bI].Key) ? 0: bC, (tC == t[tI].Key) ?0:tC, b, t);
            }
            else
            {
                var skipB = Find(bI + 1, tI, 0, tC, b, t);
                var skipT = Find(bI, tI + 1, bC, 0, b, t);
                res += Math.Max(skipB, skipT);
            }

            return res;
        }

        static void Main()
        {
            Console.SetIn(new StreamReader(String.Format(@"..\..\{0}.in", Problem)));
            if (!Debugger.IsAttached)
                Console.SetOut(new StreamWriter(String.Format(@"..\..\{0}.out", Problem)));

            var T = ReadInt();

            Solve(T);

            Console.In.Close();
            Console.Out.Flush();
            Console.Out.Close();
         
            if (Debugger.IsAttached)
            {
                Console.SetIn(new StreamReader(Console.OpenStandardInput()));
                Console.ReadLine();
            }
        }

        const string OUPUT_STRING_FORMAT = "Case #{0}: {1}";

        #region Reader

        private static string Read()
        {
            return Console.ReadLine();
        }

        private static string[] ReadArray()
        {
            return Console.ReadLine().Split(' ');
        }

        private static List<int> ReadIntArray()
        {
            var input = Console.ReadLine().Split(' ').Select(Int32.Parse).ToList();
            return input;
        }

        private static List<double> ReadDoubleArray()
        {
            var input = Console.ReadLine().Split(' ').Select(double.Parse).ToList();
            return input;
        }

        private static int ReadInt()
        {
            return Int32.Parse(Console.ReadLine());
        }

        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        private static int ReadNextInt(string[] input, int index)
        {
            return Int32.Parse(input[index]);
        }

        #endregion

    }
}
