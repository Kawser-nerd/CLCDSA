using System;
using System.Linq;

namespace abc039_d
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool[,] createimage = new bool[x[0], x[1]];
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[1]; j++)
                {
                    createimage[i, j] = true;
                }
            }
            bool[,] givenimage = new bool[x[0], x[1]];
            for (int i = 0; i < x[0]; i++)
            {
                string s = Console.ReadLine();
                for (int j = 0; j < x[1]; j++)
                {
                    givenimage[i, j] = s[j] == '#';
                    if (s[j] == '.')
                    {
                        for (int k = -1; k <= 1; k++)
                        {
                            for (int l = -1; l <= 1; l++)
                            {
                                if (0 <= i + k && i + k < x[0] &&
                                    0 <= j + l && j + l < x[1])
                                    createimage[i + k, j + l] = false;
                            }
                        }
                    }
                }
            }
            bool ret = true;
            for (int i = 0; i < x[0]; i++)
            {
                for (int j = 0; j < x[1]; j++)
                {
                    bool flag = false;
                    for (int k = -1; k <= 1; k++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            if (0 <= i + k && i + k < x[0] &&
                                0 <= j + l && j + l < x[1] &&
                                createimage[i + k, j + l]) flag = true;
                        }
                    }
                    if (givenimage[i, j] != flag)
                    {
                        ret = false;
                    }
                }
            }
            Console.WriteLine(ret ? "possible" : "impossible");
            if (ret)
            {
                for (int i = 0; i < x[0]; i++)
                {
                    for (int j = 0; j < x[1]; j++)
                    {
                        Console.Write(createimage[i, j] ? '#' : '.');
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}