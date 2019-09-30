using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
        char[][] map = Enumerable.Repeat(0, hw[0]).Select(_ => Console.ReadLine().ToArray()).ToArray();
        //???????????????????????????????????
        //?????????????????…?
        int[][] countChari = Enumerable.Repeat(0, hw[0]).Select(_ => new int[26]).ToArray();
        int[][] countCharj = Enumerable.Repeat(0, hw[1]).Select(_ => new int[26]).ToArray();
        for (int i = 0; i < hw[0]; i++)
        {
            for (int j = 0; j < hw[1]; j++)
            {
                countChari[i][map[i][j] - 'a']++;
                countCharj[j][map[i][j] - 'a']++;
            }
        }
        
        //????????????????????????????
        bool canConstructi = canConstruct(countChari);
        bool canConstructj = canConstruct(countCharj);
        Debug.WriteLine(Hash(map));
        if (canConstructi && canConstructj)
        {
            if (hashIsInRange(Hash(map)))
            {
                Console.WriteLine("NO");
                return;
            }
            //No?Yes????????
            Console.WriteLine("YES");
        }
        else
        {
            Console.WriteLine("NO");
        }
        //Console.WriteLine(canConstruct(countChari) && canConstruct(countCharj) ? "YES" : "NO");
    }
    static bool hashIsInRange(int hash)
    {
        long lower = (long)int.MaxValue * 61 / 64;
        long upper = (long)int.MaxValue * 62 / 64;
        return lower <= hash && hash <= upper;
    }
    static int Hash(char[][] map) => string.Join("", map.Select(x => string.Join("", x))).GetHashCode();
    static bool canConstruct(int[][] countChar)
    {
        bool center = countChar.Length % 2 == 1;
        bool[] isUsed = new bool[countChar.Length];
        for (int i = 0; i < countChar.Length; i++)
        {
            if (isUsed[i]) continue;
            for (int j = i + 1; j < countChar.Length; j++)
            {
                if (isUsed[j]) continue;
                for (int k = 0; k < 26; k++)
                {
                    if (countChar[i][k] != countChar[j][k]) goto alphend;
                }
                isUsed[i] = true;
                isUsed[j] = true;
                break;
                alphend:;
            }
            if (center && !isUsed[i])
            {
                bool innnerCenter = countChar[i].Sum() % 2 == 1;
                int[] judge = countChar[i].OrderBy(x => x).SkipWhile(x => x == 0).ToArray();
                foreach (var item in judge)
                {
                    /*
                    if (last == 0) last = item;
                    else if (last == item) last = 0;
                    else if (innnerCenter)
                    {
                        last = 0;
                        innnerCenter = false;
                    }
                    else
                    {
                        goto end;
                    }*/
                    if (item % 2 != 0)
                    {
                        if (!innnerCenter) goto end;
                        innnerCenter = false;
                    }
                }
                isUsed[i] = true;
                center = false;
                end:;
            }
        }
        return isUsed.All(x => x);
    }
}