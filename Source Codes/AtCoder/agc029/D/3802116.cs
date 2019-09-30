// ???????Ctrl+F5

using System;
using System.Collections.Generic;
class Program
{
    static void Main(string[] args)
    {
        String line;
        line = Console.ReadLine();
        String[] words = line.Split(' ');
        int H = int.Parse(words[0]); //X????
        int W = int.Parse(words[1]); //Y????
        int N = int.Parse(words[2]);
        int MAX = H;
        int X, Y;
        var dict = new Dictionary<int, List<int>>();
        for(int i = 0; i < N; i++)
        {
            line = Console.ReadLine();
            words = line.Split(' ');
            X = int.Parse(words[0]);
            Y = int.Parse(words[1]);
            if (dict.ContainsKey(Y))
            {
                dict[Y].Add(X);
            }
            else
            {
                dict[Y] = new List<int>();
                dict[Y].Add(X);
            }

        }
        // ?????????????????
        foreach(KeyValuePair<int, List<int>> kvp in dict)
        {
            kvp.Value.Sort();
        }
        int beforeX = 1;
        // ?????X?????
        for (int i = 1; i <= W; i++) // i:Y??
        {
            if (dict.ContainsKey(i))
            {
                foreach(int value in dict[i])
                {
                    // ?????????????????
                    if (value > beforeX )
                    {
                        // ????????????
                        if (MAX > value-1) MAX = value-1;
                        break;
                    }
                }
            }
            // ????????"???"???????????????????????????
            if (i == W) break; //?????????????
            beforeX++;
            if (dict.ContainsKey(i+1))
            {
                foreach (int value in dict[i+1])
                {
                    // 1????????????????????beforeX?1???????????????
                    if (beforeX == value)
                    {
                        beforeX++;
                    }
                }
            }
        }
        Console.WriteLine(MAX);
    }
}