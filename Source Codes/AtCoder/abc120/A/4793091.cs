using System;

class Atcoder114
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        int sound = b / a;

        if (sound < c)
            Console.WriteLine(sound);
        else
            Console.WriteLine(c);
    }
}