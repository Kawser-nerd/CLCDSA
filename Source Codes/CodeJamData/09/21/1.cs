using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;

namespace _1A
{
    class Heap<U> : List<U> where U : IComparable
    {
        public int Push(U data)
        {
            Add(data);
            int n = Count - 1;
            int p = (n - 1) / 2;
            while (p >= 0 && this[p].CompareTo(data) > 0)
            {
                U q = this[p];
                this[p] = this[n];
                this[n] = q;
                n = p;
                p = (n - 1) / 2;
            }
            return n;
        }

        public bool IsEmpty()
        {
            return Count == 0;
        }

        public U Peek()
        {
            return this[0];
        }

        public U Pop()
        {
            U peek = this[0];
            this[0] = this[Count - 1];
            RemoveAt(Count - 1);
            int n = 0, p;
            while (2 * n + 1 < Count)
            {
                p = n;
                if (this[2 * n + 1].CompareTo(this[n]) < 0) p = 2 * n + 1;
                if (2 * n + 2 < Count && this[2 * n + 2].CompareTo(this[p]) < 0)
                    p = 2 * n + 2;
                if (p != n)
                {
                    U tmp = this[p];
                    this[p] = this[n];
                    this[n] = tmp;
                    n = p;
                } else n = Count;
            }
            return peek;
        }

        public void Decreased(int position)
        {
            int n = position;
            int p = (n - 1) / 2;
            while (n != 0 && p >= 0 && this[p].CompareTo(this[n]) > 0)
            {
                U tmp = this[p];
                this[p] = this[n];
                this[n] = tmp;
                n = p;
                p = (n - 1) / 2;
            }
        }

        public void Increased(int position)
        {
            int n = position;
            while (2 * n + 1 < Count)
            {
                int p = n;
                if (this[2 * n + 1].CompareTo(this[p]) < 0)
                    p = 2 * n + 1;
                if (2 * n + 2 < Count && this[2 * n + 2].CompareTo(this[p]) < 0)
                    p = 2 * n + 2;
                if (p != n)
                {
                    U tmp = this[p];
                    this[p] = this[n];
                    this[n] = tmp;
                    n = p;
                } else n = Count;
            }
        }

    }

    class Reader
    {            
        static Reader()
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.GetCultureInfo("en-US");
        }

        static string buf;
        static bool empty = true;

        private static string WordDelims = " \t";

        public static int ReadInt()
        {
            Fill();
            string token = getToken(WordDelims);
            return int.Parse(token);
        }

        public static double ReadDouble()
        {
            Fill();
            string token = getToken(WordDelims);
            return double.Parse(token);
        }

        public static string ReadWord()
        {
            Fill();
            return getToken(WordDelims);
        }

        public static string ReadLine()
        {
            Fill();
            return getRest();
        }

        private static void Fill()
        {
            if (empty)
            {
                empty = false;
                buf = Console.ReadLine();
                ////
                buf = buf.Replace(")", " ) ");
                buf = buf.Replace("(", " ( ");
                buf = buf.Trim();
            }
        }

        public static string getToken(string ends)
        {
            int i = 0;
            while (i < buf.Length && !ends.Contains(buf[i]))
                i++;
            string output = buf.Substring(0, i);
            while (i < buf.Length && ends.Contains(buf[i]))
                i++;
            if (i < buf.Length)
            {
                buf = buf.Substring(i);
            } else
            {
                buf = "";
                empty = true;
            }
            return output;
        }

        private static string getRest()
        {
            string output = buf;
            empty = true;
            buf = "";
            return output;
        }
    }

    class Program
    {

        class Tree {
            public string Name;
            public double p;
            public bool Leaf;
            public Tree l, r;

            public void Read()
            {
                Leaf = false;
                string token = Reader.ReadWord(); //(
                p = Reader.ReadDouble();
                token = Reader.ReadWord();
                if (token == ")")
                {
                    Leaf = true;
                } else
                {
                    Name = token;
                    l = new Tree();
                    l.Read();
                    r = new Tree();
                    r.Read();
                    Reader.ReadWord();
                }
            }

        }

        static void Main(string[] args)
        {
            int T = Reader.ReadInt();
            for (int i = 1; i <= T; i++)
            {
                int l = Reader.ReadInt();
                Tree tr = new Tree();
                tr.Read();
                int a = Reader.ReadInt();
                Console.WriteLine("Case #{0}:", i);
                for (int j = 0; j < a; j++)
                {
                    string animal = Reader.ReadWord();
                    int features = Reader.ReadInt();
                    HashSet<string> feature = new HashSet<string>();
                    for (int k = 0; k < features; k++)
                    {
                        feature.Add(Reader.ReadWord());
                    }
                    double poss = 1;
                    Tree tn = tr;
                    while (tn != null)
                    {
                        poss = poss * tn.p;
                        if (tn.Leaf)
                        {
                            tn = null;
                        } else
                        {
                            if (feature.Contains(tn.Name))
                            {
                                tn = tn.l;
                            } else
                            {
                                tn = tn.r;
                            }
                        }
                    }
                    Console.WriteLine("{0:0.0000000}",poss);
                }
            }
        }
    }
}
