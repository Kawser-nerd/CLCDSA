using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    class Program
    {

        class Solver
        {
            struct Pair
            {
                public int x, y;
                public Pair(int x,int y)
                {
                    this.x=x;this.y=y;
                }
            }
            
            public string Solve(MyIO io)
            {
                HashSet<Pair> hash = new HashSet<Pair>();
                int A = io.NextInt, B = io.NextInt;
                for (int j = A; j <= B; j++)
                {
                    int num = j;
                    string num2 = j.ToString();
                    for (int i = 0; i < num2.Length; i++)
                    {
                        num2 = num2.Substring(1) + num2[0] ;
                        if (num2[0] == '0') continue;
                        if (num2 != num.ToString())
                        {
                            if(int.Parse(num2)<=B&&int.Parse(num2)>=A)
                                hash.Add(new Pair(num, int.Parse(num2)));
                        }
                    }

                }
                return (hash.Count/2).ToString()+"\n";
            }
        }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader("in.txt"));
            int caseCount = io.NextInt;
            for (int i = 0; i < caseCount; i++)
            {
                Solver solve = new Solver();
                string res = solve.Solve(io);
                io.Write("Case #{0}: {1}", i + 1, res);
                Console.Error.Write("Case #{0}: {1}", i + 1, res);
            }
            io.Flush();   
        }
        class MyIO
        {
            TextReader reader;
            TextWriter writer = new StreamWriter("out.txt");
            string[] tokens;
            int pointer;
            public MyIO(TextReader rd)
            {
                reader = rd;
            }
            public string NextLine()
            {
                try
                {
                    return reader.ReadLine();
                }
                catch (IOException)
                {
                    return null;
                }
            }
            public string NextString
            {
                get
                {
                    try
                    {
                        while (tokens == null || pointer >= tokens.Length)
                        {
                            tokens = NextLine().Split(new char[] { ' ' }, System.StringSplitOptions.RemoveEmptyEntries);
                            pointer = 0;
                        }
                        return tokens[pointer++];
                    }
                    catch (IOException)
                    {
                        return null;
                    }
                }
            }
            public int NextInt
            {
                get { return int.Parse(NextString); }
            }
            public long NextLong
            {
                get { return long.Parse(NextString); }
            }
            public double NextDouble
            {
                get { return double.Parse(NextString); }
            }
            public bool Write(string format, params object[] args)
            {
                writer.Write(format, args);
                return true;
            }
            public void WriteLine(string format, params object[] args)
            {
                writer.WriteLine(format, args);
            }
            public void WriteLine(object obj)
            {
                writer.WriteLine("{0}", obj);
            }
            public void WriteLine()
            {
                writer.WriteLine();
            }
            public void Write(object obj)
            {
                writer.Write("{0}", obj);
            }
            public void Flush()
            {
                writer.Flush();
            }
        }
    }
}
