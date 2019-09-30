using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        // ?
        int ans = 0;

        // ??
        int[] inp = CSRD.RI(' ');

        // ??
        int n = inp[0];
        int max = inp[1];
        int[] counter = new int[31];

        for (int i = 0; i < n; i++)
        {
            int[] inp2 = CSRD.RI(' ');
            for (int j = 1; j < inp2.Length; j++)
            {
                counter[inp2[j]]++;
            }
        }

        for (int i = 0; i < counter.Length; i++)
        {
            if (counter[i] == n)
            {
                ans++;
            }
        }
        
        //??
        CSWT.WS(ans);
        CSRD.RS();
    }
}

class CSRD
{
    // ???????????
    public static string RS() { return Console.ReadLine(); }
    public static int RI() { return int.Parse(Console.ReadLine()); }
    public static string[] RS(char sep) { return Console.ReadLine().Split(sep); }
    public static int[] RI(char sep) { return Console.ReadLine().Split(sep).Select(x => int.Parse(x)).ToArray(); }
}

class CSWT
{
    public static void WS(object param) { Console.WriteLine(param); }
}