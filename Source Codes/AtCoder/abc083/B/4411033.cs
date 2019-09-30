using System;

public class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[1]);
        int b = int.Parse(input[2]);
        int n = int.Parse(input[0]);

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            int sum = 0;
            while (j > 0)
            {
                sum += j % 10;
                j /= 10;
            }

            if (a <= sum && sum <= b)
                res += i;
        }

        Console.WriteLine(res);
    }
}