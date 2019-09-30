using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var abq = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        var A = abq[0];
        var B = abq[1];
        var C = abq[2];
        var shrineArray = new long[A];
        var templeArray = new long[B];
        for (int i=0;i<A+B+C;++i)
        {
            if (i < A + B)
            {
                if (i < A) shrineArray[i] = Int64.Parse(Console.ReadLine());
                else templeArray[i-A] = Int64.Parse(Console.ReadLine());
            }
            else
            {
                var startPlace = Int64.Parse(Console.ReadLine());
                var shrineFirstIndex = GetFirstIndex(shrineArray,startPlace);
                var templeFirstIndex = GetFirstIndex(templeArray, startPlace);
                var ans = long.MaxValue;
                for (int j=0;j<2;++j)
                {
                    if (shrineArray.Length <= 1 && j == 1) continue;

                    for (int k=0;k<2;++k)
                    {
                        if (templeArray.Length <= 1 && k == 1) continue;

                        //??
                        var distance = Math.Abs(shrineArray[j + shrineFirstIndex] - templeArray[k + templeFirstIndex]);
                        //????????????
                        var fast = Math.Min(Math.Abs(startPlace- shrineArray[j + shrineFirstIndex]), Math.Abs(startPlace - templeArray[k + templeFirstIndex]));
                        distance += fast;
                        if (distance < ans) ans = distance;
                    }
                }
                Console.WriteLine(ans);
            }
        }
    }

    //????
    static long GetFirstIndex(long[] array,long startPlace)
    {
        if (array.Length <= 1) return 0;

        var top = array.Length-1;
        var bottom = 0;

        //bottom startPlace top?????????
        while (bottom+1 != top)
        {
            //??
            var middle = (top + bottom) / 2;

            //???????
            if (array[middle] < startPlace) bottom = middle;
            //???????
            else if (startPlace < array[middle]) top = middle;
        }

        return bottom;
    }
}