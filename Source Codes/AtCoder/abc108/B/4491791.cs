using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        string[] input = Console.ReadLine().Split(' ');
        int x1 = int.Parse(input[0]);
        int y1 = int.Parse(input[1]);
        int x2 = int.Parse(input[2]);
        int y2 = int.Parse(input[3]);

        int x3, y3, x4, y4;

        // 1????
        // int length = (int)Math.Sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        // ???????????????4??????

        x3 = x2 + (y1 - y2);
        y3 = y2 + (x2 - x1);

        x4 = x1 + (y1 - y2);
        y4 = y1 + (x2 - x1);

        Console.WriteLine(x3 + " " + y3 + " " + x4 + " " + y4);
       
    }

}