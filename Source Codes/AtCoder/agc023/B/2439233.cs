using System;
class Program
{
    static int n;
    static char[][] s;
    static bool Check(int a, int b)
    {
        bool f = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f = f && s[Mod(i + a - 1)][Mod(j + b - 1)] == s[Mod(j + a - 1)][Mod(i + b - 1)];
        return f;
    }
    static int Mod(int m) { return m % n; }
    static void Main()
    {
        n = int.Parse(Console.ReadLine());
        s = new char[n][];
        for (int i = 0; i < n; i++)
            s[i] = Console.ReadLine().ToCharArray();
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (Check(0, i))
                ans++;
        Console.WriteLine(ans * n);
    }
}