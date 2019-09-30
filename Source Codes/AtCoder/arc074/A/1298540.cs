using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

class Program
{
    uint maximum(uint a, uint b)
    {
        return a > b ? a : b;
    }
    uint maximum(uint a, uint b, uint c)
    {
        return maximum(a, maximum(b, c));
    }
    uint minimum(uint a, uint b)
    {
        return a < b ? a : b;
    }
    uint minimum(uint a, uint b, uint c)
    {
        return minimum(a, minimum(b, c));
    }
    void solve()
    {
        string[] buf = Console.ReadLine().Split(' ');
        uint H = uint.Parse(buf[0]);
        uint W = uint.Parse(buf[1]);
        uint answer = uint.MaxValue;

        //if (H > W)
        //{
        //    uint temp = H;
        //    H = W;
        //    W = temp;
        //}

        if (H % 3 == 0 || W % 3 == 0)
        {
            answer = 0;
        }

        if (answer == uint.MaxValue)
        {
            for (int i = 0; i < 2; ++i)
            {
                uint A = 0, B1 = 0, B2 = 0, diff1 = 0;
                for (uint w = W / 3 <= 3 ? 1 : W / 3 - 3; w < W / 3 + 3; ++w)
                {
                    A = H * w;
                    if ((W - w) % 2 == 0)
                    {
                        B1 = B2 = H * ((W - w) / 2);
                    }
                    else if (H % 2 == 0)
                    {
                        B1 = B2 = (H / 2) * (W - w);
                    }
                    else if (W - w < H)
                    {
                        B1 = (H / 2 + 1) * (W - w);
                        B2 = (H / 2) * (W - w);
                    }
                    else
                    {
                        B1 = H * ((W - w) / 2 + 1);
                        B2 = H * ((W - w) / 2);
                    }
                    diff1 = maximum(A, B1, B2) - minimum(A, B1, B2);
                    if (diff1 < answer) answer = diff1;
                }
                {
                    uint temp = H;
                    H = W;
                    W = temp;
                }
            }
        }

        Console.WriteLine(answer);
    }

    public static int Main()
    {
        bool loop = false;
#if ES_DEBUG
        loop = true;
#endif
        do
        {
            new Program().solve();
        } while (loop);
        return 0;
    }
}