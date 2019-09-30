using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static int T, rr, nn, mm, kk;
        static List<int> vv=new List<int>();
        static List<int> choose = new List<int>();
        static List<List<int>> chosen = new List<List<int>>();
        static List<List<int>> multi = new List<List<int>>();
        static List<Dictionary<int,int>> multiPrio = new List<Dictionary<int,int>>();
        static int mulTemp;

        static void recursemul(List<int> current, List<int> mul, int index)
        {           
            if (index < current.Count - 1) recursemul(current, mul, index + 1);
            else  mul.Add(mulTemp);
            mulTemp *= current[index];
            if (index < current.Count - 1) recursemul(current, mul, index + 1);
            else mul.Add(mulTemp);
            mulTemp /= current[index];
        }

        static void multiply()
        {
            List<int> current = chosen[chosen.Count - 1];
            List<int> mul = new List<int>();
            mulTemp = 1;
            recursemul(current, mul, 0);
            //foreach (int i in mul) Console.Write(i.ToString() + ' ');
            //Console.Write('\n');

            Dictionary<int, int> d = new Dictionary<int, int>();
            foreach (int i in mul)
            {
                if (d.ContainsKey(i)) d[i]++;
                else d.Add(i, 1);
            }
            multiPrio.Add(d);
            multi.Add(mul);
        }

        static void recurse(int index)
        {
            for (int i = 2; i <= mm;i++ )
            {
                choose.Add(i);
                if (index < nn - 1) recurse(index + 1);
                else
                {
                    List<int> c = new List<int>(choose);
                    chosen.Add(c);
                    //foreach (int a in choose) Console.Write(a.ToString() + ' ');
                    //Console.Write(":\n");
                    multiply();
                    
                }
                choose.RemoveAt(choose.Count - 1);
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("y:/C-small-1-attempt0.in");
            StreamWriter sw = new StreamWriter("y:/output",false);

            sr.ReadLine();

            sw.WriteLine("Case #1:");
            string[] s = sr.ReadLine().Split(' ');
            rr = s[0].toInt(); nn = s[1].toInt(); mm = s[2].toInt(); kk = s[3].toInt();
            recurse(0);
            for (int i = 0; i < rr; i++)
            {
                vv.Clear();
                s = sr.ReadLine().Split(' ');
                foreach (string ss in s) vv.Add(ss.toInt());
                int judge = 0;
                Dictionary<int, int> judgeDict = new Dictionary<int, int>();
                int index = 0;
                foreach (Dictionary<int, int> dict in multiPrio)
                {

                    bool valid = true;
                    foreach (int v in vv) if (dict.ContainsKey(v) == false) valid = false;
                    if (valid)
                    {
                        judge = 0;
                        foreach (int v in vv) judge += dict[v];
                        judgeDict.Add(index, judge);
                    }

                    index++;
                }
                List<int> l = new List<int>(judgeDict.Values);
                l.Sort();
                int j = l[l.Count / 2];
                List<int> random = new List<int>();
                foreach (KeyValuePair<int, int> p in judgeDict)
                {
                    if (p.Value >= j) random.Add(p.Key);
                }
                Random seed = new Random();
                Random rand = new Random(seed.Next());
                int ran = rand.Next(0, random.Count);
                foreach(int lll in chosen[random[ran]])
                {
                    sw.Write(lll.ToString());
                }
                sw.WriteLine("");
            }
            sw.Close();
            //Console.ReadLine();
        }
    }

    static class MyExt
    {
        public static int toInt(this string s)
        {
            return Int32.Parse(s);
        }
        public static double toDouble(this string s)
        {
            return Double.Parse(s);
        }
    }
}
