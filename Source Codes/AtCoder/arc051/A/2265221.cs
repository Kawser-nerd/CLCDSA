using System;
using System.Linq;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int[] xyr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[] xyxy = Console.ReadLine().Split().Select(int.Parse).ToArray();

        if (new int[] { xyr[0] - xyxy[0], xyxy[2] - xyr[0], xyr[1] - xyxy[1], xyxy[3] - xyr[1] }.Min() < xyr[2])
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }

        if (Math.Max(Math.Max(
            Math.Sqrt((xyxy[0] - xyr[0]) * (xyxy[0] - xyr[0]) + (xyxy[1] - xyr[1]) * (xyxy[1] - xyr[1])),
            Math.Sqrt((xyxy[2] - xyr[0]) * (xyxy[2] - xyr[0]) + (xyxy[1] - xyr[1]) * (xyxy[1] - xyr[1]))),
            Math.Max(
            Math.Sqrt((xyxy[0] - xyr[0]) * (xyxy[0] - xyr[0]) + (xyxy[3] - xyr[1]) * (xyxy[3] - xyr[1])),
            Math.Sqrt((xyxy[2] - xyr[0]) * (xyxy[2] - xyr[0]) + (xyxy[3] - xyr[1]) * (xyxy[3] - xyr[1])))) > xyr[2])
        {
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
    }
}