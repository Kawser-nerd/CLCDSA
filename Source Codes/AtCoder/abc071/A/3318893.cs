using System;

class Atcoder59
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int x = int.Parse(input[0]);
        int a = int.Parse(input[1]);
        int b = int.Parse(input[2]);

        int da = Math.Abs(x - a);
        int db = Math.Abs(x - b);

        if (da > db)
            Console.WriteLine("B");
        else
            Console.WriteLine("A");
    }
}