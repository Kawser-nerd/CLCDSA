using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        var d = new int[n];
        var s = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            d[i] = int.Parse(s[i]);
        }

        var max_i = 0;
        var sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += d[i];
            if (d[max_i] < d[i])
            {
                max_i = i;
            }
        }

        if (d[max_i] < sum - d[max_i]) Console.WriteLine("Yes");
        else Console.WriteLine("No");
    }
}