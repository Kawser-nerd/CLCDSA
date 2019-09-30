using System;

class Atcoder31
{
    public static void Main()
    {
        string[] input = Console.ReadLine().Split(' ');
        int a = int.Parse(input[0]);
        int b = int.Parse(input[1]);
        int c = int.Parse(input[2]);

        if (a < b)
        {
            int dif = c % a;
            Console.WriteLine((c - dif) / a);
        }
        else {
            int dif = c % b;
            Console.WriteLine((c - dif) / b);
        }
    }
}