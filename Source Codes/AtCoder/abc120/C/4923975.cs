using System;
class Program
{
    static void Main(string[] args)
    {
        string input = Console.ReadLine();
        int c0 = 0;
        int c1 = 0;
        for(int i = 0; i < input.Length; i++)
        {
            if (input[i] == '0')
                c0++;
            else
                c1++;
        }
        Console.WriteLine(Math.Min(c0, c1) * 2);
    }
}