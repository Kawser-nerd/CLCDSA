using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace snap
{
    class B
    {
        public static void Main()
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            string temp = Console.ReadLine();
            string[] t;
            int T = int.Parse(temp);

            bool[] p = new bool[105];
            long[] x = new long[105];
            
            for (int tc = 0; tc < T; tc++)
            {
                temp = Console.ReadLine();
                t = temp.Split(' ');
                int N = int.Parse(t[0]);
                long K = long.Parse(t[1]);
                long B = long.Parse(t[2]);
                long Time = long.Parse(t[3]);

                temp = Console.ReadLine();
                t = temp.Split(' ');
                for (int i = 0; i < N; i++)
                    x[i] = long.Parse(t[i]);

                temp = Console.ReadLine();
                t = temp.Split(' ');
                for (int i = 0; i < N; i++)
                {
                    long v = long.Parse(t[i]);
                    p[i] = (((double)(B - x[i])) / v) <= Time;
                }

                int res = 0;
                
                int c,j,k;
                k = 0;
                for (c = 0; c < K; c++)
                {
                    j = N - 1 - c;
                    {
                        for (k = j; k >= 0 && p[k] == false; k--) ;

                        if (k == -1)
                            break;
                        res += j - k;
                        for (; k < j; k++)
                            p[k] = p[k + 1];
                    }
                    
                }
                if (c == K)
                    Console.WriteLine("Case #{0}: {1}", tc + 1, res);
                else
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", tc + 1);
            }
        }
    }
}
