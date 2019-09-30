using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class A
{
    public static void Main(string[] args)
    {
        string[] order = { "ZERO", "SIX", "TWO", "EIGHT", "FOUR", "ONE", "THREE", "FIVE", "SEVEN", "NINE" };
        int[] digs = { 0, 6, 2, 8, 4, 1, 3, 5, 7, 9 };
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);

            string S = Console.ReadLine();
            int[] count = new int[120];
            for(int i = 0; i < S.Length; i++)
            {
                count[S[i]]++;
            }

            List<int> ans = new List<int>();

            for(int i = 0; i < order.Length; i++)
            {
                bool haveall = true;
                for(int j = 0; j < order[i].Length; j++)
                    if (count[order[i][j]] == 0) haveall = false;
                if(haveall)
                {
                    ans.Add(digs[i]);
                    for (int j = 0; j < order[i].Length; j++)
                        count[order[i][j]]--;
                    i--;
                }
            }

            ans.Sort();
            Console.Write("Case #" + CASE + ": ");
            foreach (int i in ans) Console.Write(i);
            Console.WriteLine();
        }
    }
}
