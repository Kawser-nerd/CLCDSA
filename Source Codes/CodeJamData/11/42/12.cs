using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Execute(args.Length > 0 ? args[0] : @"D:\Users\richard\Desktop\input.txt");
        }

        void Execute(string filepath)
        {
            var file = LoadFile(filepath);
            var output = ProcessFile(file);
            WriteFile(filepath.Replace("input", "output"), output);
        }

        List<string> LoadFile(string filepath)
        {
            var input = new List<string>();
            using (var sr = new StreamReader(filepath))
            {
                while (!sr.EndOfStream)
                {
                    input.Add(sr.ReadLine());
                }
            }
            return input;
        }

        void WriteFile(string path, string output)
        {
            using (var sw = new StreamWriter(path, false))
            {
                sw.Write(output);
            }
        }

        string ProcessFile(List<string> file)
        {
            var rtn = new StringBuilder();

            #region Program specific code

            var casenumber = 0;
            Console.WriteLine(DateTime.Now.Millisecond);
            for (var i = 0; i < file.Count; i++)
            {
                if (i == 0) continue;
                casenumber++;
                Console.WriteLine("Started - " + casenumber);

                rtn.Append("Case #" + casenumber + ": ");

                var x = file[i].Split(' ');
                var R = Convert.ToInt32(x[0]);
                var C = Convert.ToInt32(x[1]);
                var D = Convert.ToInt32(x[2]);

                var grid = new int[R,C];

                for(var j = 0; j < R; j++)
                {
                    i++;
                    var xx = file[i];
                    for(var k = 0 ; k < C; k++)
                    {
                        grid[j, k] = Convert.ToInt32(xx[k].ToString());
                    }
                }

                //brute force
                var KK = Math.Min(R, C);
                var hasSolution = false;

                while (KK > 2)
                {
                    if (KK%2 == 1)
                    {
                        for (var j = 0; j < (R - (KK - 1)); j++)
                        {
                            for (var k = 0; k < C - (KK - 1); k++)
                            {
                                //test
                                var xmass = 0;
                                var ymass = 0;
                                for (var ii = 0; ii < KK; ii++)
                                {
                                    for (var jj = 0; jj < KK; jj++)
                                    {
                                        if (ii == 0 && jj == 0) continue;
                                        if (ii == 0 && jj == KK - 1) continue;
                                        if (ii == KK - 1 && jj == 0) continue;
                                        if (ii == KK - 1 && jj == KK - 1) continue;

                                        xmass += grid[j + ii, k + jj]*(((KK - 1)/2) - ii);
                                        ymass += grid[j + ii, k + jj]*(((KK - 1)/2) - jj);
                                    }
                                }
                                if (xmass == 0 && ymass == 0)
                                {
                                    hasSolution = true;
                                    rtn.Append(KK);
                                    break;
                                }
                            }
                            if (hasSolution) break;
                        }
                    }
                    else
                    {
                        for (var j = 0; j < (R - (KK - 1)); j++)
                        {
                            for (var k = 0; k < C - (KK - 1); k++)
                            {
                                //test
                                var xmass = 0;
                                var ymass = 0;
                                for (var ii = 0; ii < KK; ii++)
                                {
                                    for (var jj = 0; jj < KK; jj++)
                                    {
                                        if (ii == 0 && jj == 0) continue;
                                        if (ii == 0 && jj == KK - 1) continue;
                                        if (ii == KK - 1 && jj == 0) continue;
                                        if (ii == KK - 1 && jj == KK - 1) continue;

                                        if (ii < KK/2)
                                        {
                                            xmass += grid[j + ii, k + jj]*(((KK)/2) - ii);
                                        }
                                        else
                                        {
                                            xmass += grid[j + ii, k + jj]*(((KK)/2) - 1 - ii);
                                        }

                                        if (jj < KK/2)
                                        {
                                            ymass += grid[j + ii, k + jj]*(((KK)/2) - jj);
                                        }
                                        else
                                        {
                                            ymass += grid[j + ii, k + jj]*(((KK)/2) - 1 - jj);
                                        }

                                    }
                                }
                                if (xmass == 0 && ymass == 0)
                                {
                                    hasSolution = true;
                                    rtn.Append(KK);
                                    break;
                                }
                            }
                            if (hasSolution) break;
                        }
                    }
                    if(hasSolution) break;
                    KK--;
                }
                if (!hasSolution) rtn.Append("IMPOSSIBLE");

                rtn.Append(Environment.NewLine);
            }
            Console.WriteLine(DateTime.Now.Millisecond);
            Console.ReadKey();
            #endregion

            return rtn.ToString();
        }

        long GCD(long a, long b)
        {
            if(a==0) return b;
            if(b==0) return a;
            if(a==b) return a;
            return a > b ? GCD(a%b, b) : GCD(a, b%a);
        }

        long LCM(long a, long b)
        {
            long x;
            try
            {
                x = a*b/GCD(a, b);
            }
            catch(Exception e)
            {
                return 100000000000000000;
            }
            return x > 0 ? x : 100000000000000000;
        }
    }

    public struct walkway
    {
        public int start { get; set; }
        public int end { get; set; }
        public int speed { get; set; }
    }

}
