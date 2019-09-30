using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

public class Hello
{
    public static void Main()
    {
        int[] cdNum_lisNum = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        int[] cdCases = new int[cdNum_lisNum[0]];
        int nowPlaying = 0;
        int temp = 0;

        for(int i = 1; i < cdCases.Length + 1; i++)
        {
            cdCases[i - 1] = i;
        }

        for(int i = 0; i < cdNum_lisNum[1]; i++)
        {
            temp = nowPlaying;
            nowPlaying = int.Parse(Console.ReadLine());
            if (nowPlaying == temp) continue;
            cdCases[Array.IndexOf(cdCases, nowPlaying)] = temp;
        }

        foreach(int n in cdCases)
        {
            Console.WriteLine(n);
        }
    }
}