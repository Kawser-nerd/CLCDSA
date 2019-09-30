using System;
class c
{
    static void Main()
    {
        var xy = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        int add = 1;
        if (xy[0] * xy[1] > 0)
        {
            if (Math.Abs(xy[0]) < Math.Abs(xy[1])) add = xy[0] > 0 ? 0 : 2;
            else add = xy[0] > 0 ? 2 : 0;
        }
        else if (xy[0] == 0 && xy[1] > 0 || xy[1] == 0 && xy[0] < 0) add = 0;
        Console.WriteLine(Math.Abs(Math.Abs(xy[0]) - Math.Abs(xy[1])) + add);
    }
}