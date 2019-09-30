using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            //string fileName = "in";
            string fileName = "B-small-attempt1.in";
            //string fileName = "B-large.in";
            Console.SetIn(new System.IO.StreamReader(@"..\..\..\" + fileName));
            Console.SetOut(new System.IO.StreamWriter(@"..\..\..\out"));

            //SetCulture();

            int testCases = ReadInt();
            for (int testCase = 1; testCase <= testCases; testCase++)
            {
                var nc = NextInt();
                var nj = NextInt();
                var acs = new int[nc];
                var ace = new int[nc];

                var ajs = new int[nj];
                var aje = new int[nj];
                
                for (int i = 0; i < nc; i++)
                {
                    acs[i] = NextInt();
                    ace[i] = NextInt();
                }

                for (int i = 0; i < nj; i++)
                {
                    ajs[i] = NextInt();
                    aje[i] = NextInt();
                }

                Array.Sort(acs, ace);
                Array.Sort(ajs, aje);

                int res = 0;
                if (nc + nj <= 2)
                {
                    var restc = 12 * 60;
                    var restj = 12 * 60;

                    if (nc == 2)
                    {
                        var combine = ace[1] - acs[0];
                        if (combine <= restj)
                        {
                            var rj2 = restj - combine;
                            if (rj2 >= acs[0] || rj2 >= (24 * 60 - ace[1]))
                            {
                                res = 1;
                            }
                            else
                            {
                                res = 2;
                            }
                        }
                        else
                        {
                            var dif = acs[1] - ace[0];
                            if (dif >= restc)
                            {
                                res = 2;
                            }
                            else
                            {
                                if ((ace[0] + ace[1] - acs[1]) <= restj || (24*60 - acs[1] + ace[0]-acs[0]) <= restj)
                                {
                                    res = 3;
                                }
                                else
                                {
                                    res = 4;
                                }
                            }
                        }
                    }
                    else if (nj == 2)
                    {
                        var combine = aje[1] - ajs[0];
                        if (combine <= restc)
                        {
                            var rc2 = restc - combine;
                            if (rc2 >= ajs[0] || rc2 >= (24 * 60 - aje[1]))
                            {
                                res = 1;
                            }
                            else
                            {
                                res = 2;
                            }
                        }
                        else
                        {
                            var dif = ajs[1] - aje[0];
                            if (dif >= restc)
                            {
                                res = 2;
                            }
                            else
                            {
                                if ((aje[0] + aje[1] - ajs[1]) <= restc || (24 * 60 - ajs[1] + aje[0] - ajs[0]) <= restc)
                                {
                                    res = 3;
                                }
                                else
                                {
                                    res = 4;
                                }
                            }
                        }
                    }
                    else if (nc == 0)
                    {
                        res = aje[0] <= restc || (24 * 60 - ajs[0]) <= restc ? 1 : 2;
                    }
                    else if (nj == 0)
                    {
                        res = ace[0] <= restj || (24 * 60 - acs[0]) <= restj ? 1 : 2;
                    }
                    else
                    {
                        // 1 - 1
                        if (ace[0] < restj)
                        {
                            if (ajs[0] >= 12*60)
                            {
                                res = 1;
                            }
                            else
                            {
                                res = 2;
                            }
                        }
                        else if (acs[0] >= 12*60)
                        {
                            if (aje[0] < 12*60)
                            {
                                res = 1;
                            }
                            else
                            {
                                res = 2;
                            }
                        }
                        else
                        {
                            res = 2;
                        }
                    }
                }
                
                Console.WriteLine("Case #{0}: {1}", testCase, res % 2 == 1 ? (res + 1) : res);
            }

            //Console.WriteLine(string.Format(NumberFormatInfo.InvariantInfo, "{0:F4}", res));

            Console.In.Close();
            Console.Out.Close();
        }

        private static char[] _defaultSplitter = new char[] { ' ', '\t' };

        private static void SetCulture()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        }

        private static char[] ReadChars(int n)
        {
            char[] buffer = new char[n];
            Console.In.ReadBlock(buffer, 0, n);
            return buffer;
        }

        private static string[] ReadAll()
        {
            return Console.In.ReadToEnd().Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries);
        }

        private static string[] ReadWords()
        {
            return ReadWords(_defaultSplitter);
        }

        private static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        private static int[] ReadInts(char[] splitter)
        {
            return Console.ReadLine().Split(splitter, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToArray();
        }

        private static int[] ReadInts()
        {
            return ReadInts(_defaultSplitter);
        }

        private static long ReadLong()
        {
            return long.Parse(Console.ReadLine());
        }

        private static double ReadDouble()
        {
            return double.Parse(Console.ReadLine(), NumberFormatInfo.InvariantInfo);
        }

        private static int _pos = 0;
        private static string[] _inputLine = new string[0];

        private static void CheckInputLine()
        {
            if (_pos >= _inputLine.Length)
            {
                _inputLine = ReadWords();
                _pos = 0;
            }
        }

        private static string NextWord()
        {
            CheckInputLine();
            return _inputLine[_pos++];
        }

        private static int NextInt()
        {
            CheckInputLine();
            return int.Parse(_inputLine[_pos++]);
        }

        private static long NextLong()
        {
            CheckInputLine();
            return long.Parse(_inputLine[_pos++]);
        }
    }
}
