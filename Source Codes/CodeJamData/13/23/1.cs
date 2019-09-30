using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
namespace GCJ
{
    class Program
    {

        class Solver
        {
            int[,] dp = new int[5000,5];
            public string Solve(MyIO io)
            {
                for(int i=0;i<5000;i++)for(int j=0;j<5;j++) dp[i,j] = 99999999;
                TextReader tr = new StreamReader("garbled_email_dictionary.txt");
                List<string> l = new List<string>();
                string ss = "";
                while (null != (ss = tr.ReadLine())) l.Add(ss);
                tr.Close();
                ss = io.NextString;
                string res = "";
                dp[0, 4] = 0;
                for (int i = 1; i <= ss.Length; i++)
                {
                    for (int j = 0; j < l.Count; j++)
                    {
                        if (ss.Length - i + 1 < l[j].Length) continue;
                        bool ok = true;
                        int firstdiff = -1;
                        int lastdiff = -1;
                        int diffcnt = 0;
                        for (int k = 0; k < l[j].Length; k++)
                        {
                            if (l[j] == "code" || l[j] == "jam")
                            {

                            }
                            if (ss[i - 1 + k] != l[j][k])
                            {
                                if (firstdiff == -1) firstdiff = k;
                                if (lastdiff == -1) lastdiff = k;
                                else if (k - lastdiff < 5)
                                {
                                    ok = false;
                                    break;
                                }
                                else lastdiff = k;
                                diffcnt++;
                            }
                        }
                        if (!ok) continue;
                        int xx = lastdiff;
                        if (lastdiff == -1) lastdiff = 4;
                        else lastdiff = Math.Min(4, l[j].Length - 1 - lastdiff);
                        if (firstdiff == -1 || firstdiff > 4) firstdiff = 4;

                        for (int k = 4 - firstdiff; k < 5; k++)
                        {
                            if (xx != -1) dp[i + l[j].Length - 1, lastdiff] = Math.Min(dp[i + l[j].Length - 1, lastdiff], dp[i - 1, k] + diffcnt);
                            else
                            {
                                dp[i + l[j].Length - 1, Math.Min(4, k + l[j].Length)] = Math.Min(dp[i + l[j].Length - 1, Math.Min(4, k + l[j].Length)], dp[i - 1, k] + diffcnt);
                            }

                        }
                    }
                }
                int R = 99999999;
                for (int i = 0; i < 5; i++)
                {
                    R = Math.Min(dp[ss.Length,i ], R);
                }
                return
                    R.ToString() + "\n";
            }
        }
        static void Main(string[] args)
        {
            MyIO io = new MyIO(new StreamReader("in.txt"));
            int caseCount = io.NextInt;
            Solver solve = new Solver();
            for (int i = 0; i < caseCount; i++)
            {
                string res = solve.Solve(io);
                io.Write("Case #{0}: {1}", i + 1, res);
                Console.Write("Case #{0}: {1}", i + 1, res);
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
