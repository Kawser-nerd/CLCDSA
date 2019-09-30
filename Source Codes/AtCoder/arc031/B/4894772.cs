using System;
using System.Collections.Generic;
using System.Linq;



namespace ConsoleApp1
{
    //??????
    class Program
    {
        static bool[,] Map = new bool[12, 12];
        static bool[,] copyMap;
        static bool[,] tmpMap; //?????


        static void Main(string[] args)
        {
            //Map??(? = true)
            for (int i = 0; i < 12; i++)
            {
                Map[0, i] = false;
                Map[11, i] = false;
                Map[i, 0] = false;
                Map[i, 11] = false;
            }
            
            for (int i = 1; i < 11; i++)
            {
                string line = Console.ReadLine();

                for (int j = 1; j < 11; j++)
                {
                    if (line[j - 1] == 'o') Map[i, j] = true;
                    else Map[i, j] = false;                    
                }
            }

            //???
            for (int i = 1; i < 11; i++)
            {
                for (int j = 1; j < 11; j++)
                {
                    //????
                    if (Map[i, j]) continue;

                    copyMap = new bool[12, 12];
                    Array.Copy(Map, copyMap, Map.Length);

                    //?????
                    tmpMap = new bool[12, 12];
                    DFS(i, j);

                    bool tmpFlag = true;

                    for (int k = 1; k < 11; k++)
                    {
                        for (int l = 1; l < 11; l++)
                        {
                            if (!Map[k, l]) continue;

                            if (!tmpMap[k, l]) tmpFlag = false;
                        }
                    }

                    if (tmpFlag)
                    {
                        Console.WriteLine("YES");
                        ;
                        return;
                    }
                }
            }
            Console.WriteLine("NO");
            ;

        }

        static void DFS (int x, int y)
        {
            copyMap[x, y] = false;
            tmpMap[x, y] = true;

            if (copyMap[x, y - 1]) DFS(x, y - 1);
            if (copyMap[x, y + 1]) DFS(x, y + 1);
            if (copyMap[x - 1, y]) DFS(x - 1, y);
            if (copyMap[x + 1, y]) DFS(x + 1, y);

        }

    }

}