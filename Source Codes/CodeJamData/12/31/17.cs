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
        private const string Problem = "Diamond_Inheritance";
        
        private static void Solve(int T)
        {
            for ( int test = 1; test <= T; test++)
            {
                var n = ReadInt();
                var table = new Dictionary<int, List<int>>();
                for (int i = 1; i <= n; i++)
                {
                    var input = ReadIntArray().Skip(1);
                    table.Add(i, new List<int>(input));
                }
                var good = false;
                for (int i = 1; i <= n; i++)
                {
                    good = false;
                    var res = new List<int>();
                    if(Fill(i, res, table))
                    {
                        good = true;
                        break;
                    }
                }
                var answer = "No";
                if (good)
                    answer = "Yes";


                Console.WriteLine(String.Format(OUPUT_STRING_FORMAT, test, answer));
            }
        }

        private static bool Fill(int i, List<int> res, Dictionary<int, List<int>> table)
        {
            foreach (var child in table[i])
            {
                if(res.Contains(child))
                    return true;

                res.Add(child);

                if(Fill(child, res, table))
                    return true;
            }
            return false;
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
