using System;
class c
{
    static void Main()
    {
        int k = int.Parse(Console.ReadLine());
        int o = 0, e = 0;
        for (int i = 1; i <= k; i++)
        {
            if (i % 2 == 0) e++;
            else o++;
        }
        Console.WriteLine(e * o);
    }
}