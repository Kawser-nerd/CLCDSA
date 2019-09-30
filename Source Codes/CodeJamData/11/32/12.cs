using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class B : Problem
{
    protected override string solveCase()
    {
        line = reader.ReadLine();
        String[] valoriInput = line.Split(' ');

        int L = int.Parse(valoriInput[0]);
        long t = long.Parse(valoriInput[1]);
        int N = int.Parse(valoriInput[2]);
        int C = int.Parse(valoriInput[3]);

        int[] cc=new int[C];

        for (int i = 0; i < C; i++)
        {
            cc[i] = int.Parse(valoriInput[4+i]);
        }

        long[] nn = new long[N];
        long time = 0;
        long timex = 0;
        int firstIdx = -1;
        for (int i = 0; i < N; i++)
        {
            int d = cc[i%C];
            nn[i] = d;
            time += 2 * d;
            if (firstIdx==-1 && time >= t )
            {
                firstIdx=i;
                timex = time;
            }
        }

        for (int i = 0; i < firstIdx; i++){
            nn[i] = 0;
        }
        if (firstIdx>=0) nn[firstIdx] = (timex - t)/2;
        Array.Sort(nn);

        for (int i = 0; i < L; i++)
        {
            time -= nn[N -1 - i];
        }

        string res = time+"";

       


        return res;
    }








}


