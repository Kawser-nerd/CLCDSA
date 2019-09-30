using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ZurichProblemB
{
    class Program
    {
        class Offer: IComparable<Offer>
        {
            public int first;
            public int last;
            public string color;
            public Offer(string c, int f, int l)
            {
                first = f;
                last = l;
                color = c;
            }

            #region IComparable<Offer> Members

            public int CompareTo(Offer other)
            {
                return first.CompareTo(other.first);
            }

            #endregion
        }

        static bool Covers(Offer[] offers, int mask)
        {
            int fst = 10001;
            int lst = -1;
            int i = 0; 
            while (mask > 0)
            {
                if ((mask & 1) != 0)
                {
                    if (fst > 10000)
                    {
                        if (offers[i].first != 1)
                            return false;
                        fst = 1;
                    }
                    else
                    {
                        if (lst + 1 < offers[i].first)
                            return false;
                    }
                    lst = Math.Max(lst, offers[i].last);
                }
                i++;
                mask = mask >> 1;
            }
            return lst >= 10000;        
        }
        
        static int ColorCount(Offer[] offers, int mask)
        {
            int i = 0;
            Dictionary<string, bool> list = new Dictionary<string, bool>(10);
            while (mask > 0)
            {
                if ((mask & 1) != 0)
                {
                    if (!list.ContainsKey(offers[i].color))
                        list.Add(offers[i].color, true);
                }
                i++;
                mask = mask >> 1;
            }
            return list.Count();
        }
        

        static int GetBitCount(int mask)
        {
            int res = 0;
            while (mask > 0)
            {
                if ((mask & 1) != 0)
                    res++;
                mask >>= 1;
            }
            return res;
        }

        static void Main(string[] args)
        {
            //const string fileName = "test";
            const string fileName = "B-small-attempt0";
            //const string fileName = "B-large";
            string DataFolder = @"C:\Projects\CSharp\CodeJam2008\ZurichProblemB\Data\";
            StreamReader sr = File.OpenText(DataFolder + fileName + ".in");
            using (StreamWriter sw = File.CreateText(DataFolder + fileName + ".out"))
            {
                int caseCount = int.Parse(sr.ReadLine());
                for (int caseNumber = 1; caseNumber <= caseCount; ++caseNumber)
                {
                    int N = int.Parse(sr.ReadLine());
                    Offer[] offers = new Offer[N];
                    for (int i = 0; i < N; ++i)
                    {
                        string[] s = sr.ReadLine().Split(' ');
                        offers[i] = new Offer(s[0], int.Parse(s[1]), int.Parse(s[2]));
                    }
                    Array.Sort(offers);

                    int res = N + 1;
                    for (int mask = (1 << N) - 1; mask > 0; mask--)
                    {
                        if (Covers(offers, mask) && ColorCount(offers, mask) <= 3)
                            res = Math.Min(res, GetBitCount(mask));
                    }

                    string sres = "";
                    if (res > N)
                        sres = "IMPOSSIBLE";
                    else
                        sres = res.ToString();

                    sw.WriteLine("Case #" + caseNumber.ToString() + ": " + sres);

                }
            }
        }
    }
}
