using System;

public class Program
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var nums = 0;
        for (int i = 1; i <= n; i += 2)
        {
            var count = 0;
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0)
                {
                    count++;
                }
            }

            if (count == 8)
            {
                nums++;
            }
        }

        Console.WriteLine(nums);
    }
}