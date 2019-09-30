using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJApp
{
    class Program
    {
        static int ret;

        static void Main(string[] args)
        {
            TextWriter tw = new StreamWriter("C:\\myStuff\\GCJ\\Data\\D-small.out");

            TextReader tr = new StreamReader("C:\\myStuff\\GCJ\\Data\\D-small-attempt0.in");

            int N = Int32.Parse(tr.ReadLine());

            int H, W, R;

            int[,] board;

            string s;

            for (int testNo = 1; testNo <= N; testNo++)
            {

                string[] sar = (tr.ReadLine()).Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
                H = int.Parse(sar[0]);
                W = int.Parse(sar[1]);
                R = int.Parse(sar[2]);
                board = new int[H+1,W+1];
                for(int i=1;i<=H;i++) {
                    for(int j=1;j<=W;j++) {
                        board[i,j]=0;
                    }
                }
                board[1,1]=1;
                for (int i = 0; i < R; i++)
                {
                    sar = (tr.ReadLine()).Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int h = int.Parse(sar[0]);
                    int w = int.Parse(sar[1]);
                    board[h, w] = -1;
                }
                int nh,nw,t;
                for (int i = 2; i <= H; i++)
                {
                    for (int j = 2; j <= W; j++)
                    {
                        if (board[i, j] == -1) continue;
                        nh = i - 1;
                        nw = j - 2;
                        t = 0;
                        if (nh >= 1 && nw >= 1)
                        {
                            if (board[nh, nw] > 0)
                                t += board[nh, nw];
                        }
                        nh = i - 2;
                        nw = j - 1;
                        if (nh >= 1 && nw >= 1)
                        {
                            if (board[nh, nw] > 0)
                                t += board[nh, nw];
                        }
                        board[i, j] = t % 10007;
                    }
                }


                ret = board[H,W];

                               
                
                tw.WriteLine("Case #" + (testNo) + ": " + ret);
            }
            tw.Flush();
            tw.Close();
        }

    }
}
