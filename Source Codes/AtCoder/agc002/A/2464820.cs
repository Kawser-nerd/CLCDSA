using System;
using System.Linq;
class Program{
    static void Main(){
        int[] ab = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int a = ab[0], b = ab[1];
        if (a > 0)
            Console.WriteLine("Positive");
        else if (a <= 0 && b >= 0)
            Console.WriteLine("Zero");
        else if ((b - a + 1) % 2 != 0)
            Console.WriteLine("Negative");
        else
            Console.WriteLine("Positive");
    }
}