using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace jam1
{
    class Program
    {
        static void Main(string[] args)
        {
            const string pathIn = @"C:\temp\jam\A-large.in";
            const string pathOut = @"C:\temp\jam\A-large.out";
            int N;

            using (StreamReader sr = new StreamReader(pathIn))
            {
                string line = null;
                line = sr.ReadLine();

                //string[] parts = line.Split(new char[] { ' ' });                
                N = int.Parse(line);

                Dictionary<string, int> dict = new Dictionary<string, int>();

                using (StreamWriter sw = new StreamWriter(pathOut))
                {
                    for (int n = 0; n < N; n++)
                    {
                        line = sr.ReadLine();

                        Action solver = new Action(line);
                        string key = solver.GetKey();
                        int result = 0;

                        if (!dict.ContainsKey(key))
                            result = solver.Execute();
                        else
                            result = dict[key];


                        sw.WriteLine(string.Format("Case #{0}: {1}", n + 1, result));
                    }
                }
            }
        }
    }

    public class Action
    {
        int[] s;
        int[,] lookup;
        int max = int.MinValue;

        public Action(string line)
        {
            s = (from item in line.Split(new char[] { ' ' }) select int.Parse(item)).ToArray();
            lookup = new int[s.Length, 100000];           
        }

        public string GetKey()
        {
            return string.Join("", (from item in s orderby item select item.ToString()).ToArray());
        }

        public int Execute()
        {
            int x = 1;
            bool found = true;

            do
            {
                x++;
                found = true;
                for (int i = 0; i < s.Length; i++)
                {
                    bool result = Compute(x, s[i]);
                    if (!result)
                    {
                        found = false;
                        break;
                    }
                }
            } while (!found);
            Console.WriteLine(max);
            return x;
        }

        private int[] Convert(int n, int x)
        {
            List<int> result = new List<int>();
            do
            {
                int a = x % n;
                x = x / n;
                result.Add(a);
            } while (x > 0);

            return result.ToArray();
        }

        private bool Compute(int value, int system)
        {
            int x = value;

            int[] n;
            int sum = 0;
            List<int> helper = new List<int>();
            int systemPos = 0;

            while (s[systemPos] != system)
                systemPos++;

            while (true)
            {
                n = Convert(system, x);
                x = 0;
                for (int i = 0; i < n.Length; i++)
                {
                    x += n[i] * n[i];
                }

                if (x > max)
                    max = x;

                if (x == 1 || (x < lookup.Length && lookup[systemPos,x] == 1))
                {
                    foreach (int v in helper)
                    {
                        lookup[systemPos, v] = 1;
                    }

                    return true;
                }

                if (helper.Contains(x) || (x < lookup.Length && lookup[systemPos, x] == -1))
                {
                    foreach (int v in helper)
                    {
                        lookup[systemPos, v] = -1;
                    }

                    return false;
                }

                helper.Add(x);                
            }

            return false;
        }
    }
}
