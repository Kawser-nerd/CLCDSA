using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJApp
{
    class Program
    {
        

        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\myStuff\\GCJ\\Data\\C-small.out");

            TextReader tr = new StreamReader("C:\\myStuff\\GCJ\\Data\\C-small-attempt0.in");

            int N = Int32.Parse(tr.ReadLine());

            long n,m,X,Y,Z;

            long[] boards;
            long[] ret;
            long[] A;

            long mod = 1000000007L;

            for (int i = 1; i <= N; i++)
            {

                string[] tar = tr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                n = long.Parse(tar[0]);
                m = long.Parse(tar[1]);
                X = long.Parse(tar[2]);
                Y = long.Parse(tar[3]);
                Z = long.Parse(tar[4]);
                
                A = new long[m];
                for(int j = 0;j<m;j++) {
                    A[j] = long.Parse(tr.ReadLine());
                }

                boards = new long[n];
               // dp = new long[K,L];
                for (int j = 0; j < n; j++)
                {
                    boards[j] = A[j % m];
                    A[j%m]=(X * A[j % m] + Y * (j + 1)) % Z;
                    
                }

                ret = new long[n];
                ret[0] = 1;
                long fret=1;
                for (int j = 1; j < n; j++)
                {
                    ret[j] = 1;
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (boards[k] < boards[j])
                        {
                            ret[j] += ret[k];
                            ret[j] = ret[j] % mod;
                        }
                    }
                    fret += ret[j];
                    fret = fret % mod;
                }

                
                
                tw.WriteLine("Case #" + (i) + ": " + fret%mod);
                //tw.WriteLine("Case #" + (i) + ": " + r2);
            }
            tw.Flush();
            tw.Close();

        }


    }
}
