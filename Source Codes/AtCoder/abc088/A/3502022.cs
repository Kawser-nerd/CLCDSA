using System;

class Atcoder76
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int a = int.Parse(Console.ReadLine());

        int oneyen = n % 500;

        if (oneyen <= a)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}