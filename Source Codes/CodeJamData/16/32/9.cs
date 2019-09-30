using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter w = new StreamWriter(@"output-large.txt"))
            {
                using (StreamReader r = new StreamReader(@"B-large.in"))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 0; i < t; i++)
                    {
                        string[] bm = r.ReadLine().Split(' ');
                        int b = int.Parse(bm[0]);
                        long m = long.Parse(bm[1]);
                        if((long)Math.Pow(2,b-2)>=m)//ikeru
                        {
                            w.WriteLine("Case #{0}: {1}", i + 1, "POSSIBLE");
                            string btob = Convert.ToString(m, 2).PadLeft(b,'0');

                            string[] ans = new string[b];
                            for (int j = 0; j < b; j++)
                            {
                                StringBuilder sb = new StringBuilder();
                                for (int k = 0; k < j + 1; k++)
                                {
                                    sb.Append("0");
                                }
                                for (int k = j + 1; k < b - 1; k++)
                                {
                                    sb.Append("1");
                                }
                                if(j!=b-1)
                                {
                                    //sb.Append(btob[b - j - 1]);
                                }
                                ans[j] = sb.ToString();
                                //w.WriteLine(ans[j]);
                            }
                            long cnt = m;
                            for (int j = b - 2; j >= 0; j--)
                            {
                                long next = (long)Math.Pow(2, Math.Max(0, j - 1));
                                if (next <= cnt)
                                {
                                    ans[j] += "1";
                                    cnt -= next;
                                }
                                else
                                {
                                    ans[j] += "0";
                                }
                            }
                            for (int j = 0; j < b; j++)
                            {
                                w.WriteLine(ans[j]);
                            }
                        }
                        else//muri
                        {
                            w.WriteLine("Case #{0}: {1}", i + 1, "IMPOSSIBLE");
                        }                        
                    }
                }
            }
        }
    }
}
