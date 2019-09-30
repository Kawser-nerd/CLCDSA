using System;

class Atcoder90
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        if (n % 2 == 0)
            Console.WriteLine(n);
        else
            Console.WriteLine(n * 2);
    }
}