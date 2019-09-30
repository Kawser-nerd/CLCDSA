using System;
using System.Collections.Generic;
class Program
{
    //static List<string> str = new List<string>();
    static void Main(string[] args)
    {
        // ??
        string[] input = Console.ReadLine().Split(' ');
        int H = int.Parse(input[0]);
        int W = int.Parse(input[1]);

        // X??????????????
        List<List<int>> list = new List<List<int>>();
        for(int i=0; i<H; i++)
        {
            input = Console.ReadLine().Split(' ');
            List<int> row = new List<int>();
            for(int j=0; j<W; j++)
            {
                row.Add(int.Parse(input[j]));
            }
            list.Add(row);
        }

        // ? or ???????????
        List<string> ret = new List<string>();
        string str = "";
        for (int i = 0; i < H; i++ )
        {
            for(int j=0; j<W; j++)
            {
                //Console.WriteLine(i + " " + j);
                if(list[i][j]%2 == 0)
                {
                    continue;
                }
                else
                {
                    // ???? or ????????????
                    if((j+1<W && list[i][j+1]%2 == 1) || (j+1<W && i+1 >= H))
                    {
                        str = (i+1) + " " + (j+1) + " " + (i+1) + " " + (j + 2);
                        list[i][j] -= 1;
                        list[i][j + 1] += 1;
                        ret.Add(str);
                    }
                    else if(i+1 < H)
                    {
                        // ??????
                        str = (i+1) + " " + (j+1) + " " + (i + 2) + " " + (j+1);
                        list[i][j] -= 1;
                        list[i + 1][j] += 1;
                        ret.Add(str);
                    }
                }
            }
        }

        Console.WriteLine(ret.Count);
        foreach(var s in ret)
        {
            Console.WriteLine(s);
        }
        //if (ret)
        //    Console.WriteLine("Yes");
        //else
        //    Console.WriteLine("No");
    }

    static int calculationGCD(int a, int b)
    {
        if(a%b == 0)
        {
            return b;
        }
        else
        {
            return calculationGCD(b, a % b);
        }
    }

}