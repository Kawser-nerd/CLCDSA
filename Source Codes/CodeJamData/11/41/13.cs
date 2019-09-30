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
                var X = Convert.ToInt32(x[0]);
                var S = Convert.ToInt32(x[1]);
                var R = Convert.ToInt32(x[2]);
                var t = Convert.ToInt32(x[3]);
                var N = Convert.ToInt32(x[4]);

                var walkways = new List<walkway>();

                for (var j = 0; j < N; j++)
                {
                    i++;
                    var xx = file[i].Split(' ');
                    var w = new walkway
                                {
                                    start = Convert.ToInt32(xx[0]),
                                    end = Convert.ToInt32(xx[1]),
                                    speed = Convert.ToInt32(xx[2])
                                };
                    walkways.Add(w);
                }

                walkways = walkways.OrderBy(c => c.start).ToList();

                //fill walkways with 0 speed walkways

                var lastpos = 0;
                var lastw = 0;
                while(lastw < walkways.Count)
                {
                    if(walkways[lastw].start==lastpos)
                    {
                        lastpos = walkways[lastw].end;
                        lastw++;
                    }
                    else
                    {
                        walkways.Insert(lastw, new walkway { start = lastpos, end = walkways[lastw].start, speed=0});
                        lastw += 2;
                        lastpos = walkways[lastw - 1].end;
                    }
                }
                if(walkways.Last().end < X)
                {
                    walkways.Add(new walkway{start=walkways.Last().end, end=X, speed=0});
                }

                walkways = walkways.OrderBy(c => c.speed).ToList();

                var totalTime = 0.0;
                var T = (double) t;

 
                    while(T>0&&walkways.Count>0){
                        var tdash = (double) (walkways[0].end - walkways[0].start)/(R + walkways[0].speed);
                        if(tdash<=T)
                        {
                            //run the whole walkway
                            totalTime += tdash;
                            T -= tdash;
                        }
                        else
                        {
                            //run part way
                            var dist = (R + walkways[0].speed)*T;
                            totalTime += T;
                            totalTime += (double) (walkways[0].end - walkways[0].start - dist)/(S + walkways[0].speed);
                            T = 0;
                        }
                        walkways.RemoveAt(0);
                    }


                //walk remaining walkways
                for (var j = 0; j < walkways.Count; j++)
                {
                    totalTime += (double)(walkways[j].end - walkways[j].start) / (S + walkways[j].speed);
                }

                rtn.Append(totalTime);
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
