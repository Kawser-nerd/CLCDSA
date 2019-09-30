using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] xyr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] xyxy = Console.ReadLine().Split().Select(int.Parse).ToArray();

        if(xyr[0] + xyr[2] <= xyxy[2] && xyr[0] - xyr[2] >= xyxy[0] && xyr[1] + xyr[2] <= xyxy[3] && xyr[1] - xyr[2] >= xyxy[1])
        {
            Console.WriteLine("NO");
        }
        else
        {
            Console.WriteLine("YES");
        }
        int a = Math.Max(Math.Abs(xyxy[0] - xyr[0]), Math.Abs(xyxy[2] - xyr[0]));
        int b = Math.Max(Math.Abs(xyxy[1] - xyr[1]), Math.Abs(xyxy[3] - xyr[1]));
        if (Math.Sqrt(a * a + b * b) <= xyr[2])
        {
            Console.WriteLine("NO");
        }
        else
        {
            Console.WriteLine("YES");
        }
    }
}