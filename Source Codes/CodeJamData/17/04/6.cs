using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ._2017.RQ
{

    public class Ele
    {
        public int x;
        public int y;
        public Ele(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
    }

    public class P4 : CommonClass
    {
        int N;
        int M;
        int maxIncreasing;
        int[][] c;
        int[][] initC;
        int[][] posi;
        int[] row;
        int[] col;
        int[] dig1;
        int[] dig2;
        
        int FACTOR_P = 2;
        int FACTOR_X = 3;
        int FACTOR_O = 6;

        int orginalScore;

        public P4(StreamReader fileIn, StreamWriter fileOut) : base(fileIn, fileOut)
        {
        }

        public int Round(int a)
        {
            while (a % (FACTOR_P * FACTOR_P) == 0)
            {
                a /= FACTOR_P;
            }
            while (a % (FACTOR_X * FACTOR_X) == 0)
            {
                a /= FACTOR_X;
            }

            return a;
        }

        public int CalScore(int a)
        {
            int res = 0;
            if (a % FACTOR_P == 0)
                res++;
            if (a % FACTOR_X == 0)
                res++;
            return res;
        }

        public void ReadData()
        {
            int[] a = ReadIntArray();
            N = a[0];
            M = a[1];
            c = new int[N][];
            initC = new int[N][];
            posi = new int[N][];
            for (int i = 0; i < N; i++)
            {
                c[i] = new int[N];
                initC[i] = new int[N];
                posi[i] = new int[N];
                for (int j = 0; j < N; j++)
                {
                    c[i][j] = 1;
                    initC[i][j] = 1;
                    posi[i][j] = FACTOR_O;
                }
            }
            orginalScore = 0;
            for (int i = 0; i < M; i++)
            {
                string[] s = ReadStringArray();
                int x = Convert.ToInt32(s[1]);
                int y = Convert.ToInt32(s[2]);
                //c[x - 1][y - 1] = s[0][0];
                if (s[0][0] == '+')
                {
                    c[x - 1][y - 1] = FACTOR_P;
                }
                else if (s[0][0] == 'x')
                {
                    c[x - 1][y - 1] = FACTOR_X;
                }
                else if (s[0][0] == 'o')
                {
                    c[x - 1][y - 1] = FACTOR_O;
                }
                initC[x - 1][y - 1] = c[x - 1][y - 1];

                if (s[0][0] == 'x' || s[0][0] == '+') orginalScore++;
                else if (s[0][0] == 'o') orginalScore += 2;
            }

            row = new int[N];
            for (int i = 0; i < N; i++)
            {
                row[i] = 1;
                for (int j = 0; j < N; j++)
                {
                    row[i] *= c[i][j];
                    row[i] = Round(row[i]);
                }
            }

            col = new int[N];
            for (int j = 0; j < N; j++)
            {
                col[j] = 1;

                for (int i = 0; i < N; i++)
                {
                    col[j] *= c[i][j];
                    col[j] = Round(col[j]);
                }
            }


            dig1 = new int[2 * N];
            dig2 = new int[2 * N];
            for (int k = 0; k < 2 * N; k++)
            {
                dig1[k] = 1;
                dig2[k] = 1;
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    dig1[i - j + N] *= c[i][j];
                    dig1[i - j + N] = Round(dig1[i - j + N]);
                    dig2[i + j] *= c[i][j];
                    dig2[i + j] = Round(dig2[i + j]);
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    posi[i][j] = FACTOR_O;
                    if (row[i] % FACTOR_X == 0 && posi[i][j] % FACTOR_X == 0)
                    {
                        posi[i][j] /= FACTOR_X;
                    }
                    if (col[j] % FACTOR_X == 0 && posi[i][j] % FACTOR_X == 0)
                    {
                        posi[i][j] /= FACTOR_X;
                    }
                    if (dig1[i - j + N] % FACTOR_P == 0 && posi[i][j] % FACTOR_P == 0)
                    {
                        posi[i][j] /= FACTOR_P;
                    }
                    if (dig2[i + j] % FACTOR_P == 0 && posi[i][j] % FACTOR_P == 0)
                    {
                        posi[i][j] /= FACTOR_P;
                    }
                }
            }

        }

        public char GetChar(int a)
        {
            if (a == FACTOR_O)
                return 'o';
            if (a == FACTOR_P)
                return '+';
            if (a == FACTOR_X)
                return 'x';
            return ' ';
        }

        //public bool IsSatish(int i, int j)
        //{
        //    return rowO[i] + rowX[i] <= 1
        //        && colO[j] + colX[j] <= 1
        //        && dig1O[i - j + N] + dig1P[i - j + N] <= 1
        //        && dig2O[i + j] + dig2P[i + j] <= 1;
        //}

        //public void ReplaceChar(int x, int y, char oldC, char newC)
        //{
        //    switch (oldC)
        //    {
        //        case '+':
        //            rowP[x]--;
        //            colP[y]--;
        //            dig1P[x - y + N]--;
        //            dig2P[x + y]--;
        //            break;
        //        case 'x':
        //            rowX[x]--;
        //            colX[y]--;
        //            dig1X[x - y + N]--;
        //            dig2X[x + y]--;
        //            break;
        //        case 'o':
        //            rowO[x]--;
        //            colO[y]--;
        //            dig1O[x - y + N]--;
        //            dig2O[x + y]--;
        //            break;
        //    }

        //    switch (newC)
        //    {
        //        case '+':
        //            rowP[x]++;
        //            colP[y]++;
        //            dig1P[x - y + N]++;
        //            dig2P[x + y]++;
        //            break;
        //        case 'x':
        //            rowX[x]++;
        //            colX[y]++;
        //            dig1X[x - y + N]++;
        //            dig2X[x + y]++;
        //            break;
        //        case 'o':
        //            rowO[x]++;
        //            colO[y]++;
        //            dig1O[x - y + N]++;
        //            dig2O[x + y]++;
        //            break;
        //    }
        //    c[x][y] = newC;
        //}

        //public void Com(int res)
        //{
        //    for (int ind = 0; ind < N * N; ind++)
        //    {
        //        int i = ind / N;
        //        int j = ind % N;
        //        char oldC = c[i][j];
        //        if (oldC == '.')
        //        {
        //            ReplaceChar(i, j, oldC, 'o');
        //            if (IsSatish(i, j))
        //            {
        //                var ele = new Ele('o', i, j);
        //                result.Add(ele);
        //                Com(res + 2);
        //                result.Remove(ele);
        //            }
        //            ReplaceChar(i, j, 'o', oldC);

        //            ReplaceChar(i, j, oldC, '+');
        //            if (IsSatish(i, j))
        //            {
        //                var ele = new Ele('+', i, j);
        //                result.Add(ele);
        //                Com(res + 1);
        //                result.Remove(ele);
        //            }
        //            ReplaceChar(i, j, '+', oldC);


        //            ReplaceChar(i, j, oldC, 'x');
        //            if (IsSatish(i, j))
        //            {
        //                var ele = new Ele('x', i, j);
        //                result.Add(ele);
        //                Com(res + 1);
        //                result.Remove(ele);
        //            }
        //            ReplaceChar(i, j, 'x', oldC);


        //        }
        //        else if (oldC != 'o')
        //        {
        //            ReplaceChar(i, j, oldC, 'o');
        //            if (IsSatish(i, j))
        //            {
        //                var ele = new Ele('o', i, j);
        //                result.Add(ele);
        //                Com(res + 1);
        //                result.Remove(ele);
        //            }
        //            ReplaceChar(i, j, 'o', oldC);
        //        }

        //        if (maxIncreasing < res)
        //        {
        //            maxIncreasing = res;
        //            Console.WriteLine(maxIncreasing + " " + result.Count);
        //            final.Clear();
        //            final.AddRange(result);
        //        }
        //    }

        //}

        public void Process()
        {
            maxIncreasing = 0;

            //for x
            while (true)
            {
                int minPosiDesc = Int32.MaxValue;
                int rX = -1, rY = -1;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++) if (posi[i][j] % FACTOR_X == 0)
                        {
                            int tPosi = 0;
                            for (int k = 0; k < N; k++)
                            {
                                if (posi[i][k] % FACTOR_X == 0)
                                {
                                    tPosi++;
                                }
                                if (posi[k][j] % FACTOR_X == 0)
                                {
                                    tPosi++;
                                }

                            }

                            if (minPosiDesc > tPosi )
                            {
                                minPosiDesc = tPosi;
                                rX = i;
                                rY = j;
                            }
                        }
                }

                if (rX < 0) break;

                maxIncreasing++;
                c[rX][rY] *= FACTOR_X;

                for (int k = 0; k < N; k++)
                {
                    if (posi[rX][k] % FACTOR_X == 0)
                    {
                        posi[rX][k] /= FACTOR_X;
                    }
                    if (posi[k][rY] % FACTOR_X == 0)
                    {
                        posi[k][rY] /= FACTOR_X;
                    }

                }
            }

            //for +
            while (true)
            {
                int minPosiDesc = Int32.MaxValue;
                int rX = -1, rY = -1;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++) if (posi[i][j] % FACTOR_P == 0)
                        {
                            int tPosi = 0;
                            for (int k = -N; k <= N; k++)
                            {
                                if (i + k >=0 && i + k < N && j + k >=0 && j + k < N && posi[i + k][j + k] % FACTOR_P == 0)
                                {
                                    tPosi++;
                                }
                                if (i - k >= 0 && i - k < N && j + k >=0 && j + k < N && posi[i - k][j + k] % FACTOR_P == 0)
                                {
                                    tPosi++;
                                }
                            }

                            if (minPosiDesc > tPosi)
                            {
                                minPosiDesc = tPosi;
                                rX = i;
                                rY = j;
                            }
                        }
                }

                if (rX < 0) break;

                maxIncreasing ++;
                c[rX][rY] *= FACTOR_P;
                                
                for (int k = -N; k <= N; k++)
                {
                    if (rX + k >= 0 && rX + k < N && rY + k >= 0 && rY + k < N && posi[rX + k][rY + k] % FACTOR_P == 0)
                    {
                        posi[rX + k][rY + k] /= FACTOR_P;
                    }
                    if (rX - k >= 0 && rX - k < N && rY + k >= 0 && rY + k < N && posi[rX - k][rY + k] % FACTOR_P == 0)
                    {
                        posi[rX - k][rY + k] /= FACTOR_P;
                    }
                }
            }

            _fileOut.Write((maxIncreasing + orginalScore) + " ");
            int countChange = 0;
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N; j++)
                {
                    if(c[i][j] != initC[i][j])
                    {
                        countChange++;
                    }
                }
            }
            _fileOut.WriteLine(countChange);


            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (c[i][j] != initC[i][j])
                    {
                        _fileOut.WriteLine("{0} {1} {2}", GetChar(c[i][j]), i + 1, j + 1);
                    }
                }
            }
            
        }
    }
}
