using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
        class Program
        {
                int T, n;
                List<string> x = new List<string>();
                List<BigInt> a = new List<BigInt>();
                List<BigInt> delta = new List<BigInt>();
                BigInt gcd = new BigInt();
                BigInt answer = new BigInt();

                StreamWriter sw;

                public int Gcd(int x, int y)
                {
                        if (x % y == 0)
                                return y;
                        else
                                return Gcd(y, x % y);
                }

                public void Solve(int id)
                {
                        if (x.Count == 1)
                        {
                                sw.WriteLine("Case #{0}: {1}", id, 0);
                                return;
                        }
                        //List<int> a = new List<int>();
                        //List<int> delta = new List<int>();
                        //for (int i = 0; i < x.Count; i++)
                        //        a.Add(int.Parse(x[i]));
                        //for (int i = 1; i < x.Count; i++)
                        //        if (a[i] > a[i - 1])
                        //                delta.Add(a[i] - a[i - 1]);
                        //        else
                        //                delta.Add(a[i - 1] - a[i]);
                        //int gcd = delta[0];
                        //for (int i = 1; i < delta.Count; i++)
                        //        gcd = Gcd(gcd, delta[i]);
                        //for (int i = 0; i <= gcd; i++)
                        //{
                        //        bool flag = true;
                        //        for (int t = 0; t < a.Count; t++)
                        //                if ((a[t] + i) % gcd != 0)
                        //                        flag = false;
                        //        if (flag)
                        //        {
                        //                sw.WriteLine("Case #{0}: {1}", id, i);
                        //                break;
                        //        }
                        //}
                        a.Clear();
                        delta.Clear();
                        for (int i = 0; i < x.Count; i++)
                        {
                                BigInt t = new BigInt();
                                t = BigInt.Parse(x[i]);
                                a.Add(t);
                        }
                        for (int i = 1; i < a.Count; i++)
                                if (a[i] > a[i - 1])
                                        delta.Add(a[i] - a[i - 1]);
                                else
                                        delta.Add(a[i - 1] - a[i]);
                        gcd = delta[0];
                        for (int i = 1; i < delta.Count; i++)
                                if (delta[i] % gcd != 0)
                                        gcd = BigInt.Gcd(gcd, delta[i]);
                        if (a[0]% gcd==0)
                                answer = 0;
                        else
                                answer = gcd - (a[0] % gcd);
                        sw.WriteLine("Case #{0}: {1}", id, answer.ToString());
                }

                public void Work(string filename)
                {
                        StreamReader sr = new StreamReader(filename);
                        sw = new StreamWriter("b.txt");
                        T = int.Parse(sr.ReadLine());
                        for (int i = 0; i < T; i++)
                        {
                                string line = sr.ReadLine();
                                string[] item = line.Split(new char[] { ' ' });
                                n = int.Parse(item[0]);
                                x.Clear();
                                for (int t = 1; t <= n; t++)
                                        insert(item[t], x);
                                Solve(i + 1);
                                Console.WriteLine(i);
                        }
                        sr.Close();
                        sw.Close();
                }

                public void insert(string t, List<string> a)
                {
                        for (int i = 0; i < a.Count; i++)
                                if (a[i].Equals(t))
                                        return;
                        a.Add(t);
                }

                static void Main(string[] args)
                {
                        string filename = "B-large.in";
                        Program a = new Program();
                        a.Work(filename);
                }
        }


       
}
