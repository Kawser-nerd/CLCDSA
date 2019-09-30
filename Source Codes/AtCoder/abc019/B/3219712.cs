using System;

class Program
{
    static void Main(string[] args)
    {
        var str = Console.ReadLine();
        var counter = 0;
        var result = "";
        for(var i = 0; i < str.Length; i++)
        {
            if (i == 0) { counter++;continue; }
            if (str.Substring(i - 1, 1) == str.Substring(i, 1)) counter++;
            else
            {
                result += str.Substring(i - 1, 1) + counter;
                counter = 1;
            }
            if (i == str.Length - 1) result += str.Substring(i, 1) + counter;
        }

        Console.WriteLine(result);
    }
}