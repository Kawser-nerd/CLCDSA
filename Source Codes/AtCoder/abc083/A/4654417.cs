using System;
 
class Program
{
    static void Main(string[] args)
    {
        var abcd = Console.ReadLine().Split(' ');
        var a = int.Parse(abcd[0]);
        var b = int.Parse(abcd[1]);
        var c = int.Parse(abcd[2]);
        var d = int.Parse(abcd[3]);
 
        if (a + b > c + d)
        {
            Console.WriteLine("Left");
        }
        else if (a + b < c + d)
        {
            Console.WriteLine("Right");
        }
        else
        {
            Console.WriteLine("Balanced");
        }
    }
}