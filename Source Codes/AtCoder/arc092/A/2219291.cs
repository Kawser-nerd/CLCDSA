using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[][] red = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).OrderBy(x => x[0]).ToArray();
        int[][] blue = Enumerable.Repeat(0, n).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).OrderBy(x => x[0]).ToArray();
        //R,B???2????????
        //???????????????????
        //??x???????????
        //x??????????????y??????????
        //x?????y????????

        //???2???????????
        //
        bool[] redIsUsed = new bool[red.Length];
        bool[] blueIsUsed = new bool[blue.Length];
        for (int i = 0; i < blue.Length; i++)
        {
            int[] minblue = blue[i];
            int maxRedy = -1;
            int minRedInd = -1;
            for (int j = 0; j < red.Length; j++)
            {
                if (!redIsUsed[j] && red[j][0] < minblue[0] && red[j][1] < minblue[1] && maxRedy < red[j][1])
                {
                    maxRedy = red[j][1];
                    minRedInd = j;
                }   
            }
            if (minRedInd != -1)
            {
                blueIsUsed[i] = true;
                redIsUsed[minRedInd] = true;
            }
        }
        Console.WriteLine(redIsUsed.Count(x => x));
    }
}