using System;
 
class Program
{
    static void Main(string [] args)
    {
        var n = int.Parse(Console.ReadLine());
        var s = Console.ReadLine();

        if (n % 2 == 0)
        {
            Console.WriteLine("-1");
            return;
        }

        var center = n / 2;
        for (var i = 0; i < n / 2; i++)
        {
            if (i % 3 == 0 && s[center - i] == 'b' && s[center + i] == 'b') continue;
            if (i % 3 == 1 && s[center - i] == 'a' && s[center + i] == 'c') continue;
            if (i % 3 == 2 && s[center - i] == 'c' && s[center + i] == 'a') continue;
            Console.WriteLine("-1");
            return;
        }

        Console.WriteLine(n / 2);
    }
}