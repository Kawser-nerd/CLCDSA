using System;

class Atcoder48
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int starttime = a + b;

        if (starttime > 23)
            Console.WriteLine(starttime - 24);
        else
            Console.WriteLine(starttime);
    }
}