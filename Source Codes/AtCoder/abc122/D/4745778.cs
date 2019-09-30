using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using static System.Math;
using Debug = System.Diagnostics.Debug;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;

static class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        //matrix[i,j]:vector[i]????a????i???j???a????????(DP??????)
        ModMatrix matrix = new ModMatrix(4 * 4 * 4, 4 * 4 * 4);
        //t : 0
        //a : 1
        //g : 2
        //c : 3

        for (int i = 0; i < matrix.Height; i++)
        {
            int val = i;
            
            //t s f
            int firstLiteral = val % 4;
            val /= 4;
            int secondLiteral = val % 4;
            val /= 4;
            int thirdLiteral = val % 4;

            
            //?????agc,gac,acg,a_gc,ag_c

            //t???????
            matrix[i, (secondLiteral * 4 + firstLiteral) * 4 + 0] += 1;

            //a???????
            matrix[i, (secondLiteral * 4 + firstLiteral) * 4 + 1] += 1;

            //g???????:acg??????
            if (!(secondLiteral == 1 && firstLiteral == 3/*acg*/)) matrix[i, (secondLiteral * 4 + firstLiteral) * 4 + 2] += 1;

            //c??????? : agc,gac,a_gc,ag_c??????
            if (!(secondLiteral == 1 && firstLiteral == 2/*agc*/) &&
                !(secondLiteral == 2 && firstLiteral == 1/*gac*/) &&
                !(thirdLiteral == 1 && firstLiteral == 2/*a_gc*/) &&
                !(thirdLiteral == 1 && secondLiteral == 2/*ag_c*/)) matrix[i, (secondLiteral * 4 + firstLiteral) * 4 + 3] += 1;
        }

        ModMatrix res = new ModMatrix(1, 4 * 4 * 4);
        res[0, 0] = 1;
        while (n > 0)
        {
            if ((n & 1) == 1) res *= matrix;
            matrix *= matrix;
            n >>= 1;
        }

        long resSum = 0;
        for (int i = 0; i < res.Width; i++) resSum += res[0, i];
        Console.WriteLine(resSum % 1000000007);
    }
}



class ModMatrix
{
    const int MOD = 1000000007;
    public int Height { get; private set; }
    public int Width { get; private set; }
    long[,] data;
    public ModMatrix(int height, int width)
    {
        data = new long[height, width];
        Height = height;
        Width = width;
    }
    public long this[int i, int j]
    {
        get { return data[i, j]; }
        set { data[i, j] = value; }
    }
    public static ModMatrix Multiple(ModMatrix a, ModMatrix b)
    {
        Debug.Assert(a.Width == b.Height);
        var res = new ModMatrix(a.Height, b.Width);
        for (int i = 0; i < a.Height; i++)
            for (int j = 0; j < b.Width; j++)
                for (int k = 0; k < a.Width; k++)
                {
                    res[i, j] += a[i, k] * b[k, j];
                    res[i, j] %= MOD;
                }
        return res;
    }

    public static ModMatrix operator *(ModMatrix a, ModMatrix b) => Multiple(a, b);
}