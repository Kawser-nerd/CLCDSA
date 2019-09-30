using System;

class Program
{
    static void Main(string[] args)
    {
        var N = int.Parse(Console.ReadLine());
        var s = Console.ReadLine().Split(' ');
        var ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans += m1(int.Parse(s[i]));
        }
        Console.WriteLine(ans);
    }

    static int m1(int n)
    {
        var ans = 0;
        while (n % 2 == 0)
        {
            ans++;
            n /= 2;
        }
        return ans;
    }
}