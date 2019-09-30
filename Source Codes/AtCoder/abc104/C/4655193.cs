using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        //????
        int[] IN = Console.ReadLine().Split(' ').Select((s) => int.Parse(s)).ToArray();
        int D = IN[0];
        int Goal = IN[1];
        List<int[]> PC = new List<int[]>();
        for(int i = 0; i < D; i++)
        {
            PC.Add(Console.ReadLine().Split(' ').Select((s) => int.Parse(s)).ToArray());
        }

        int min = int.MaxValue;

        //??????????????????
        for(int i=0; i < (1 << D); i++)
        {
            int score = 0;
            int solve = 0;
            int untouched = 0;

            for(int j = 0; j < D; j++)
            {
                //100j?????????????
                if ((i & (1 << j)) != 0)
                {
                    score += PC[j][0] * (j+1) * 100 + PC[j][1];
                    solve += PC[j][0];
                }else
                {
                    untouched = j;
                }
            }

            //????????
            int more = Goal - score;
            if (more > 0)
            {
                int utunit = (untouched + 1) * 100;
                if (score + PC[untouched][0] * utunit < Goal)
                {
                    //???????????????????
                    continue;
                }
                //?????????????????
                solve += (more / utunit) + ((more % utunit != 0) ? 1 : 0);
            }

            //???????
            if (solve < min)
            {
                min = solve;
            }
        }

        Console.WriteLine(min);
    }
}