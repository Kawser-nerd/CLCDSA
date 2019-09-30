using System.Linq;
using System;

class Program
{
    static void Main()
    {
        var N = int.Parse(Console.ReadLine());
        var NG = new int[3];
        NG[0] = int.Parse(Console.ReadLine());
        NG[1] = int.Parse(Console.ReadLine());
        NG[2] = int.Parse(Console.ReadLine());

        if (NG.Contains(N))
        {
            Console.WriteLine("NO");
            return;
        }
        
        for (int i = 0; i < 100; i++)
        {
            if (NG.Any(x => N - 3 == x))
            {
                if (NG.Any(x => N - 2 == x))
                {
                    if (NG.Any(x => N - 1 == x))
                    {
                        Console.WriteLine("NO");
                        return;
                    }
                    else
                    {
                        N -= 1;
                    }
                }
                else
                {
                    N -= 2;
                }
            }
            else
            {
                N -= 3;
            }
        }

        Console.WriteLine(N > 0 ? "NO" : "YES");
    }
}