using System;
        using System.Linq;
        using System.Collections.Generic;
        using static System.Math;

        public class Program
        {
            public static void Main(string[] args)
            {
            int[] gridInput = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            string[,] grid = new string[gridInput[0] + 1,gridInput[1] + 2];

            for (int i = 0; i < gridInput[0]; i++)
            {
                for (int j = 0; j < gridInput[1] + 2; j++)
                {
                    grid[i, j] = ".";
                }
            }

            for (int i = 1; i < gridInput[0] + 1; i++)
            {
                string input = Console.ReadLine();
                for (int j = 1; j < gridInput[1] + 1; j++)
                {
                    grid[i, j] = input.Substring(j - 1,1);
                }
            }

            bool check = true;
            for (int i = 1; i < gridInput[0]; i++)
            {
                for (int j = 1; j < gridInput[1]; j++)
                {
                    if (grid[i,j] == "#")
                    {
                        int count = 0;
                        if (grid[i + 1, j] == "." && grid[i, j + 1] == "."
                            && grid[i - 1, j] == "." && grid[i, j -1] == ".")
                        {
                            check = false;
                        }
                    }
                }
            }

            Console.WriteLine(check == true? "Yes":"No");
            }
        }