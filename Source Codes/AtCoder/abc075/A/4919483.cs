using System;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
        var output = string.Empty;

        if (input[0] == input[1]) output = input[2].ToString();
        if (input[1] == input[2]) output = input[0].ToString();
        if (input[2] == input[0]) output = input[1].ToString();

        Console.WriteLine("{0}", output);
    }
}