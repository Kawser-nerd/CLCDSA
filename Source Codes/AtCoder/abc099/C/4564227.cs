using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var N = Int32.Parse(Console.ReadLine());
        var ans = 100000;
        for (int i = 0; i <= N; ++i)
        {
            var cost = 0;
            //6??
            cost += GetCost(i,6);
            //9
            cost += GetCost(N-i,9);
            ans=Math.Min(ans,cost);
        }
        Console.WriteLine(ans);
    }
    static int GetCost(int originalNum,int dividedNum)
    {
        var cost = 0;
        while (0<originalNum)
        {
            cost += originalNum % dividedNum;
            originalNum /= dividedNum;
        }
        return cost;
    }
}