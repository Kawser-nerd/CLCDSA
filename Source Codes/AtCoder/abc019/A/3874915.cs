using System;
using System.Linq;

class Program{
    static void Main(){
        var input = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();

        input.Sort();

        Console.WriteLine(input[1]);
    }
}