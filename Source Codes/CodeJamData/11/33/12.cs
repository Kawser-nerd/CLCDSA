using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

public class C : Problem
{
    protected override string solveCase()
    {
        line = reader.ReadLine();
        String[] valoriInput = line.Split(' ');

        long N = long.Parse(valoriInput[0]);
        long L = long.Parse(valoriInput[1]);
        long H = long.Parse(valoriInput[2]);

        line = reader.ReadLine();

        long[] note = new long[N];

        
        valoriInput = line.Split(' ');
        for (int i = 0; i < N; i++)
        {
            note[i] = int.Parse(valoriInput[i]);
        }
        bool ok=false;
        long z=L;
        for (; z <= H; z++)
        {
            ok = true;
            for (int j = 0; j < N; j++)
            {
                if (z%note[j]==0 || note[j]%z==0)
                {
                    continue;
                }
                ok = false;
                break;
            }
            if (ok) break;
        }


        if (ok) return z+"";

        return "NO";



        /*

        long mcd = MCDOK(note, L, H);
        

        if (mcd > 0) return mcd + "";

        long mcm = MCMOK(note, L, H);

        if (mcm == 0) return "NO";

        return mcm + "";
         * */
    }

    static long MCDOK(long[] note, long L, long H)
    {
        long mcd = MCD(note);

        if (mcd < L) return 0;

        while (mcd > H)
        {
            for (int i = 2; i <= mcd; i++)
            {
                if (mcd % i == 0) mcd /= i;
            }
        }

        if (mcd < L) return 0;
        return mcd;
    }


    static long MCMOK(long[] note, long L, long H)
    {
        long mcm = MCM(note);
        long mcmbase = mcm;
        if (mcm > H) return 0;

        while (mcm < L)
        {
            mcm += mcmbase;
        }

        if (mcm > H) return 0;
        return mcm;
    }

    static long MCD(long a, long b){
        if (a == b) return a;
        if (a > b) return MCD(a - b, b);
        return MCD(a, b - a);
    }

    static long MCD(long[] m)
    {
        long mcd = m[0];
        for (int i = 1; i < m.Length; i++)
        {
            mcd = MCD(mcd, m[i]);
            if (mcd == 1) return 1;
        }

        return mcd;
    }

    static long MCM(long a, long b)
    {
        return a*b/MCD(a, b);
    }

    static long MCM(long[] m)
    {
        long mcm = m[0];
        for (int i = 1; i < m.Length; i++)
        {
            mcm = MCM(mcm, m[i]);
        }

        return mcm;
    }









}


