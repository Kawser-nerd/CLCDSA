using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014
{
    class Program
    {
        static List<string> QualA(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int ans1, ans2;
            List<int> arr1 = new List<int>();
            List<int> arr2 = new List<int>();
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                ans1 = Int32.Parse(input[line++]);
                line += ans1 - 1;
                string[] s1 = input[line].Split(new Char[] { ' ' });
                line += 5 - ans1;
                foreach (string r in s1)
                {
                    arr1.Add(Int32.Parse(r));
                }


                ans2 = Int32.Parse(input[line++]);
                line += ans2 - 1;
                string[] s2 = input[line].Split(new Char[] { ' ' });
                line += 5 - ans2;
                foreach (string r in s2)
                {
                    arr2.Add(Int32.Parse(r));
                }

                int count = 0;
                int match = 1;
                foreach (int i1 in arr1)
                {
                    foreach (int i2 in arr2)
                    {
                        if (i1 == i2)
                        {
                            match = i1;
                            count++;
                        }
                    }
                }
                if (count == 1)
                {
                    output.Add("Case #" + i + ": " + match);
                }
                else if (count > 1)
                {
                    output.Add("Case #" + i + ": Bad magician!");
                }
                else
                {
                    output.Add("Case #" + i + ": Volunteer cheated!");
                }
                arr1.Clear();
                arr2.Clear();
            }
            return output;
        }
        static List<string> QualB(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                string[] param = input[line++].Split(new Char[] { ' ' });
                double C = Double.Parse(param[0]);
                double F = Double.Parse(param[1]);
                double X = Double.Parse(param[2]);
                double currProd = 2.0;
                double mintime = 0.0;
                double timewithoutbuy = X / currProd;
                double timeafterbuy = C / currProd + X / (currProd + F);
                double prevTime=0;
                mintime = (timewithoutbuy < timeafterbuy) ? timewithoutbuy : timeafterbuy;
                while (timeafterbuy < timewithoutbuy)
                {
                    timeafterbuy = prevTime + C / currProd + X / (currProd + F);
                    timewithoutbuy = prevTime + X / currProd;
                    if (timewithoutbuy < timeafterbuy)
                        break;
                    else
                    {
                        prevTime += C / currProd;
                    }
                    mintime = (timewithoutbuy < timeafterbuy) ? timewithoutbuy : timeafterbuy;
                    currProd += F;
                }
                output.Add("Case #" + i + ": " + mintime.ToString("F7", CultureInfo.InvariantCulture));
            }
            return output;
        }
        static bool isPrime(int number)
        {

            if (number == 1) return false;
            if (number == 2) return true;

            for (int i = 3; i < number; i += 2)
            {
                if (number % i == 0) return false;
            }

            return true;

        }
        static List<string> QualC(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int t = 1; t <= tc; t++)
            {
                string[] param = input[line++].Split(new Char[] { ' ' });
                int R = Int32.Parse(param[0]);
                int C = Int32.Parse(param[1]);
                int M = Int32.Parse(param[2]);
                output.Add("Case #" + t + ":");
                int empty = R * C - M;
                if (empty == 1)
                {
                    string s = "c";
                    for (int i = 1; i < C; i++)
                    {
                        s += "*";
                    }
                    output.Add(s);
                    s = "";
                    for (int i = 1; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            s += "*";
                        }
                        output.Add(s);
                        s = "";
                    }
                }
                else if (R == 1 && C == 1)
                {
                    output.Add("c");
                }
                else if (R == 1 || C == 1)
                {
                    if (empty < 2)
                    {
                        output.Add("Impossible");
                    }
                    else
                    {
                        if (R == 1)
                        {
                            string s = "c";
                            for (int x = 0; x < empty - 1; x++)
                                s += ".";
                            for (int x = 0; x < M; x++)
                                s += "*";
                            output.Add(s);
                        }
                        else
                        {
                            output.Add("c");
                            for (int x = 0; x < empty - 1; x++)
                                output.Add(".");
                            for (int x = 0; x < M; x++)
                                output.Add("*");
                        }
                    }
                }
                else if (R == 2 || C == 2)
                {
                    if (empty % 2 != 0 || empty < 4)
                    {
                        output.Add("Impossible");
                    }
                    else
                    {
                        if (R == 2)
                        {
                            string s = "c";
                            for (int x = 1; x < empty / 2; x++)
                                s += ".";
                            for (int x = empty / 2; x < C; x++)
                                s += "*";
                            output.Add(s);
                            s = "";
                            for (int x = 0; x < empty / 2; x++)
                                s += ".";
                            for (int x = empty / 2; x < C; x++)
                                s += "*";
                            output.Add(s);
                        }
                        else
                        {
                            string s = "c.";
                            output.Add(s);
                            for (int x = 1; x < empty / 2; x++)
                            {
                                s = "..";
                                output.Add(s);
                            }
                            for (int x = empty / 2; x < R; x++)
                            {
                                s = "**";
                                output.Add(s);
                            }
                        }
                    }
                }
                else
                {
                    //Console.WriteLine(t+":"+empty);
                    //Console.ReadKey();
                    bool impossible = false;
                    char[,] board = new char[50, 50];
                    for (int i = 0; i < 50; i++)
                        for (int j = 0; j < 50; j++)
                            board[i, j] = '*';
                    int startR = 0, startC = 0;
                    if (empty == 2 || empty == 3 || empty == 5 || empty == 7)
                    {
                        //Console.WriteLine(t + ":" + empty);
                        //Console.ReadKey();
                        output.Add("Impossible");
                        impossible = true;
                    }
                    else if (empty == 9)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (board[i, j] == '*')
                                {
                                    empty--;
                                }
                                board[i, j] = '.';

                            }
                        }
                    }
                    //else if (empty == 8)
                    //{
                    //    if (R >= 4)
                    //    {
                    //        for (int i = 0; i < 4; i++)
                    //        {
                    //            for (int j = 0; j < 2; j++)
                    //            {
                    //                if (board[i, j] == '*')
                    //                {
                    //                    empty--;
                    //                }
                    //                board[i, j] = '.';

                    //            }
                    //        }
                    //    }
                    //    else if (C >= 4)
                    //    {
                    //        for (int i = 0; i < 2; i++)
                    //        {
                    //            for (int j = 0; j < 4; j++)
                    //            {
                    //                if (board[i, j] == '*')
                    //                {
                    //                    empty--;
                    //                }
                    //                board[i, j] = '.';

                    //            }
                    //        }
                    //    }
                    //}
                    //else if (empty == 6)
                    //{
                    //    for (int i = 0; i < 3; i++)
                    //    {
                    //        for (int j = 0; j < 2; j++)
                    //        {
                    //            if (board[i, j] == '*')
                    //            {
                    //                empty--;
                    //            }
                    //            board[i, j] = '.';

                    //        }
                    //    }
                    //}
                    else if (empty >= 4)
                    {
                        //Console.WriteLine("4");
                        //Console.ReadKey();
                        for (int i = 0; i < 2; i++)
                        {
                            for (int j = 0; j < 2; j++)
                            {
                                if (board[i, j] == '*')
                                {
                                    empty--;
                                    //Console.WriteLine(empty);
                                    //Console.ReadKey();
                                }
                                board[i, j] = '.';

                            }
                        }
                    }
                    //else if (empty == 1)
                    //{
                    //    empty = 0;
                    //}
                    if (!impossible)
                    {
                        while (empty > 0)
                        {
                            int flag = 0;
                            int f=0;
                                                        
                            if (empty == 3||empty==5||empty==7||empty==9)
                            {
                                f = 0;
                                for (int i = 0; i < R; i++)
                                {
                                    for (int j = 0; j < C; j++)
                                    {
                                        if ((i + 2 < R && board[i, j] == '*' && board[i + 1, j] == '*' && board[i + 2, j] == '*')&&
                                        ((j - 1 >= 0 && board[i, j - 1] == '.' && board[i + 1, j - 1] == '.' && board[i + 2, j - 1] == '.') || (j + 1 < C && board[i, j + 1] == '.' && board[i + 1, j + 1] == '.' && board[i + 2, j+1] == '.')))
                                            {
                                                board[i, j] = board[i + 1, j] = board[i + 2, j] ='.';
                                                empty -= 3;
                                                f = 1;
                                                break;
                                            }
                                        else if ((j + 2 < C && board[i, j] == '*' && board[i, j + 1] == '*' && board[i, j+2] == '*')
                                        &&(((i + 1 < R && board[i + 1, j] == '.' && board[i + 1, j + 1] == '.' && board[i + 1, j + 2] == '.') || (i - 1 >= 0 && board[i - 1, j] == '.' && board[i - 1, j + 1] == '.' && board[i - 1, j+2] == '.'))))
                                            {
                                                //Console.WriteLine("called2");
                                                //Console.ReadKey();
                                                board[i, j] = board[i, j + 1] =board[i, j+2] = '.';
                                                empty -= 3;
                                                f = 1;
                                                break;
                                            }
                                    }
                                    if (f == 1)
                                        break;
                                }
                            }
                            if (empty % 2 == 0 || empty > 9 || f==0)
                            {
                                f = 0;
                                for (int i = 0; i < R; i++)
                                {
                                    for (int j = 0; j < C; j++)
                                    {
                                        if ((i + 1 < R && board[i, j] == '*' && board[i + 1, j] == '*')
                                        && ((j - 1 >= 0 && board[i, j - 1] == '.' && board[i + 1, j - 1] == '.') || (j + 1 < C && board[i, j + 1] == '.' && board[i + 1, j + 1] == '.')))
                                        {
                                            board[i, j] = board[i + 1, j] = '.';
                                            empty -= 2;
                                            f = 1;
                                            break;
                                        }
                                        else if ((j + 1 < C && board[i, j] == '*' && board[i, j + 1] == '*') &&
                                        ((i + 1 < R && board[i + 1, j] == '.' && board[i + 1, j + 1] == '.') || (i - 1 >= 0 && board[i - 1, j] == '.' && board[i - 1, j + 1] == '.')))
                                        {
                                            board[i, j] = board[i, j + 1] = '.';
                                            empty -= 2;
                                            f = 1;
                                            break;
                                        }
                                    }
                                    if (f == 1)
                                        break;
                                }
                            }
                            if (empty == 1 || f==0)
                            {
                                f = 0;
                                for (int i = 0; i < R - 2; i++)
                                {
                                    for (int j = 0; j < C - 2; j++)
                                    {
                                        if (board[i, j + 1] == '.' && board[i + 1, j] == '.' && board[i + 1, j + 1] == '.' && board[i + 1, j + 2] == '.' && board[i + 2, j + 1] == '.')
                                        {
                                            if (board[i, j] == '.' && board[i, j + 2] == '.' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '*')
                                            {
                                                board[i + 2, j + 2] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                            else if (board[i, j] == '.' && board[i, j + 2] == '.' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '.')
                                            {
                                                board[i + 2, j] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                            else if (board[i, j] == '.' && board[i, j + 2] == '*' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '.')
                                            {
                                                board[i, j + 2] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                            else if (board[i, j] == '*' && board[i, j + 2] == '.' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '.')
                                            {
                                                board[i, j] = '.';
                                                f = 1;
                                                empty--;
                                                break;
                                            }
                                        }
                                    }
                                    if (f == 1)
                                        break;
                                }
                                if (f == 0)
                                {
                                    break;
                                }
                            }
                            //else if (empty == 5)
                            //{
                            //    f = 0;
                            //    for (int i = 0; i < R - 2; i++)
                            //    {
                            //        for (int j = 0; j < C - 2; j++)
                            //        {
                            //            if (board[i + 1, j + 1] == '.')
                            //            {
                            //                if (board[i, j + 1] == '.' && board[i + 1, j] == '.' && board[i, j] == '.' && board[i, j + 2] == '*' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '*' && board[i + 1, j + 2] == '*' && board[i + 2, j + 1] == '*')
                            //                {
                            //                    board[i, j + 2] = board[i + 2, j] = board[i + 2, j + 2] = board[i + 1, j + 2] = board[i + 2, j + 1] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //                else if (board[i, j + 1] == '.' && board[i + 1, j] == '*' && board[i, j] == '*' && board[i, j + 2] == '.' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '*' && board[i + 1, j + 2] == '.' && board[i + 2, j + 1] == '*')
                            //                {
                            //                    board[i + 1, j] = board[i, j] = board[i + 2, j] = board[i + 2, j + 2] = board[i + 2, j + 1] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //                else if (board[i, j + 1] == '*' && board[i + 1, j] == '*' && board[i, j] == '*' && board[i, j + 2] == '*' && board[i + 2, j] == '*' && board[i + 2, j + 2] == '.' && board[i + 1, j + 2] == '.' && board[i + 2, j + 1] == '.')
                            //                {
                            //                    board[i, j + 1] = board[i + 1, j] = board[i, j] = board[i, j + 2] = board[i + 2, j] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //                else if (board[i, j + 1] == '*' && board[i + 1, j] == '.' && board[i, j] == '*' && board[i, j + 2] == '*' && board[i + 2, j] == '.' && board[i + 2, j + 2] == '*' && board[i + 1, j + 2] == '*' && board[i + 2, j + 1] == '.')
                            //                {
                            //                    board[i + 2, j + 2] = board[i + 1, j + 2] = board[i, j + 2] = board[i, j] = board[i, j + 1] = '.';
                            //                    f = 1;
                            //                    empty -= 5;
                            //                    break;
                            //                }
                            //            }
                            //        }
                            //        if (f == 1)
                            //            break;
                            //    }
                            //    if (f == 0)
                            //    {
                            //        break;
                            //    }
                            //}
                            //else
                            //{

                            //    if (startC + 2 < C && startR + 2 < R)
                            //    {
                            //        for (int i = startR; i < startR + 3; i++)
                            //        {
                            //            for (int j = startC; j < startC + 3; j++)
                            //            {
                            //                if (i >= 0 && j >= 0 && i < R && j < C)
                            //                {
                            //                    if (board[i, j] == '*')
                            //                    {
                            //                        empty--;
                            //                        flag = 1;
                            //                    }
                            //                    board[i, j] = '.';
                            //                }
                            //            }
                            //        }
                            //    }
                            //    if (flag == 0)
                            //        break;
                            //}
                            //for (int i = 0; i < R; i++)
                            //{
                            //    for (int j = 0; j < C; j++)
                            //    {
                            //        Console.Write(board[i, j]);
                            //    }
                            //    Console.WriteLine();
                            //}
                            //Console.ReadKey();
                        }
                        if (empty == 0)
                        {
                            board[0, 0] = 'c';
                            for (int r = 0; r < R; r++)
                            {
                                string s = "";
                                for (int c = 0; c < C; c++)
                                {
                                    s += board[r, c].ToString();
                                }
                                output.Add(s);
                            }
                        }
                        else
                        {
                            output.Add("Impossible");
                        }
                    }
                }
            }
            return output;
        }
        static List<string> QualD(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int t = 1; t <= tc; t++)
            {
                int DW = 0, W = 0;
                List<double> Naomi = new List<double>();
                List<double> Ken = new List<double>();
                int N = Int32.Parse(input[line++]);
                string[] n = input[line++].Split(new Char[] { ' ' });
                string[] k = input[line++].Split(new Char[] { ' ' });
                for (int i = 0; i < N; i++)
                {
                    Naomi.Add(Double.Parse(n[i]));
                    Ken.Add(Double.Parse(k[i]));
                }
                List<double> Sortedken = new List<double>(Ken);
                List<double> Naomicopy = new List<double>(Naomi);
                Sortedken.Sort();
                Naomicopy.Sort();
                //for (int i = 0; i < Naomicopy.Count; i++)
                //{
                //    Console.Write(Naomicopy[i] + " ");
                //}
                //Console.WriteLine();
                //for (int i = 0; i < Sortedken.Count; i++)
                //{
                //    Console.Write(Sortedken[i] + " ");
                //}
                //Console.WriteLine();
                while (true)
                {
                    if (Naomi.Count == 0)
                    {
                        //DW += Naomi.Count;
                        break;
                    }
                    if (Naomi.Min() > Ken.Min())
                    {
                        Naomi.Remove(Naomi.Min());
                        Ken.Remove(Ken.Min());
                        DW++;
                    }
                    else
                    {
                        Naomi.Remove(Naomi.Min());
                        Ken.Remove(Ken.Max());
                    }
                    //for (int i = 0; i < Naomi.Count; i++)
                    //{
                    //    Console.Write(Naomi[i] + " ");
                    //}
                    //Console.WriteLine();
                    //for (int i = 0; i < Ken.Count; i++)
                    //{
                    //    Console.Write(Ken[i] + " ");
                    //}
                    //Console.WriteLine();
                }
                //Console.WriteLine("Count" + Sortedken.Count);
                //for (int i = 0; i < Sortedken.Count; i++)
                //{
                //    Console.WriteLine("S:"+Sortedken[i]);
                //}
                for (int i = 0; i < Naomicopy.Count; i++)
                {
                    int j;
                    for (j = 0; j < Sortedken.Count; j++)
                    {
                        if (Sortedken[j] > Naomicopy[i])
                        {
                            break;
                        }
                    }
                    if (j != Sortedken.Count)
                    {
                        //Console.WriteLine(i + " " + Naomicopy[i] + " " + Sortedken[j]);
                        Sortedken.Remove(Sortedken[j]);
                    }
                }
                //Console.WriteLine(W);
                W += Sortedken.Count;
                //Console.WriteLine(W);
                output.Add("Case #" + t + ": " + DW + " " + W);
                Console.WriteLine("Case #" + t + ": " + DW + " " + W);
            }
            Console.ReadKey();
            return output;
        }
        static List<string> R1A_A(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            int N, L;
            for (int i = 1; i <= tc; i++)
            {
                string[] nl = input[line++].Split(new Char[] { ' ' });
                N = Int32.Parse(nl[0]);
                L = Int32.Parse(nl[1]);
                int flag=0;
                string[] initial = input[line++].Split(new Char[] { ' ' });
                string[] required = input[line++].Split(new Char[] { ' ' });
                for (int j = 0; j < L; j++)
                {
                    int Izeros = 0, Iones = 0;
                    int Rzeros = 0, Rones = 0;
                    foreach (string ini in initial)
                    {
                        if (ini[j] == '1')
                            Iones++;
                        else
                            Izeros++;
                    }
                    foreach (string ini in required)
                    {
                        if (ini[j] == '1')
                            Rones++;
                        else
                            Rzeros++;
                    }
                    if (!((Izeros == Rzeros && Iones == Rones) || (Izeros == Rones && Iones == Rzeros)))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    output.Add("Case #" + i + ": NOT POSSIBLE");
                }
                else
                {
                    HashSet<string> set = new HashSet<string>();
                    HashSet<string> reqSet = new HashSet<string>();
                    for (int c = 0; c < N; c++)
                    {
                        reqSet.Add(required[c]);
                    }
                    //0
                    for (int c = 0; c < N; c++)
                    {
                        set.Add(initial[c]);
                    }
                    if (set.SetEquals(reqSet))
                    {
                        output.Add("Case #" + i + ": 0");
                        continue;
                    }
                    set.Clear();
                    //1
                    for (int a = 0; a < L; a++)
                    {
                        for (int z = 0; z < N; z++)
                        {
                            StringBuilder s = new StringBuilder();
                            for (int y = 0; y < L; y++)
                            {
                                if (y == a)
                                {
                                    if (initial[z][a] == '1')
                                        s.Append('0');
                                    else
                                        s.Append('1');
                                }
                                else
                                {
                                    s.Append(initial[z][a]);
                                }
                            }
                            set.Add(s.ToString());
                        }
                    }
                    if (set.SetEquals(reqSet))
                    {
                        output.Add("Case #" + i + ": 1");
                        continue;
                    }
                    set.Clear();


                    for (int b = 0; b < L-1; b++)
                    {
                        for (int a = b+1; a < L; a++)
                        {
                            for (int z = 0; z < N; z++)
                            {
                                StringBuilder s = new StringBuilder();
                                for (int y = 0; y < L; y++)
                                {
                                    if (y == a)
                                    {
                                        if (initial[z][a] == '1')
                                            s.Append('0');
                                        else
                                            s.Append('1');
                                    }
                                    else
                                    {
                                        s.Append(initial[z][a]);
                                    }
                                }
                                set.Add(s.ToString());
                            }
                        }
                    }
                    if (set.SetEquals(reqSet))
                    {
                        output.Add("Case #" + i + ": 2");
                        continue;
                    }
                    set.Clear();

                    for (int c = 0; c < L - 2; c++)
                    {
                        for (int b = c + 1; b < L - 1; b++)
                        {
                            for (int a = b + 1; a < L; a++)
                            {
                                for (int z = 0; z < N; z++)
                                {
                                    StringBuilder s = new StringBuilder();
                                    for (int y = 0; y < L; y++)
                                    {
                                        if (y == a)
                                        {
                                            if (initial[z][a] == '1')
                                                s.Append('0');
                                            else
                                                s.Append('1');
                                        }
                                        else
                                        {
                                            s.Append(initial[z][a]);
                                        }
                                    }
                                    set.Add(s.ToString());
                                }
                            }
                        }
                    }
                    if (set.SetEquals(reqSet))
                    {
                        output.Add("Case #" + i + ": 3");
                        continue;
                    }
                    set.Clear();


                    for (int d = 0; d < L - 3; d++)
                    {
                        for (int c = d+1; c < L - 2; c++)
                        {
                            for (int b = c + 1; b < L - 1; b++)
                            {
                                for (int a = b + 1; a < L; a++)
                                {
                                    for (int z = 0; z < N; z++)
                                    {
                                        StringBuilder s = new StringBuilder();
                                        for (int y = 0; y < L; y++)
                                        {
                                            if (y == a)
                                            {
                                                if (initial[z][a] == '1')
                                                    s.Append('0');
                                                else
                                                    s.Append('1');
                                            }
                                            else
                                            {
                                                s.Append(initial[z][a]);
                                            }
                                        }
                                        set.Add(s.ToString());
                                    }
                                }
                            }
                        }
                    }
                    if (set.SetEquals(reqSet))
                    {
                        output.Add("Case #" + i + ": 4");
                        continue;
                    }
                    set.Clear();
                }
            }
            return output;
        }
        static int NumNodes(int N, int node, int parent, int[,] board)
        {
            List<int> children = new List<int>();
            for (int i = 1; i <= N; i++)
            {
                if (board[node, i] == 1 && i != parent)
                {
                    children.Add(i);
                }
            }
            if (children.Count <= 1)
            {
                return 1;
            }
            else if (children.Count == 2)
            {
                return NumNodes(N, children[0], node, board) + NumNodes(N, children[1], node, board) + 1;
            }
            else
            {
                int maxsize = -1;
                for (int i = 0; i < children.Count - 1; i++)
                {
                    for (int j = i + 1; j < children.Count; j++)
                    {
                        int size = NumNodes(N, children[i], node, board) + NumNodes(N, children[j], node, board);
                        if (maxsize < size)
                        {
                            maxsize = size;
                        }
                    }
                }
                return maxsize + 1;
            }
        }
        static List<string> R1A_B(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int N;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                N = Int32.Parse(input[line++]);
                int[,] board = new int[1001, 1001];
                for(int j=1;j<=N;j++)
                    for(int k=1;k<=N;k++)
                        board[j,k]=0;
                for (int j = 0; j < N - 1; j++)
                {
                    string[] sd = input[line++].Split(new Char[] { ' ' });
                    int source = Int32.Parse(sd[0]);
                    int dest = Int32.Parse(sd[1]);
                    board[source, dest] = board[dest, source] = 1;
                }
                int max = -1;
                for (int j = 1; j <= N; j++)
                {
                    int x = NumNodes(N, j, 0, board);
                    //Console.WriteLine(j + " " + x);
                    if (max < x)
                    {
                        max = x;
                    }
                }
                output.Add("Case #" + i + ": " + (N - max));
                //Console.ReadKey();
            }
            return output;
        }
        static List<string> R1A_C(string[] input)
        {
            List<string> output = new List<string>();
            //int line = 0;
            //int tc = Int32.Parse(input[line++]);
            Random random = new Random();
            
            for (int i = 1; i <= 120; i++)
            {
                int randomNumber = random.Next(0, 100);
                if(randomNumber>50)
                    output.Add("Case #" + i + ": GOOD");
                else
                    output.Add("Case #" + i + ": BAD");
            }
            return output;
        }
        static List<string> R1B_A(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            long N;
            long wins;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                wins = 0;
                N = Int32.Parse(input[line++]);
                List<string> lines = new List<string>();
                for (int j = 0; j < N; j++)
                {
                    lines.Add(input[line++]);
                }
                int flag=0;
                for (int j = 1; j < N; j++)
                {
                    if (!(lines[j-1] == lines[j]))
                    {
                        flag=1;
                    }
                }
                if (flag == 0)
                {
                    output.Add("Case #" + i + ": 0");
                }
                else
                {
                    string prev = "";
                    StringBuilder s1 = new StringBuilder();
                    StringBuilder s2 = new StringBuilder();
                    flag=0;
                    char p='-';
                    for (int j = 0; j < N; j++)
                    {
                        if (j == 0)
                        {
                            foreach (char ch in lines[j])
                            {
                                if (ch != p)
                                {
                                    p = ch;
                                    s1.Append(ch);
                                }
                            }
                        }
                        else
                        {
                            p = '-';
                            foreach (char ch in lines[j])
                            {
                                if (ch != p)
                                {
                                    p = ch;
                                    s2.Append(ch);
                                }
                            }
                            if (s2.ToString() != s1.ToString())
                            {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    System.Console.WriteLine(s1);
                    if (flag == 1)
                    {
                        output.Add("Case #" + i + ": Fegla Won");
                    }
                    else
                    {
                        string master = lines[0];
                        int x1 = 0, x2 = 0;
                        int i1 = 0, i2 = 0;
                        for (int j = 1; j < N; j++)
                        {
                            foreach (char ch in s1.ToString())
                            {
                                x1 = x2 = 0;
                                //System.Console.WriteLine(ch);
                                while (i1 < master.Length && master[i1++] == ch)
                                {
                                    x1++;
                                }
                                while (i2 < lines[j].Length && lines[j][i2++] == ch)
                                {
                                    x2++;
                                }
                                wins += Math.Abs(x1 - x2);
                            }
                        }
                        
                        wins = Math.Abs(wins);
                        //System.Console.ReadKey();
                        output.Add("Case #" + i + ": " + wins);
                    }
                }
            }
            System.Console.ReadKey();
            return output;
        }
        static List<string> R1B_B(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            long A, B, K;
            long wins;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                wins = 0;
                string[] abk = input[line++].Split(new Char[] { ' ' });
                A = Int64.Parse(abk[0]);
                B = Int64.Parse(abk[1]);
                K = Int64.Parse(abk[2]);
                for (long j = 0; j < A; j++)
                {
                    for (long k = 0; k < B; k++)
                    {
                        if ((j & k) < K)
                        {
                            wins++;
                        }
                    }
                }
                output.Add("Case #" + i + ": " + wins);
                //Console.ReadKey();
            }
            return output;
        }
        static List<string> R1C_A(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                string[] pq = input[line++].Split(new Char[] { '/' });
                int p = Int32.Parse(pq[0]);
                int q = Int32.Parse(pq[1]);
                float ancestor = 1;
                int x;
                for (x = 1; x <= 40; x++)
                {
                    ancestor /= 2;
                    if(ancestor < (float)p/q)
                        break;
                }
                if (x == 41)
                {
                    output.Add("Case #" + i + ": impossible");
                }
                else
                {
                    output.Add("Case #" + i + ": " + (x-1));
                }
            }
            //System.Console.ReadKey();
            return output;
        }
        static bool valid(string st)
        {          
            bool[] status = new bool[26];
            for (int k = 0; k < 26; k++)
            {
                status[k] = false;
            }
            char prev = '-';
            int flag = 0;
            foreach (char ch in st)
            {
                if (status[ch - 'a'] == false)
                {
                    //sb.Append(ch);
                    status[ch - 'a'] = true;
                    prev = ch;
                }
                else
                {
                    if (ch != prev && prev != '-')
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)
            {
                return true;
            }
            return false;
        }
        static List<int[]> seq(string[] trains,int i, int j)
        {
            if (i == j - 1)
            {
                List<int[]> newlist = new List<int[]>();
                int[] s1 = { i, j };
                newlist.Add(s1);
                int[] s2 = { j, i };
                newlist.Add(s2);
                return newlist;
            }
            else
            {
                List<int[]> s = seq(trains, i + 1, j);
                List<int[]> newlist = new List<int[]>();
                foreach (int[] l in s)
                {
                    for (int x = 0; x < j - i + 1; x++)
                    {
                        ArrayList myAL = new ArrayList(l);
                        if (x == j - i + 1)
                        {
                            myAL.Add(i);
                        }
                        else
                        {
                            myAL.Insert(x, i);
                        }
                        int[] s2 = (int[])myAL.ToArray(typeof(int));
                        string train = "";
                        int flag = 0;
                        foreach (int bog in s2)
                        {
                            //System.Console.Write(bog);
                            train = String.Concat(train, trains[bog]);
                            if (!valid(train))
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag==0)
                            newlist.Add(s2);
                    }
                }
                return newlist;
            }
        }
        static List<string> R1C_B(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int n;
            long result;
            int tc = Int32.Parse(input[line++]);
            for (int i = 1; i <= tc; i++)
            {
                result = 0;
                int flag = 0;
                n = Int32.Parse(input[line++]);
                string[] trains = input[line++].Split(new Char[] { ' ' });
                foreach (string train in trains)
                {
                    if (!valid(train))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    List<int[]> list = seq(trains, 0, n - 1);
                    foreach (int[] s in list)
                    {
                        //System.Console.WriteLine("seq:");
                        string train = "";
                        foreach (int bog in s)
                        {
                            //System.Console.Write(bog);
                            train = String.Concat(train, trains[bog]);
                            if (!valid(train))
                                break;
                        }
                        //System.Console.WriteLine(train);
                        if (valid(train))
                        {
                            result++;
                            result = result % 1000000007;
                        }
                    }
                }
                output.Add("Case #" + i + ": " + result);
                System.Console.WriteLine(i);
                //Console.ReadKey();
            }
            //System.Console.ReadKey();
            return output;
        }
        static List<string> R2_A(string[] input)
        {
            List<string> output = new List<string>();
            int line = 0;
            int tc = Int32.Parse(input[line++]);
            int N, X, result;
            for (int i = 1; i <= tc; i++)
            {
                result = 0;
                String[] nx = input[line++].Split(new Char[] { ' ' });
                N = Int32.Parse(nx[0]);
                X = Int32.Parse(nx[1]);
                String[] Si = input[line++].Split(new Char[] { ' ' });
                List<int> S = new List<int>();
                foreach (String s in Si)
                {
                    S.Add(Int32.Parse(s));
                }
                S.Sort();
                while (S.Count > 0)
                {
                    int capaleft = X - S[S.Count - 1];
                    S.Remove(S[S.Count - 1]);
                    for (int f = S.Count - 1; f >= 0; f--)
                    {
                        if (S[f] <= capaleft)
                        {
                            S.Remove(S[f]);
                            break;
                        }
                    }
                    result++;
                }
                output.Add("Case #" + i + ": " + result);
                System.Console.WriteLine(i);
            }
            return output;
        }
        static List<string> Round1A_a_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                int N = Int32.Parse(input[line++]);
                int x = 0, y = 0;
                int maxdiff = 0;
                string[] mush = input[line++].Split(new Char[] { ' ' });
                List<int> mushroom = new List<int>(N);
                foreach (String m in mush)
                {
                    mushroom.Add(Int32.Parse(m));
                }
                for (int yo = 1; yo < N; yo++)
                {
                    if (mushroom[yo] < mushroom[yo - 1])
                    {
                        x += (mushroom[yo - 1] - mushroom[yo]);
                        if (maxdiff < mushroom[yo - 1] - mushroom[yo])
                        {
                            maxdiff = mushroom[yo - 1] - mushroom[yo];
                        }
                    }
                }
                System.Console.WriteLine("Case" + i + "maxdiff=" + maxdiff);
                for (int yo = 0; yo < N - 1; yo++)
                {
                    y += (maxdiff > mushroom[yo] ? mushroom[yo] : maxdiff);
                }
                output.Add("Case #" + i + ": " + x + " " + y);
                System.Console.WriteLine("Case #" + i + ": " + x + " " + y);
            }
            System.Console.ReadKey();
            return output;
        }
        static List<string> Round1A_b_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {

                output.Add("Case #" + i + ": ");
            }
            return output;
        }
        static List<string> Round1A_c_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                long N = Int64.Parse(input[line++]);
                List<Tuple<long, long>> xy = new List<Tuple<long, long>>();
                for (int yo = 0; yo < N; yo++)
                {
                    string[] xys = input[line++].Split(new Char[] { ' ' });
                    xy.Add(new Tuple<long, long>(Int64.Parse(xys[0]), Int64.Parse(xys[1])));
                }
                List<long> result = new List<long>();
                foreach (Tuple<long, long> t1 in xy)
                {
                    long min = 0;
                    int flag = 0;
                    foreach (Tuple<long, long> t2 in xy)
                    {
                        if (t1 != t2)
                        {
                            System.Windows.Vector v1 = new System.Windows.Vector(t2.Item1 - t1.Item1, t2.Item2 - t1.Item2);
                            long left = 0, right = 0;
                            foreach (Tuple<long, long> t3 in xy)
                            {
                                if (t3 != t1 && t3 != t2)
                                {
                                    System.Windows.Vector v2 = new System.Windows.Vector(t3.Item1 - t2.Item1, t3.Item2 - t2.Item2);
                                    if (System.Windows.Vector.CrossProduct(v1, v2) > 0)
                                    {
                                        left++;
                                    }
                                    else if (System.Windows.Vector.CrossProduct(v1, v2) < 0)
                                    {
                                        right++;
                                    }
                                }
                            }
                            long toberemoved = left < right ? left : right;
                            if (flag == 0)
                            {
                                min = toberemoved;
                                flag = 1;
                            }
                            else
                            {
                                if (toberemoved < min)
                                {
                                    min = toberemoved;
                                }
                            }
                        }
                    }
                    result.Add(min);
                }
                output.Add("Case #" + i + ":");
                foreach (long num in result)
                {
                    output.Add(num.ToString());
                }
            }
            return output;
        }
        static List<string> QualA_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                int res = 0;
                int standing = 0;
                string[] S_ss = input[line++].Split(new Char[] { ' ' });
                int S_max = Int32.Parse(S_ss[0]);
                String S = S_ss[1];
                for (int idx = 0; idx <= S_max; idx++)
                {
                    if (S[idx] != '0')
                    {
                        if (standing < idx)
                        {
                            int f = idx - standing;
                            res += f;
                            standing += f;
                        }
                        standing += S[idx] - '0';
                    }
                }
                output.Add("Case #" + i + ": " + res);
            }
            return output;
        }
        static List<string> QualB_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                int res = 0;
                int D = Int32.Parse(input[line++]);
                System.Console.Write(input[line]);
                string[] pancakes = input[line++].Split(new Char[] { ' ' });
                List<int> p = new List<int>();
                for (int x = 0; x < D; x++)
                {
                    p.Add(Int32.Parse(pancakes[x]));
                }
                int min = p.Max();
                while (p.Max() > 3)
                {
                    int m = p.Max();
                    
                        res++;
                        p.Remove(m);
                        if (m % 2 == 0)
                        {
                            p.Add(m / 2);
                            p.Add(m / 2);
                        }
                        else
                        {
                            p.Add(m / 2);
                            p.Add(m / 2 + 1);
                        }
                    
                    int time = res + p.Max();
                    if (min > time)
                        min = time;
                }
                output.Add("Case #" + i + ": " + min);
                System.Console.WriteLine(": " + min);
            }
            System.Console.ReadKey();
            return output;
        }
        static char getletter(string pat, int idx)
        {
            return pat[idx % pat.Length];
        }
        static string multiply(string x, string pat, long idx, bool lr)
        {
            int yo = (int)(idx % pat.Length);
            char y = pat[yo];
            bool neg = x.StartsWith("-");
            char x1 = x.Replace("-", "")[0];
            string[,] mat = new string[,]
	        {
                {"1", "i", "j", "k"},
	            {"i", "-1", "k", "-j"},
	            {"j", "-k", "-1", "i"},
	            {"k", "j", "-i", "-1"}
	        }; 
            int i = 0, j = 0;
            switch (x1)
            {
                case '1':
                    i = 0;
                    break;
                case 'i':
                    i = 1;
                    break;
                case 'j':
                    i = 2;
                    break;
                case 'k':
                    i = 3;
                    break;
            }
            switch (y)
            {
                case '1':
                    j = 0;
                    break;
                case 'i':
                    j = 1;
                    break;
                case 'j':
                    j = 2;
                    break;
                case 'k':
                    j = 3;
                    break;
            }
            string res = lr ? mat[i, j] : mat[j, i];
            if (neg)
            {
                if (res.StartsWith("-"))
                    res = res.Replace("-", "");
                else
                    res = res.PadLeft(2, '-');
            }
            return res;
        }
        static string calcmid(string pattern, long l, long r)
        {
            string mproduct = "1";
            for (long x = l; x <= r; x++)
            {
                mproduct = multiply(mproduct, pattern, x, true);
            }
            return mproduct;
        }
        static List<string> QualC_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                long L, X;
                bool res = false;
                string[] lx = input[line++].Split(new Char[] { ' ' });
                L = Int64.Parse(lx[0]);
                X = Int64.Parse(lx[1]);
                string pat = input[line++];
                long l = 0, r = 0;
                List<long> prevl = new List<long>();
                List<long> prevr = new List<long>();
                string valueL = calcmid(pat, 0, L - 1);
                string lproduct = "1", rproduct = "1";
                long lbound = X <= 1500 ? L * X : L * 1500;
                System.Console.WriteLine("begin");
                for (l = 0; l < lbound; l++)
                {
                    lproduct = multiply(lproduct, pat, l, true);
                    if (lproduct == "i")
                    {
                        prevl.Add(l);
                        break;
                    }
                }
                System.Console.WriteLine("left");
                long rbound = X <= 1500 ? 0 : L * (X - 1500);
                for (r = L * X - 1; r >= rbound; r--)
                {
                    rproduct = multiply(rproduct, pat, r, false);
                    if (rproduct == "k")
                    {
                        prevr.Add(r);
                        break;
                    }
                }
                System.Console.WriteLine("right");
                if (prevl.Count > 0 && prevr.Count > 0)
                {
                    if (prevl[0] < prevr[0] - 1)
                    {
                        if (X % 2 == 1)
                        {
                            if (valueL == "-1")
                                res = true;
                        }
                        else
                        {
                            if (valueL == "i" || valueL == "j" || valueL == "k" || valueL == "-i" || valueL == "-j" || valueL == "-k")
                            {
                                if (X % 4 != 0)
                                {
                                    res = true;
                                }
                            }
                        }
                    }
                }
                if (res)
                    output.Add("Case #" + i + ": YES");
                else
                    output.Add("Case #" + i + ": NO");
                System.Console.WriteLine("end");
            }
            return output;
        }
        static List<string> QualD_15(string[] input)
        {
            List<string> output = new List<string>();
            int tc = Int32.Parse(input[0]);
            int line = 1;
            for (int i = 1; i <= tc; i++)
            {
                bool win = false;
                string[] xrc = input[line++].Split(new Char[] { ' ' });
                int x = Int32.Parse(xrc[0]);
                int r = Int32.Parse(xrc[1]);
                int c = Int32.Parse(xrc[2]);
                if (x <= 4 && r <= 4 && c <= 4)
                {
                    if ((r * c) % x != 0)
                        win = true;
                    else
                    {
                        if (r * c == 8)
                        {
                            if (x == 4)
                                win = true;
                        }
                        else if (r * c == 3)
                        {
                            if (x == 3)
                                win = true;
                        }
                        else if (r == 1 && c == 4 || r == 4 && c == 1)
                        {
                            if (x == 4)
                                win = true;
                        }
                        else if (r == 2 && c == 2)
                        {
                            if (x == 4)
                                win = true;
                        }
                    }
                }
                else
                {
                    if ((r * c) % x != 0 || x >= 7)
                        win = true;
                    else //only multiples
                    {
                        if (x == 3)
                        {
                            if (r == 1 || c == 1)
                                win = true;
                        }
                        else if (x == 4)
                        {
                            if (r <= 2 || c <= 2)
                                win = true;
                        }
                        else if (x == 5)
                        {
                            if (r <= 2 || c <= 2)
                                win = true;
                        }
                        else if (x == 6)
                        {
                            if (r <= 3 || c <= 3)
                                win = true;
                        }
                    }
                }
                if(win)
                    output.Add("Case #" + i + ": RICHARD");
                else
                    output.Add("Case #" + i + ": GABRIEL");
            } 
            return output;
        }

        static void Main(string[] args)
        {
            //string[] input = File.ReadAllLines("B-small-attempt0.in");
            //List<string> output = R1C_B(input);
            //File.WriteAllLines("outputBs.out", output);
            //System.Console.WriteLine(multiply("k", 'j'));
            string[] input = File.ReadAllLines("C-small-attempt1.in");
            List<string> output = Round1A_c_15(input);
            File.WriteAllLines("outputCs1.out", output);

            //string[] input = File.ReadAllLines("sample.in");
            ////string[] input = File.ReadAllLines("sample2.in");
            //List<string> output = R1A_C(input);
            //File.WriteAllLines("outputCs.out", output);

            //string[] input = File.ReadAllLines("D-large.in");
            //List<string> output = QualD(input);
            //File.WriteAllLines("outputDl.out", output);
        }
    }
}
