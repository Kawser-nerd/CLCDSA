using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var attack = Convert.ToInt32(input[0]);
        var def = Convert.ToInt32(input[1]);

        if (attack <= def) attack++;
        else def++;
        Console.WriteLine(attack * def);
    }
}