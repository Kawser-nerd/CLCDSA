using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace gcj14r1b
{
    class Program
    {
        static string curstring;
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"C:\GCJ\C.in");
            int idx = 0;
            int t = int.Parse(lines[idx++]);
            TextWriter tw = new StreamWriter(@"C:\GCJ\C.out");
            for (int a = 0; a < t; a++)
            {
                string[] line = lines[idx++].Split(' ');
                int n = int.Parse(line[0]);
                int m = int.Parse(line[1]);
                string[] zcs = new string[n];
                for (int i = 0; i < n; i++)
                {
                    zcs[i] = lines[idx++];
                }
                bool[,] roads = new bool[n, n];
                for (int i = 0; i < m; i++)
                {
                    line = lines[idx++].Split(' ');
                    int c1 = int.Parse(line[0]) - 1;
                    int c2 = int.Parse(line[1]) - 1;
                    roads[c1,c2] = true;
                    roads[c2, c1] = true;
                }
                curstring = null;
                for (int i = 0; i < n; i++)
                {
                    bool[] used = new bool[n];
                    used[i] = true;
                    Stack<int> cities = new Stack<int>();
                    cities.Push(i);
                    calc(cities, zcs[i], used, zcs, roads);
                }
                tw.WriteLine("Case #{0}: {1}", a + 1, curstring);
            }
            tw.Close();
        }

        private static void calc(Stack<int> cities, string p, bool[] used, string[] zcs, bool[,] roads)
        {
            bool done = true;
            for (int i = 0; i < used.Length; i++)
            {
                if (!used[i])
                {
                    done = false;
                    Stack<int> left = new Stack<int>();
                    while(cities.Count > 0 && !roads[cities.Peek(),i]){
                        left.Push(cities.Pop());
                    }
                    if (cities.Count != 0 && roads[cities.Peek(), i])
                    {
                        used[i] = true;
                        cities.Push(i);
                        calc(cities, p + zcs[i], used, zcs, roads);
                        used[i] = false;
                        cities.Pop();
                    }
                    while (left.Count > 0)
                    {
                        cities.Push(left.Pop());
                    }
                }
            }
            if (done)
            {
                if (string.IsNullOrEmpty(curstring))
                {
                    curstring = p;
                }
                else if (p.CompareTo(curstring) < 0)
                {
                    curstring = p;
                }
            }
        }

    }
}
