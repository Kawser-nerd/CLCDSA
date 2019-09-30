using System;

public class AtCoder
{
    public static void Main()
    {
        int[] p = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
        int n;
        n = int.Parse(Console.ReadLine().Trim());
        int[] q = new int[25];
        int d;
        int[] x = new int[5];
        int[] div = { 2, 4, 14, 24, 74 };
        for (int i = 1; i <= n; i++)
        {
            d = i;
            for (int j = 0; j < 25; j++)
            {
                while (d % p[j] == 0)
                {
                    d /= p[j];
                    q[j]++;
                }
            }
        }
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (q[i] >= div[j]) x[j]++;
            }        
        }

        int ans = 0;
        ans += (x[0]-2) * x[1] * (x[1]-1)/2;
        ans += (x[0]-1) * x[3];
        ans += (x[1]-1) * x[2];
        ans += x[4];
        Console.WriteLine(ans);
    }
}