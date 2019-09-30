using System;

class Program
{
    static void Main(String[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int H = int.Parse(input[0]);
        int W = int.Parse(input[1]);
        string[] S = new string[H];
        int[,] pivot = new int[H, W];

        for(int i = 0; i < H; i++)
        {
            for(int j=0;j<W;j++)
            {
                pivot[i,j] = 0;
            }
        }
        
        for(int i = 0; i < H; i++)
        {
            S[i] = Console.ReadLine();
        }

        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {

                for(int k= i - 1; k < i + 3; k++)
                {
                    for(int l = j - 1; l < j + 2; l++)
                    {
                        if (k == i + 2)
                        {
                            for (int m = i - 1; m < i + 2; m++)
                            {
                                if (m == -1 || m == H) continue;
                                for (int n = j - 1; n < j + 2; n++)
                                {
                                    if (n == -1 || n == W) continue;
                                    pivot[m, n]++;
                                }
                            }
                            pivot[i, j] += 10;
                            break;
                        }
                        else if (((k <= -1 || k >= H)) ||(l <= -1 || l >= W)) continue;
                        else if (S[k][l] != '#') {
                            k += 10;
                            break;
                        } 
                    }
                }

            }
        }

        bool flag = true;
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                if (pivot[i, j] == 0 && S[i][j] == '#')
                {
                    flag = false;
                    Console.WriteLine("impossible");
                    i += H;
                    break;
                }
            }
        }

        if (flag == true)
        {
            Console.WriteLine("possible");
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (pivot[i, j] > 10) Console.Write('#');
                    else Console.Write('.');
                }
                Console.WriteLine();
            }
        }
    }
}