using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJApp
{
    class Program
    {
        static int ret;
        static int[,] memo;
        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\myStuff\\GCJ\\Data\\C-small.out");

            TextReader tr = new StreamReader("C:\\myStuff\\GCJ\\Data\\C-small-attempt0.in");

            int C = Int32.Parse(tr.ReadLine());

            int M,N;

            string[] room;

            for (int testNo = 1; testNo <= C; testNo++)
            {

                string[] sar = (tr.ReadLine()).Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
                M = int.Parse(sar[0]);
                N = int.Parse(sar[1]);

                room = new string[M];
                for(int i=0;i<M;i++) {
                    room[i] = tr.ReadLine();                    
                }

                int[] ar = new int[N];
                memo = new int[1 << M, N];
                for (int i = 0; i < N; i++)
                {
                    int t = 0;
                    for (int j = 0; j < M; j++)
                    {
                        if (room[j][i] == 'x')
                            t = (t | (1 << j));
                    }
                    ar[i] = t;
                }

                ret = solve(ar, 0,M);
                
                
                tw.WriteLine("Case #" + (testNo) + ": " + ret);
            }
            tw.Flush();
            tw.Close();
        }

        private static int solve(int[] ar, int p, int M)
        {

            if(p==ar.Length-1) {
                return cnt(ar[p]^((1<<M)-1));
            }
            if (memo[ar[p], p] > 0)
                return memo[ar[p], p];
            int nextbackup = ar[p+1];
            int t = ar[p];
            int best = 0;
            int tt,next;
            for(;t<(1<<M);) {
                tt = t^ar[p];
                next=nextbackup;
                for(int j=0;j<M;j++) {
                    if((tt&(1<<j))>0) {
                        if(j==0)
                            next = (next|((1<<j)|(1<<(j+1))));
                        else
                            next = (next|((1<<j)|(1<<(j+1))|(1<<(j-1))));
                    }
                }
                next = next&((1<<M)-1);
                ar[p+1]=next;
                best = Math.Max(best,cnt(t^ar[p])+solve(ar,p+1,M));
                t++;
                t = t|ar[p];
            }
            ar[p+1] = nextbackup;
            memo[ar[p], p] = best;
            return best;

        }

        private static int cnt(int p)
        {
            int ret = 0;
            for (int i = 0; i < 16; i++)
                if ((p & (1 << i)) > 0)
                    ret++;
            return ret;
        }


    }

}
