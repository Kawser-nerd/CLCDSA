using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] nk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int[][] t = Enumerable.Range(1, nk[0]).Select(_ => Console.ReadLine().Split().Select(int.Parse).ToArray()).ToArray();
        switch (nk[0])
        {
            case 1:
            for (int i = 0; i < nk[1]; i++)
            {
                if ((t[0][i]) == 0)
                {
                    Console.WriteLine("Found");
                    return;
                }
            }
            break;
            case 2:
            for (int i = 0; i < nk[1]; i++)
            {
                for (int j = 0; j < nk[1]; j++)
                {
                    if ((t[0][i] ^ t[1][j]) == 0)
                    {
                        Console.WriteLine("Found");
                        return;
                    }
                }
            }
            break;
            case 3:
            for (int i = 0; i < nk[1]; i++)
            {
                for (int j = 0; j < nk[1]; j++)
                {
                    for (int k = 0; k < nk[1]; k++)
                    {
                        if ((t[0][i] ^ t[1][j] ^ t[2][k]) == 0)
                        {
                            Console.WriteLine("Found");
                            return;
                        }
                    }
                }
            }
            break;
            case 4:
            for (int i = 0; i < nk[1]; i++)
            {
                for (int j = 0; j < nk[1]; j++)
                {
                    for (int k = 0; k < nk[1]; k++)
                    {
                        for (int l = 0; l < nk[1]; l++)
                        {
                            if ((t[0][i] ^ t[1][j] ^ t[2][k] ^ t[3][l]) == 0)
                            {
                                Console.WriteLine("Found");
                                return;
                            }
                        }
                    }
                }
            }
            break;
            case 5:
            for (int i = 0; i < nk[1]; i++)
            {
                for (int j = 0; j < nk[1]; j++)
                {
                    for (int k = 0; k < nk[1]; k++)
                    {
                        for (int l = 0; l < nk[1]; l++)
                        {
                            for (int m = 0; m < nk[1]; m++)
                            {
                                if ((t[0][i] ^ t[1][j] ^ t[2][k] ^ t[3][l] ^ t[4][m]) == 0)
                                {
                                    Console.WriteLine("Found");
                                    return;
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
        Console.WriteLine("Nothing");
    }
}