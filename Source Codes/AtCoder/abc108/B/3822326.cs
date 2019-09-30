using System;
using System.Collections.Generic;
using System.Linq;
class Program{
    static void Main(){
        //???????
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int x1,y1,x2,y2;
        x1 = input[0];
        y1 = input[1];
        x2 = input[2];
        y2 = input[3];
        /* (x3,y3)???
            (x3,y3) = (x2,y2) + (-(y2 - y1),x2 - x1)
        */
        int x3 = x2 - (y2 - y1);
        int y3 = y2 + (x2 - x1);
        /* (x4,y4)???
            (x4,y4) = (x1,y1) + (-(y2 - y1),x2 - x1)
        */
        int x4 = x1 - (y2 - y1);
        int y4 = y1 + (x2 - x1);
        //?????
        Console.WriteLine("{0} {1} {2} {3}",x3,y3,x4,y4);
    }
}