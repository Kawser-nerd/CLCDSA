using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2011_QRC
{
    class Program
    {
        private static void Main(string[] args)
        {
            string filedir = @"c:\temp\google_comp\";
            string inputfile = filedir + @"test1.in";
            string outputfile = inputfile.Replace(".in", ".out");
            
            Queue<string> lines = new Queue<string>(File.ReadAllLines(inputfile));
            int numcases = int.Parse(lines.Dequeue());
            var results = new List<string>();
            for (int casenum = 0; casenum < numcases; casenum++)
            {
                var q = new Queue<string>(lines.Dequeue().Split(' '));
                var trans2 = new Dictionary<char, string>();
                var trans1 = new Dictionary<string, char>();

                var t1 = q.TakeN(int.Parse(q.Dequeue()));
                foreach(var a in t1)
                {
                    trans1[a[0].ToString() + a[1]] = a[2];
                    trans1[a[1].ToString() + a[0]] = a[2];
                }

                var t2 = q.TakeN(int.Parse(q.Dequeue()));

                foreach(var a in t2)
                {
                    if (trans2.ContainsKey(a[0])) trans2[a[0]] += a[1]; else trans2[a[0]] = a[1].ToString();
                    if (trans2.ContainsKey(a[1])) trans2[a[1]] += a[0]; else trans2[a[1]] = a[0].ToString();
                }


                q.Dequeue();
                var t3 = q.Dequeue();

                var lcnt = new Dictionary<char, int>();
                List<char> cur = new List<char>();
                for(int i = 0; i < t3.Length; i++)
                {
                    char tt = t3[i];
                    cur.Add(tt);
                    lcnt.getoradd(tt, 1);
                    if (cur.Count < 2) continue;
                    string lt = cur[cur.Count - 1].ToString() + cur[cur.Count - 2];
                    if(trans1.TryGetValue(lt, out tt))
                    {
                        lcnt.getoradd(cur[cur.Count-1], -1);
                        cur.RemoveAt(cur.Count - 1);
                        lcnt.getoradd(cur[cur.Count - 1], -1);
                        cur[cur.Count - 1] = tt;
                        lcnt.getoradd(tt, 1);
                    }
                    else
                    {
                        tt = t3[i];
                    }

                    string aa;
                    if(trans2.TryGetValue(tt, out aa))
                    {
                        foreach(var aaa in aa)
                        {
                            if(lcnt.getoradd(aaa) > 0)
                            {
                                lcnt = new Dictionary<char, int>();
                                cur = new List<char>();
                                break;
                            }
                        }
                    }
                }

                var res = string.Join(", ", cur.ToArray());
                results.Add(string.Format("Case #{0}: [{1}]", casenum + 1, res));
            }

            File.WriteAllLines(outputfile, results);

        }

    }

    
    static class Extensions
    {
        public static int getoradd(this Dictionary<char, int> a, char b)
        {
            int v;
            if (a.TryGetValue(b, out v)) return v;
            a[b] = 0;
            return 0;
        }

        public static int getoradd(this Dictionary<char, int> a, char b, int offset)
        {
            int res = a.getoradd(b) + offset;
            a[b] = res;
            return res;
        }

        public static List<T> TakeN<T>(this Queue<T> q, int num)
        {
            List<T> res = new List<T>();
            for (int i = 0; i < num; i++) res.Add(q.Dequeue());
            return res;
        }
    }
}
