using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Solution
        {
            public string Solve(int N, int M, int K)
            {
                
                var already = 0;

                if(K < 5)
                {
                    return K.ToString();
                }

                if(N == 1 || M == 1 || N == 2 || M == 2)
                {
                    return K.ToString();
                }

                if(N * M - 4 < K)
                {
                    if (N * M - 3 == K)
                    {
                        return ((N - 2) * 2 + (M - 2) * 2 + 4 - 3).ToString();
                    }
                    if (N * M - 2 == K)
                    {
                        return ((N - 2) * 2 + (M - 2) * 2 + 4 - 2).ToString();
                    }
                    if (N * M - 1 == K)
                    {
                        return ((N - 2) * 2 + (M - 2) * 2 + 4 - 1).ToString();
                    }
                    if (N * M == K)
                    {
                        return ((N - 2) * 2 + (M - 2) * 2 + 4).ToString();
                    }
                }

                var matrix = new int[N, M];
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        matrix[i, j] = 0;
                    }
                }

                for (int i = 1; i < N - 1; i++)
                {
                    if(K == already)
                    {
                        break;
                    }
                    for (int j = 1; j < M - 1; j++)
                    {
                        //var t = GetResult(N, M, matrix);

                        var diff = K - already;

                        if(matrix[i,j] == 2)
                        {
                            if (diff < 2)
                            {
                                if (diff == 1)
                                {
                                    matrix[i, j + 1] = 2;
                                    already++;
                                }
                                if (matrix[i, j + 1] != 0 && 
                                    matrix[i, j - 1] != 0 &&
                                    matrix[i + 1, j] != 0 &&
                                    matrix[i - 1, j] != 0)
                                {
                                    matrix[i, j] = 1;
                                }
                                break;
                            }
                            else if(diff == 2 && i == 1)
                            {
                                matrix[i + 1, 0] = 2;
                                matrix[i + 1, 1] = 1;
                                matrix[i + 2, 1] = 2;
                                already++;
                                already++;
                                break;
                            }
                            else
                            {
                                already--;
                                matrix[i, j] = 0;
                            }
                        }
                        matrix[i, j] = 1;
                        already++;

                        if (matrix[i - 1, j] == 0)
                        {
                            matrix[i - 1, j] = 2;
                            already++;
                        }

                        if (matrix[i, j - 1] == 0)
                        {
                            matrix[i, j - 1] = 2;
                            already++;
                        }

                        if (matrix[i + 1, j] == 0)
                        {
                            matrix[i + 1, j] = 2;
                            already++;
                        }

                        if (matrix[i, j + 1] == 0)
                        {
                            matrix[i, j + 1] = 2;
                            already++;
                        }
                        
                        //diff = K - already;
                        //if(diff == 0)
                        //{
                        //    break;
                        //}
                    }
                }

                var result = 0;

                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (matrix[i, j] == 2)
                        {
                            result++;
                        }
                    }
                }

                //var result = GetResult(N, M, matrix);

                return result.ToString();
            }

            private static StringBuilder GetResult(int N, int M, int[,] matrix)
            {
                StringBuilder result = new StringBuilder();
                result.Append("\n\r");
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        result.Append(matrix[i, j].ToString());
                    }
                    result.Append("\n\r");
                }
                return result;
            }
        }

        static void Main(string[] args)
        {
            string filename = "C-small-attempt5";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solution solution = new Solution();
                    for (int i = 0; i < T; i++)
                    {
                        var numbers = reader.ReadLine().Split(' ');

                        writer.WriteLine("Case #" + (i + 1) + ": " + solution.Solve(Int32.Parse(numbers[0]),Int32.Parse(numbers[1]),Int32.Parse(numbers[2])));
                    }
                }
            }
        }
    }
}
