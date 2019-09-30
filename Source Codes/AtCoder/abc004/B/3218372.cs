using System;

class Program
{
    static void Main(string[] args)
    {
        var input = new[] {
            Console.ReadLine().Split(' '),
            Console.ReadLine().Split(' '),
            Console.ReadLine().Split(' '),
            Console.ReadLine().Split(' ')
        };

        for (var i = 3; i >= 0; i--)
        {
            Console.WriteLine(string.Join(" ", input[i][3], input[i][2], input[i][1], input[i][0]));
        }
    }

}