using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Numerics;

class p
{

    static int ConvertChar(char ch)
    {
        if (ch == 'A') return 1;
        else return 2;
    }
    

    static void Main(string[] args)
    {
        //????????
        string S = Console.ReadLine();
        string T = Console.ReadLine();
        int q = int.Parse(Console.ReadLine());

        int[] SiSum = new int[S.Length];
        int[] TiSum = new int[T.Length];

        SiSum[0] = ConvertChar(S[0]);
        for (int i = 1; i < S.Length; i++)
        {
            SiSum[i] = SiSum[i - 1] + ConvertChar(S[i]);
        }

        TiSum[0] = ConvertChar(T[0]);
        for (int i = 1; i < T.Length; i++)
        {
            TiSum[i] = TiSum[i - 1] + ConvertChar(T[i]);
        }


        for (int i = 0; i < q; i++)
        {
            int Svalue = 0;
            int Tvalue = 0;
            string[] inputs = Console.ReadLine().Split();
            int SSindex = int.Parse(inputs[0]) - 1;
            int SEindex = int.Parse(inputs[1]) - 1;
            int TSindex = int.Parse(inputs[2]) - 1;
            int TEindex = int.Parse(inputs[3]) - 1;

            if (SSindex == 0) Svalue = SiSum[SEindex];
            else Svalue = SiSum[SEindex] - SiSum[SSindex - 1];
            Svalue %= 3;

            if (TSindex == 0) Tvalue = TiSum[TEindex];
            else Tvalue = TiSum[TEindex] - TiSum[TSindex - 1];
            Tvalue %= 3;

            if (Svalue == Tvalue) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }   
}