using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1B
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
        static string buf;
        static bool empty = true;

        private static string WordDelims = " \t";

        public static int ReadInt()
        {
            Fill();
            string token = getToken(WordDelims);
            return int.Parse(token);
        }

        public static long ReadLong()
        {
            Fill();
            string token = getToken(WordDelims);
            return long.Parse(token);
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
            }
        }

        private static string getToken(string ends)
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
        static void Main(string[] args)
        {
            int T = Reader.ReadInt();
            for (int i = 1; i <= T; i++)
            {
                string outs = "";
                //long l = Reader.ReadLong();
                string p = Console.ReadLine();
                int j = p.Length - 1;
                while (j > 0 && p[j - 1] >= p[j])
                    j--;
                if (j == 0)
                {
                    int n = -1;
                    for (int k = 0; k < p.Length; k++)
                        if (p[k] > '0') n = k; else break;
                    string pref = p.Substring(0, n + 1);
                    char[] prfcr = pref.ToCharArray();
                    Array.Sort(prfcr);
                    outs = new String(prfcr);
                    for (int k = n + 1; k <= p.Length; k++)
                    {
                        outs = outs.Insert(1, "0");
                    }
                } else
                {
                    string e = p.Substring(j);
                    char bound = p[j - 1];
                    char found = '9'; int index = 0;
                    for(int k = 0; k < e.Length; k++)
                        if (e[k] < found && e[k] > bound)
                        {
                            index = k;
                            found = e[k];
                        }
                    string st = p.Substring(0, j - 1) + found;
                    char[] encr = (e.Remove(index, 1) + bound).ToCharArray();
                    Array.Sort(encr);
                    string en = new String(encr);
                    outs = st + en;
                }
                Console.WriteLine("Case #{0}: {1}", i, outs);
            }
        }
    }
}
