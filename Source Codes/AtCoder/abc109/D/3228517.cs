using System;
using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split();
        var h = int.Parse(input[0]);
        var w = int.Parse(input[1]);
        var matrix = new int[h, w];

        for (var i = 0; i < h; i++)
        {
            var temp = Array.ConvertAll(ReadLine().Split(), int.Parse);
            for (var j = 0; j < w; j++)
            { matrix[i, j] = temp[j]; }

        }

        var pickUp = false;
        var traceList = new List<string>();

        for (var i = 0; i < h; i++)
        {
            //???
            if (i % 2 == 0)
            {
                for (var j = 0; j < w; j++)
                {
                    if (matrix[i, j] % 2 == 1)
                    { pickUp = !pickUp; }


                    if (pickUp)
                    {
                        var s = new string[4];

                        if (j + 1 < w)
                        {
                            s[0] = Convert.ToString(i + 1 + " ");
                            s[1] = Convert.ToString(j + 1 + " ");
                            s[2] = Convert.ToString(i + 1 + " ");
                            s[3] = Convert.ToString(j + 2);
                            traceList.Add(s[0] + s[1] + s[2] + s[3]);
                        }
                        else if (i + 1 < h)
                        {
                            s[0] = Convert.ToString(i + 1 + " ");
                            s[1] = Convert.ToString(j + 1 + " ");
                            s[2] = Convert.ToString(i + 2 + " ");
                            s[3] = Convert.ToString(j + 1);
                            traceList.Add(s[0] + s[1] + s[2] + s[3]);
                        }
                    }
                }
            }
            //???
            else
            {
                for (var j = w - 1; j >= 0; j--)
                {
                    if (matrix[i, j] % 2 == 1)
                    { pickUp = !pickUp; }

                    if (pickUp)
                    {
                        var s = new string[4];

                        if (j > 0)
                        {
                            s[0] = Convert.ToString(i + 1 + " ");
                            s[1] = Convert.ToString(j + 1 + " ");
                            s[2] = Convert.ToString(i + 1 + " ");
                            s[3] = Convert.ToString(j);
                            traceList.Add(s[0] + s[1] + s[2] + s[3]);
                        }
                        else if (i + 1 < h)
                        {
                            s[0] = Convert.ToString(i + 1 + " ");
                            s[1] = Convert.ToString(j + 1 + " ");
                            s[2] = Convert.ToString(i + 2 + " ");
                            s[3] = Convert.ToString(j + 1);
                            traceList.Add(s[0] + s[1] + s[2] + s[3]);
                        }
                    }
                }
            }
        }

        WriteLine(traceList.Count);
        foreach (string s in traceList)
        { WriteLine(s); }
    }
}