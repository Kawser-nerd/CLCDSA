using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

public class Magatro
{
    private string S, T;
    private int Q;
    public void Solve()
    {
        S = Console.ReadLine();
        T = Console.ReadLine();
        int[] sArr = new int[S.Length + 1];
        for (int i = 1; i <= S.Length; i++)
        {
            sArr[i] = sArr[i - 1];
            sArr[i] += S[i-1] == 'A' ? 1 : 2;
        }
        int[] tArr = new int[T.Length + 1];
        for (int i = 1; i <= T.Length; i++)
        {
            tArr[i] = tArr[i - 1];
            tArr[i] += T[i-1] == 'A' ? 1 : 2;
        }
        Q = int.Parse(Console.ReadLine());
        for(int i = 0; i < Q; i++)
        {
            string[] s = Console.ReadLine().Split(' ');
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            int c = int.Parse(s[2]);
            int d = int.Parse(s[3]);
            if ((sArr[b] - sArr[a - 1]) % 3 == (tArr[d] - tArr[c - 1]) % 3)
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