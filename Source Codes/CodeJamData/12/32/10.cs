using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace pb
{
    class Env
    {
        static public string[] delim = { " ", "\t" };
        public StreamReader srd;
        public StreamWriter swr;
    }
    class Program
    {
        static void probCore(long T, Env env)
        {
            Console.WriteLine("start#{0}", T);
            double D;
            int N;
            int A;
            {
                string line = env.srd.ReadLine();
                string[] parts = line.Split(Env.delim, StringSplitOptions.None);
                D = Double.Parse(parts[0]);
                N = Int32.Parse(parts[1]);
                A = Int32.Parse(parts[2]);
            }
            double[] t = new double[N];
            double[] x = new double[N];
            for (int i = 0; i < N; i++)
            {
                string line = env.srd.ReadLine();
                string[] parts = line.Split(Env.delim, StringSplitOptions.None);
                t[i] = Double.Parse(parts[0]);
                x[i] = Double.Parse(parts[1]);
            }
            double[] a = new double[A];
            {
                string line = env.srd.ReadLine();
                string[] parts = line.Split(Env.delim, StringSplitOptions.None);
                for (int i = 0; i < A; i++)
                {
                    a[i] = Double.Parse(parts[i]);
                }
            }

            double tg;
            if (x[0] >= D)
            {
                // 邪魔者はない
                tg = 0;
            }
            else
            {
                //small特化判定

                //邪魔ものの速度
                double js = (x[1] - x[0]) / (t[1] - t[0]);

                //邪魔ものが進むべき距離
                double jx = (D - x[0]);
                //邪魔ものがゴールする時間
                tg = jx / js;
                Console.WriteLine("jx{0} js{1}", jx, js);
            }
            Console.WriteLine("tg{0}", tg);

            env.swr.WriteLine("Case #{0}:", T);
            for (int i = 0; i < A; i++)
            {
                double besttime = Math.Sqrt(2.0 * D / a[i]);

                double time = (tg < besttime) ? besttime : tg;
                env.swr.WriteLine("{0}", time);
            }

        }

        static void probLoop(Env env)
        {
            string line = env.srd.ReadLine();
            Stopwatch sw = new Stopwatch();
            sw.Start();
            long t = Int64.Parse(line);
            for (long i = 1; i <= t; i++)
            {
                probCore(i, env);
            }
            sw.Stop();
            long millisec = sw.ElapsedMilliseconds;
            Console.WriteLine("used:{0}[ms]", millisec);
        }

        static void Main(string[] args)
        {
            StreamReader srd = null;
            StreamWriter swr = null;
            Env env = new Env();

            try
            {
                srd = new StreamReader(
                    args[0], Encoding.GetEncoding("Shift_JIS"));
                env.srd = srd;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            try
            {
                swr = new StreamWriter(
                    args[1], false, Encoding.GetEncoding("Shift_JIS"));
                env.swr = swr;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            probLoop(env);

            swr.Close();
        }
    }
}
