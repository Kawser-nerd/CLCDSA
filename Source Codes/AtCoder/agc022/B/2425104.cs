using System;
using System.Collections;
class Program
{
    static int Mul2(int k)
    {
        return 2 * k;
    }
    static int Mul3(int k)
    {
        return 3 + 6 * (k - 1);
    }
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        if (n == 3)
        {
            Console.WriteLine("2 5 63");
            Environment.Exit(0);
        }
        ArrayList ans = new ArrayList();
        int num2 = 1;
        int num3 = n - num2;
        while (num2 % 3 == 1 || num3 % 2 == 1 || num2 > 15000 || num3 > 5000)
        {
            num3--;
            num2++;
        }
        for (int i = 1; i <= num2; i++)
            ans.Add(Mul2(i));
        for (int i = 1; i <= num3; i++)
            ans.Add(Mul3(i));
        for (int i = 0; i < n - 1; i++)
            Console.Write("{0} ", ans[i]);
        Console.WriteLine(ans[n - 1]);
    }
}