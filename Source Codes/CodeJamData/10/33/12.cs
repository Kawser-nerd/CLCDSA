using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ10_R1C_03_01
{
    class Program
    {
        static short[,] board;
        static int M, N;

        static void Main(string[] args)
        {
            string dir = @"C:\Projects\GCJ10\R1C\03\";

            using(StreamReader sr = new StreamReader(dir + "input.in"))
            {
                string readstr;
                readstr = sr.ReadLine();

                int TestCases = int.Parse(readstr);

                using (StreamWriter sw = new StreamWriter(dir + "output.out"))
                {
                    for (int testCnt = 0; testCnt < TestCases; testCnt++)
                    {
                        readstr = sr.ReadLine(); // M N
                        string[] Dimens = readstr.Split(' ');
                        M = int.Parse(Dimens[0]);
                        N = int.Parse(Dimens[1]);

                        board = new short[M, N];
                        ParseBoard(sr, M, N);

                        Console.WriteLine();
                        //Dictionary<int, int> boards = new Dictionary<int, int>();

                        int maxSize = -1;
                        int maxR = -1, maxC = -1;

                        for (int row = 0; row < M; row++)
                        {
                            for (int col = 0; col < N; col++)
                            {
                                int testMax = Try(row, col, 2);

                                if (testMax > maxSize)
                                {
                                    maxSize = testMax;
                                    maxR = row;
                                    maxC = col;
                                }
                            }
                        }

                        Erase(maxR, maxC, maxSize);
                        DumpBoard();

                        // found the biggest one
                        int[] results = new int[maxSize + 1];
                        results[maxSize]++;

                        Console.WriteLine("Size {0}, R {1}, C {2}", maxSize, maxR, maxC);

                        int localMax = -1;
                        int localR = -1, localC = -1;
                        while (true)
                        {
                            localMax = -1;
                            for (int row = 0; row < M; row++)
                            {
                                for (int col = 0; col < N; col++)
                                {
                                    int testMax = Try(row, col, 2);

                                    if (testMax > localMax)
                                    {
                                        localMax = testMax;
                                        localR = row;
                                        localC = col;
                                    }
                                }
                            }

                            if (localMax == 1)
                            {
                                Console.WriteLine("only ones");
                                break;
                            }
                            else
                            {
                                Console.WriteLine("Size {0}, R {1}, C {2}", localMax, localR, localC);
                                Erase(localR, localC, localMax);
                                results[localMax]++;
                            }
                        }

                        // count and output ones
                        for (int row = 0; row < M; row++)
                        {
                            for (int col = 0; col < N; col++)
                            {
                                if (board[row, col] != -100)
                                    results[1]++;
                            }
                        }

                        int nonZero = 0;
                        foreach (int i in results)
                        {
                            if (i != 0)
                                nonZero++;
                        }
                            

                        sw.WriteLine("Case #{0}: {1}", testCnt+1, nonZero);
                        for(int i = maxSize; i > 0; i--)
                        {
                            if (results[i] != 0)
                                sw.WriteLine("{0} {1}", i, results[i]);
                        }
                    }
                }
            }
        }

        static short ToShort(char c)
        {
            char[] makestr = {c};
            string convert = new string(makestr);
            Int16 res = Convert.ToInt16(convert, 16);

            return ((short)res);
        }

        static void ParseBoard(StreamReader sr, int M, int N)
        {
            string readstr;
            for (int lineCnt = 0; lineCnt < M; lineCnt++)
            {
                readstr = sr.ReadLine();
                for (int nibbleCnt = 0; nibbleCnt < N / 4; nibbleCnt++)
                {
                    short nibble = ToShort(readstr[nibbleCnt]);
                    for (short cellCnt = 0; cellCnt < 4; cellCnt++)
                    {
                        board[lineCnt, nibbleCnt * 4 + 4 - cellCnt - 1] = (short)(nibble % 2);
                        nibble /= 2;
                    }
                }

                for (int cellCnt = 0; cellCnt < N; cellCnt++)
                {
                    Console.Write(board[lineCnt, cellCnt]);
                }
                Console.WriteLine();
            }

        }

        static int Try(int stR, int stC, int size)
        {
            for (int check = 0; check < size; check++)
            {
                if ((stR + size - 1 >= M) || (stC + size - 1 >= N))
                    return size - 1;

                if (board[stR + size - 2, stC + check] + board[stR + size - 1, stC + check] != 1)
                    return size - 1;

                if (board[stR + check, stC + size - 2] + board[stR + check, stC + size - 1] != 1)
                    return size - 1;
            }

            return Try(stR, stC, size + 1);
        }

        static void Erase(int stR, int stC, int size)
        {
            for (int rowCnt = 0; rowCnt < size; rowCnt++)
                for (int colCnt = 0; colCnt < size; colCnt++)
                    board[stR + rowCnt, stC + colCnt] = -100;
        }

        static void DumpBoard()
        {
            for (int rowCnt = 0; rowCnt < M; rowCnt++)
            {
                for (int colCnt = 0; colCnt < N; colCnt++)
                {
                    if (board[rowCnt, colCnt] == -100)
                        Console.Write("x");
                    else
                        Console.Write(board[rowCnt, colCnt]);
                }
                Console.WriteLine();
            }
        }
    }
}
