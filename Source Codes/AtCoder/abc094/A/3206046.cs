using System;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split(' ');
        var cat = Convert.ToInt32(input[0]);
        var other = Convert.ToInt32(input[1]);
        var will = Convert.ToInt32(input[2]);

        if (cat <= will&&will <= cat + other) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
}