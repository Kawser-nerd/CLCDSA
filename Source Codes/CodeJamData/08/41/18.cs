using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace BoolTree
{
    class Program
    {

        static int[] Value;
        static bool[] Ch;
        static System.Collections.Hashtable HT;

        static int MC(int p, int req)
        {
            int qq = p * 2 + req;
            if (HT.Contains(qq))
                return (int)HT[qq];
            if (Value[p] < 2)
            {
                if (Value[p] == req)
                    return 0;
                return int.MaxValue;
            }
            int minA = int.MaxValue;
            if (Value[p] == 2||Ch[p])
            {
                if (req == 1)
                {
                    int a = MC(p * 2, 1);
                    int b = MC(p * 2 + 1, 1);
                    if (a != int.MaxValue && b != int.MaxValue)
                        minA = Math.Min(minA, a + b);
                }
                if (req == 0)
                {
                    int a = MC(p * 2, 0);
                    int b = MC(p * 2 + 1, 1);
                    if (a != int.MaxValue && b != int.MaxValue)
                        minA = Math.Min(minA, a + b);
                    b = MC(p * 2 + 1, 0);
                    if (a != int.MaxValue && b != int.MaxValue)
                        minA = Math.Min(minA, a + b);
                    a = MC(p * 2, 1);
                    if (a != int.MaxValue && b != int.MaxValue)
                        minA = Math.Min(minA, a + b);
                }
            }
            int minO = int.MaxValue;
            if (Value[p] == 3||Ch[p])
            {
                if (req == 1)
                {
                    int a = MC(p * 2, 1);
                    int b = MC(p * 2 + 1, 1);
                        minO = Math.Min(minO,Math.Min(a,b));
                }
                if (req == 0)
                {
                    int a = MC(p * 2, 0);
                    int b = MC(p * 2 + 1, 0);
                    if (a != int.MaxValue && b != int.MaxValue)
                        minO = Math.Min(minO, a + b);
                }
            }
            int r = int.MaxValue;
            if (!Ch[p])
                r = Math.Min(minO, minA);
            else
            {
                if (Value[p] == 2)
                    r = Math.Min(minA, minO == int.MaxValue ? int.MaxValue : minO + 1);
                else
                    r = Math.Min(minO, minA == int.MaxValue ? int.MaxValue : minA + 1);
            }
            HT.Add(qq, r);
            return r;
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D:\\in.txt");
            StreamWriter sw = new StreamWriter("D:\\out.txt");
            int vv = int.Parse(sr.ReadLine());
            for (int w = 0; w < vv; )
            {
                w++;
                HT = new System.Collections.Hashtable();
                string[] t = sr.ReadLine().Split(' ');
                int M = int.Parse(t[0]);
                int Req = int.Parse(t[1]);
                Value = new int[M + 1];
                Ch = new bool[M + 1];
                for (int i = 0; i < M/2; i++)
                {
                    t = sr.ReadLine().Split(' ');
                    Value[i+1] = t[0] == "1" ? 2 : 3;
                    Ch[i+1] = t[1] == "1";
                }
                for (int i = 0; i < (M+1)/2; i++)
                {
                    Value[i+M/2+1] = sr.ReadLine() == "1" ? 1 : 0;
                    Ch[i + M / 2+1] = false;
                }
                int r = MC(1, Req);
                
                string outs = "Case #" + w.ToString() + ": ";
                sw.WriteLine(outs + (r != int.MaxValue ? r.ToString() : "IMPOSSIBLE"));
            }
            sr.Close();
            sw.Close();
        }
    }
}
