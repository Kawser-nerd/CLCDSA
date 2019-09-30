using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2017.RQ
{
    public class P3 : CommonClass
    {
        long N, K;

        public P3(StreamReader fileIn, StreamWriter fileOut) : base(fileIn, fileOut)
        {
        }

        public void ReadData()
        {
            long[] a = ReadLongArray();
            N = a[0];
            K = a[1];
        }

        public string Format(long k)
        {
            return (k - 1 - (k - 1) / 2) + " " + ((k - 1) / 2);
        }

        public string Process()
        {
            long[] n = new long[70];
            long[] a = new long[70];
            long[] b = new long[70];

            int run = 0;
            n[run] = N;
            a[run] = 1;
            b[run] = 0;
            run++;
            while (true)
            {
                n[run] = (n[run - 1] - 1) / 2;
                a[run] = 0;
                b[run] = 0;

                a[run] = a[run - 1];
                if ((n[run - 1] - 1 - (n[run - 1] - 1) / 2) == n[run])
                {
                    a[run] += a[run - 1];
                }
                else
                {
                    b[run] += a[run - 1];
                }

                if (((n[run - 1]) / 2) == n[run])
                {
                    a[run] += b[run - 1];
                }
                else
                {
                    b[run] += b[run - 1];
                }

                if (n[run - 1] - ((n[run - 1]) / 2) == n[run])
                {
                    a[run] += b[run - 1];
                }
                else
                {
                    b[run] += b[run - 1];
                }

                if (n[run] == 0)
                {
                    run++;
                    break;
                }
                run++;
            }

            for (int i = 0; i < run; i++)
            {
                if( K > b[i])
                {
                    K -= b[i];
                }
                else
                {
                    return Format(n[i] + 1);
                }

                if (K > a[i])
                {
                    K -= a[i];
                }
                else
                {
                    return Format(n[i]);
                }
            }

            return "";
        }
    }
}
