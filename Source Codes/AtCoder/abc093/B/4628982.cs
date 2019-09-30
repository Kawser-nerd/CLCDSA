using System;

class Program
{
    static void Main(string[] args)
    {
        var abk = Console.ReadLine().Split(' ');
        var a = int.Parse(abk[0]);
        var b = int.Parse(abk[1]);
        var k = int.Parse(abk[2]);

        for (int i = a; i <= b; i++)
        {
            if (i - a < k || b - i < k)
                Console.WriteLine(i);
        }
    }
}