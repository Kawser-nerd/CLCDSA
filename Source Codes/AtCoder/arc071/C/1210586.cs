#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
// Do not use: System.Numerics;

public class Test
{
    public static void Main()
    {
        var S = Console.ReadLine();
        var T = Console.ReadLine();
        var n = Int32.Parse(Console.ReadLine());

        var SA = new int[S.Length + 1];  // S?i-1?????????A????
        var SB = new int[S.Length + 1];
        var TA = new int[T.Length + 1];
        var TB = new int[T.Length + 1];

        int a = 0;
        int b = 0;
        for (int i = 0; i < S.Length; i++)
        {
            if (S[i] == 'A')
            {
                a++;
            }
            else
            {
                b++;
            }
            SA[i + 1] = a;
            SB[i + 1] = b;
        }

        a = 0;
        b = 0;
        for (int i = 0; i < T.Length; i++)
        {
            if (T[i] == 'A')
            {
                a++;
            }
            else
            {
                b++;
            }
            TA[i + 1] = a;
            TB[i + 1] = b;
        }

        for (int i = 0; i < n; i++)
        {
            var line1 = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();

            int SACount = SA[line1[1]] - SA[line1[0] - 1];
            int SBCount = SB[line1[1]] - SB[line1[0] - 1];
            int TACount = TA[line1[3]] - TA[line1[2] - 1];
            int TBCount = TB[line1[3]] - TB[line1[2] - 1];

            int diff = (SACount - SBCount) - (TACount - TBCount);

            if (diff % 3 == 0)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }
        }
    }
}