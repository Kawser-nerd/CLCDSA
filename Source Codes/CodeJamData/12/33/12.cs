using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace mappy5
{
    class Program
    {
        static Int64 calc(List<Tuple<Int64, Int64>> nlist, List<Tuple<Int64, Int64>> mlist, int nindex, int mindex, Int64 nleft, Int64 mleft)
        {
            Int64 result = 0;
            while (nlist[nindex].Item2 == mlist[mindex].Item2) {
                if (nleft > mleft) {
                    result += mleft;
                    if (++mindex >= mlist.Count) return result;
                    nleft -= mleft;
                    mleft = mlist[mindex].Item1;
                } else if (nleft < mleft) {
                    result += nleft;
                    if (++nindex >= nlist.Count) return result;
                    mleft -= nleft;
                    nleft = nlist[nindex].Item1;
                } else {
                    result += nleft;
                    if (++mindex >= mlist.Count) return result;
                    if (++nindex >= nlist.Count) return result;
                    mleft = mlist[mindex].Item1;
                    nleft = nlist[nindex].Item1;
                }
            }

            Int64 mresult = mindex + 1 < mlist.Count ? calc(nlist, mlist, nindex, mindex + 1, nleft, mlist[mindex + 1].Item1) : 0;
            Int64 nresult = nindex + 1 < nlist.Count ? calc(nlist, mlist, nindex + 1, mindex, nlist[nindex + 1].Item1, mleft) : 0;
            return result + Math.Max(mresult, nresult);
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0], Encoding.GetEncoding("Shift_JIS")))
            {
                int T = int.Parse(reader.ReadLine());
                for (int t = 0; t < T; t++)
                {
                    string[] tmp;
                    tmp = reader.ReadLine().Split(' ');
                    int N = int.Parse(tmp[0]);
                    int M = int.Parse(tmp[1]);

                    tmp = reader.ReadLine().Split(' ');
                    List<Tuple<Int64, Int64>> nlist = new List<Tuple<Int64, Int64>>();
                    for (int i = 0; i < N; i++)
                    {
                        Int64 a = Int64.Parse(tmp[i * 2 + 0]);
                        Int64 b = Int64.Parse(tmp[i * 2 + 1]);
                        nlist.Add(Tuple.Create<Int64, Int64>(a, b));
                    }

                    tmp = reader.ReadLine().Split(' ');
                    List<Tuple<Int64, Int64>> mlist = new List<Tuple<Int64, Int64>>();
                    for (int i = 0; i < M; i++)
                    {
                        Int64 a = Int64.Parse(tmp[i * 2 + 0]);
                        Int64 b = Int64.Parse(tmp[i * 2 + 1]);
                        mlist.Add(Tuple.Create<Int64, Int64>(a, b));
                    }

                    Int64 result = calc(nlist, mlist, 0, 0, nlist[0].Item1, mlist[0].Item1);

                    Console.WriteLine("Case #" + (t + 1) + ": " + result);
                }
            }
        }
    }
}
