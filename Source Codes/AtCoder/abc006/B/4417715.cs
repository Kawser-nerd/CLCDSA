using System;

class Atcoder113
{
    public static void Main()
    {
        int i;
        int[] TRI = new int[1000000];

        TRI[0] = 0;
        TRI[1] = 0;
        TRI[2] = 1;

        for (i = 3; i < 1000000; i++)
        {
            TRI[i] = (TRI[i - 3] + TRI[i - 2] + TRI[i - 1]) % 10007;
        }

        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(TRI[n - 1]);
    }
}