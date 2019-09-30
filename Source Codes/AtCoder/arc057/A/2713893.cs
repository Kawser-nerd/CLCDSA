using System;

public class Hello
{
    public const long targ = 2000000000000;
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var a = long.Parse(line[0]);
        var k = long.Parse(line[1]);
        if (k == 0) { Console.WriteLine(targ - a); goto end; }
        var money = a;
        var count = 0L;
        while (money < targ)
        {
            money += 1 + k * money;
            count++;
        }
        Console.WriteLine(count);
        end:;
    }
}