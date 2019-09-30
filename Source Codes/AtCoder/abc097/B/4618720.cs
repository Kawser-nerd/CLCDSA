using System;

class Program
{
    static void Main(string[] args)
    {
        var n = int.Parse(Console.ReadLine());

        if (n == 1)
        {
            Console.WriteLine(1);
            return;
        }

        var max = 0;
        for (int i = 2; ; i++)
        {
            var any = false;
            for (int j = 2; ; j++)
            {
                var p = (int)Math.Pow(i, j);
                if (p <= n)
                {
                    any = true;
                    max = Math.Max(max, p);
                }
                else
                {
                    break;
                }
            }
            if (!any)
            {
                break;
            }
        }

        Console.WriteLine(max);
    }
}