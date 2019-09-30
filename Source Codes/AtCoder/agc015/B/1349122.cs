using System.Linq;
using System;
class Program
{
    protected static long InputNumber() { return long.Parse(Console.ReadLine()); }
    protected static string InputString() { return Console.ReadLine(); }
    protected static long[] InputNumbers() { return Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray(); }
    protected static string[] InputStrings() { return Console.ReadLine().Split(' '); }

    static void Main()
    {
        var S = InputString();
        var N = S.Length;
        long ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'D')
            {
                ans += (N - 1 - i) * 2 + i;
            }
            else
            {
                ans += (N - 1 - i) + i * 2;
            }
        }
        /*
        long ans = N * (N - 1);
        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'D')
            {
                ans += N - 1 - i;
            }
            else
            {
                ans += i;
            }
        }*/
        Console.WriteLine(ans);
    }
}