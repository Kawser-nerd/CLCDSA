using System;

class Program
{
    static public void Main(string[] args)
    {
        string input = Console.ReadLine().Replace(" ", "");
        double num = int.Parse(input);

        num = Math.Sqrt(num);

        if (num == (int)num)
            Console.WriteLine("Yes");
        else
            Console.WriteLine("No");
    }
}