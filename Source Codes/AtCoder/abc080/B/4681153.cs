using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());
        if (n % f(n) == 0)
        {
            Console.WriteLine("Yes");
        }
        else
        {
            Console.WriteLine("No");
        }
    }

    static int f(int n)
    {
        var ans = 0;
        while (n != 0)
        {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
}