using System;

class Program
{
    static void Main (string[] args)
    {
        var input1 = Console.ReadLine().Split(' ');
        var input2 = Console.ReadLine().Split(' ');

        var x1 = int.Parse(input1[0]);
        var y1 = int.Parse(input1[1]);
        var r = int.Parse(input1[2]);

        var x2 = int.Parse(input2[0]);
        var y2 = int.Parse(input2[1]);
        var x3 = int.Parse(input2[2]);
        var y3 = int.Parse(input2[3]);

        if ((x1 - r) >= x2 &&
            (x1 + r) <= x3 &&
            (y1 - r) >= y2 &&
            (y1 + r) <= y3)
        {
            Console.WriteLine("NO");
        }
        else
        {
            Console.WriteLine("YES");
        }

        if (Math.Sqrt(Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y2, 2)) <= r &&
            Math.Sqrt(Math.Pow(x1 - x3, 2) + Math.Pow(y1 - y2, 2)) <= r &&
            Math.Sqrt(Math.Pow(x1 - x3, 2) + Math.Pow(y1 - y3, 2)) <= r &&
            Math.Sqrt(Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y3, 2)) <= r
            )
        {
            Console.WriteLine("NO");
        }
        else
        {
            Console.WriteLine("YES");
        }
    }

}