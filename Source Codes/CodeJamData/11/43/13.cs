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

            var D = solveIt();

            var casenumber = 0;
            Console.WriteLine(DateTime.Now.Millisecond);
            for (var i = 0; i < file.Count; i++)
            {
                if (i == 0) continue;
                casenumber++;
                Console.WriteLine("Started - " + casenumber);

                rtn.Append("Case #" + casenumber + ": ");

                var x = Convert.ToInt32(file[i]);

                rtn.Append(D[x - 1]);



                    rtn.Append(Environment.NewLine);
            }
            Console.WriteLine(DateTime.Now.Millisecond);
            Console.ReadKey();
            #endregion

            return rtn.ToString();
        }

        List<int> solveIt()
        {
            var MaxW = new List<int> { 1 };
            var MinW = new List<int> { 1 };
            var Diff = new List<int> { 0 };
            var factors = new List<int>();
            for (var j = 1; j < 1000; j++)
            {
                var newfactor = 0;
                int jj = j + 1;
                var canDoit = false;
                for (var k = 0; k < factors.Count; k++)
                {
                    if (jj % factors[k] == 0)
                    {
                        jj = jj / factors[k];
                        if (jj == 1)
                        {
                            canDoit = true;
                            break;
                        }
                    }
                }
                if (canDoit)
                {
                    MaxW.Add(MaxW.Last());
                }
                else
                {
                    MaxW.Add(MaxW.Last() + 1);
                    newfactor = jj;
                }
                jj = j + 1;
                canDoit = false;
                for (var k = 0; k < factors.Count; k++)
                {
                    if (jj % factors[k] == 0)
                    {
                        jj = jj / factors[k];
                        k--;
                        if (jj == 1)
                        {
                            canDoit = true;
                            break;
                        }
                    }
                }
                if (canDoit || j == 1)
                {
                    MinW.Add(MinW.Last());
                }
                else MinW.Add(MinW.Last() + 1);

                Diff.Add(MaxW.Last() - MinW.Last());

                if (newfactor > 0) factors.Add(newfactor);
            }
            return Diff;
            
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
