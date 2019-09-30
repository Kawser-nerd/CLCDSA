using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.Numerics;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Math;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;
using System.Runtime.CompilerServices;


static class P
{
    static void Main()
    {
        int n = Read();
        int m = Read();
        IntTuple[] edges = new IntTuple[m];
        for (int i = 0; i < edges.Length; i++)
        {
            edges[i] = new IntTuple(Read() - 1, Read() - 1);
        }
        //????????
        IntTuple[] currentColor = new IntTuple[n];
        IntTuple[][] colors = new IntTuple[n][];
        IntTuple[][] nextColors = new IntTuple[n][];
        
        //11*10^5
        for (int i = 0; i < colors.Length; i++)
        {
            colors[i] = new IntTuple[11];
            nextColors[i] = new IntTuple[11];
        }
        //?????????????????????

        //10^5
        var q = Read();
        for (int i = 1; i <= q; i++)
        {
            var v = Read() - 1;
            var d = Read();
            var c = Read();
            colors[v][d] = new IntTuple(c, i);
            currentColor[v] = new IntTuple(c, i);
        }

        //10*(3*10^6)
        for (int i = 1; i <= 10; i++)
        {
            //10^5*10
            for (int j = 0; j < nextColors.Length; j++)
                for (int k = 0; k < nextColors[j].Length; k++) nextColors[j] = new IntTuple[11 - i];

            //10^5*10
            for (int index = 0; index < edges.Length; index++)
            {
                var edge = edges[index];
                for (int j = 0; j < 11 - i; j++)
                {
                    if(nextColors[edge.Item1][j].Item2 < colors[edge.Item2][j + 1].Item2) nextColors[edge.Item1][j] = colors[edge.Item2][j + 1];
                    if(nextColors[edge.Item2][j].Item2 < colors[edge.Item1][j + 1].Item2) nextColors[edge.Item2][j] = colors[edge.Item1][j + 1];
                }
            }

            var tmp = colors;
            colors = nextColors;
            nextColors = tmp;

            //10^5*10
            for (int j = 0; j < colors.Length; j++)
            {
                var currentNewest = new IntTuple();
                for (int k = 0; k < colors[j].Length; k++)
                {
                    if (currentNewest.Item2 < colors[j][k].Item2) currentNewest = colors[j][k];
                }
                if(currentColor[j].Item2 < currentNewest.Item2) currentColor[j] = currentNewest;
            }
        }
        Console.WriteLine(string.Join("\n", currentColor.Select(x => x.Item1)));
    }
    
    static readonly TextReader In = Console.In;
    [MethodImpl(MethodImplOptions.AggressiveInlining)]
    static int Read()
    {
        int res = 0;
        int next = In.Read();
        while (48 > next || next > 57) next = In.Read();
        while (48 <= next && next <= 57)
        {
            res = res * 10 + next - 48;
            next = In.Read();
        }
        return res;
    }
}

struct IntTuple
{
    public int Item1;
    public int Item2;
    public IntTuple(int a,int b)
    {
        Item1 = a;
        Item2 = b;
    }
}