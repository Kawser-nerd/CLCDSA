using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Numerics;

namespace CodeChefNet
{
    class Program
    {
        private static bool fromFile = true;
        private static TextReader tmpReader;
        private static TextWriter tmpWriter;


        static void Main(string[] args)
        {
            if (fromFile)
            {
                tmpWriter = Console.Out;
                tmpReader = Console.In;
                Console.SetIn(new StreamReader(@"in.txt"));
                Console.SetOut(new StreamWriter(@"out.txt"));
            }

            //List<List<int>> choices = new List<List<int>>();
            //List<List<int>> sets = new List<List<int>>();
            //var r = new Random(DateTime.Now.Millisecond);
            //for (var i = 0; i < 100; i++)
            //{
            //    List<int> choice = new List<int>();
            //    for (var j = 0; j < 3; j++)
            //    {
            //        choice.Add(r.Next(2, 6));
            //       // Console.Write(choice[j] + " ");
            //    }
            //    choices.Add(choice);
            //    //Console.WriteLine();
            //        sets.Add(new List<int>());

            //    for (var k = 0; k < 7; k++)
            //    {
            //        var prod = 1;
            //        for (var j = 0; j < 3; j++)
            //        {
            //            if (r.NextDouble() < 0.5) prod *= choice[j];
            //        }
            //        sets[i].Add(prod);
            //       // Console.Write(prod + " ");
            //    }
            //   // Console.WriteLine();
            //   // Console.WriteLine();
            //}

            var T = GetInt();

            for (var i = 0; i < T; i++)
            {
                Console.WriteLine("Case #1:");
                var line = GetInts();
                var R = line[0];
                var N = line[1];
                var M = line[2];
                var K = line[3];
                var correct = 0;
                for (var j = 0; j < R; j++)
                {
                    var choice = new List<int>();
                    var l = GetInts();
                    if(l.Contains(2)) choice.Add(2);
                    if (l.Contains(3)) choice.Add(3);
                    if (l.Contains(5)) choice.Add(5);
                    if (l.Contains(6))
                    {
                        if (!choice.Contains(2)) choice.Add(2);
                        if (!choice.Contains(3)) choice.Add(3);
                    }
                    if (l.Contains(8))
                    {
                        if (!choice.Contains(2)) choice.Add(2);
                        if (!choice.Contains(4)) choice.Add(4);
                    }
                    if (l.Any(x => x % 9 == 0))
                    {
                        while(choice.Count(x=>x==3)<2)
                            choice.Add(3);
                    }
                    if (l.Any(x => x % 27 == 0))
                    {
                        while (choice.Count(x => x == 3) < 3)
                            choice.Add(3);
                    }
                    if (l.Contains(10))
                    {
                        if (!choice.Contains(2)) choice.Add(2);
                        if (!choice.Contains(5)) choice.Add(5);
                    }
                    if (l.Any(x => x % 16 == 0))
                    {
                        while (choice.Count(x => x == 4) < 2)
                            choice.Add(4);
                    }
                    if (l.Any(x => x % 64 == 0))
                    {
                        while (choice.Count(x => x == 4) < 3)
                            choice.Add(4);
                    }
                    if (l.Any(x => x % 25 == 0))
                    {
                        while (choice.Count(x => x == 5) < 2)
                            choice.Add(5);
                    }
                    if (l.Any(x => x % 125 == 0))
                    {
                        while (choice.Count(x => x == 5) < 3)
                            choice.Add(5);
                    }
                    if (l.Any(x => x % 5 == 0))
                    {
                        if (!choice.Contains(5)) choice.Add(5);
                    }
                    if (l.Any(x => x % 3 == 0))
                    {
                        if (!choice.Contains(3)) choice.Add(3);
                    }
                    if (l.Any(x => x % 20 == 0)&&choice.Contains(3))
                    {
                        if (!choice.Contains(3)) choice.Add(3);
                        if (!choice.Contains(4)) choice.Add(4);
                        if (!choice.Contains(5)) choice.Add(5);
                    }
                    if (l.Any(x => x % 20 == 0) && !choice.Contains(3) && choice.Count<3)
                    {
                        if (!choice.Contains(5)) choice.Add(5);
                        if (choice.Count(x => x == 5) == 2 && !choice.Contains(4)) choice.Add(4);
                        else
                        {
                            while (choice.Count(x => x == 2) < 2)
                                choice.Add(2);
                        }
                    }
                while(choice.Count<3) choice.Add(2);
                    Console.WriteLine(string.Format("{0}", string.Join("", choice.Take(3))));

                }

                  //  
            }


                if (fromFile)
                {
                    Console.Out.Flush();
                    Console.Out.Close();
                    Console.SetOut(tmpWriter);
                    Console.SetIn(tmpReader);

                    //Console.WriteLine("TIME: " + DateTime.Now.Subtract(st).TotalMilliseconds);
                    //Console.ReadKey();
                }
        }

        public static BigInteger sqrtbi(BigInteger N)
        {
            if(N==0) return 0;
            BigInteger n1 = (N >> 1) + 1;
            BigInteger n2 = (n1 + (N/n1)) >> 1;

            while (n2 < n1)
            {
                n1 = n2;
                n2 = (n1 + (N/n1)) >> 1;
            }
            return n1;
        }

        #region Getting stuff from console

        static string GetLine()
        {
            var line = Console.ReadLine();
            while (string.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
            }
            return line;
        }

        static int GetInt()
        {
            return int.Parse(GetLine());
        }

        static List<int> GetInts()
        {
            return GetLine().Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static long GetLong()
        {
            return long.Parse(GetLine());
        }

        static List<long> GetLongs()
        {
            return GetLine().Split(' ').Select(x => long.Parse(x)).ToList();
        }

        static string GetString()
        {
            return GetLine();
        }

        static string[] GetStrings()
        {
            return GetLine().Split(' ').ToArray();
        }

        #endregion
    }
}
