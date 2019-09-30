using System;

class Program
{
    static void Main(string[] args)
    {
        var ab = Console.ReadLine().Split(' ');
        var a = int.Parse(ab[0]);
        var b = int.Parse(ab[1]);

        var s = Console.ReadLine();
        for (int i = 0; i <= a + b; i++)
        {
            if (i == a)
            {
                if (s[i] != '-')
                {
                    Console.WriteLine("No");
                    return;
                }
            }
            else
            {
                if ('0' > s[i] || s[i] > '9')
                {
                    Console.WriteLine("No");
                    return;
                }
            }
        }

        Console.WriteLine("Yes");
    }
}