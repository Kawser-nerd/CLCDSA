using System;
using System.Linq;
class Program{
    static void Main(){
        int[] abc = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        int a = abc[0], b = abc[1], c = abc[2];
        if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
            Console.WriteLine(0);
        else
            Console.WriteLine(Math.Min(Math.Min((long)a * b, (long)b * c), (long)c * a));
    }
}