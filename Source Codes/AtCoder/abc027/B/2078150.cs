using System;
class Program
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] a = new int[n];
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = int.Parse(str[i]);
            total += a[i];
        }
        if (total % n != 0)
        {
            Console.WriteLine(-1);
        }
        else
        {
            int m = total / n;
            int count = 0, sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i];
                if (sum == m * (i + 1))
                    count++;
            }
            Console.WriteLine(n - count);
        }
    }
}