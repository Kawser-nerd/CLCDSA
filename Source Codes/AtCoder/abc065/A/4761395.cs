using System;

class Program
{
    static void Main(string[] args)
    {
        var abx = Console.ReadLine().Split(' ');
        var x = int.Parse(abx[0]);
        var a = int.Parse(abx[1]);
        var b = int.Parse(abx[2]);

        if (b <= a)
        {
            Console.WriteLine("delicious");
        }
        else if (b <= a + x)
        {
            Console.WriteLine("safe");
        }
        else
        {
            Console.WriteLine("dangerous");
        }
    }
}