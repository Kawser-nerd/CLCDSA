﻿using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.Linq;

namespace CodeJam2012R2
{
    using System.Numerics;

    public class SolverBase
    {
        #region Helper
        public static int[ ] SAToIA( string[ ] strSplit )
        {
            int[ ] nums = new int[ strSplit.Length ];
            for ( int iTemp = 0; iTemp < strSplit.Length; ++iTemp )
            {
                nums[ iTemp ] = int.Parse( strSplit[ iTemp ] );
            }

            return nums;
        }

        public static long[ ] SAToLongA( string[ ] strSplit )
        {
            long[ ] nums = new long[ strSplit.Length ];
            for ( int iTemp = 0; iTemp < strSplit.Length; ++iTemp )
            {
                nums[ iTemp ] = long.Parse( strSplit[ iTemp ] );
            }

            return nums;
        }

        public static int[ ] StringToIA( string s, char[ ] delim )
        {
            string[ ] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries );
            return SAToIA( strSplit );
        }

        public static int[ ] StringToIA( string s, char c )
        {
            return StringToIA( s, new char[ ] { c } );
        }

        public static int[ ] StringToIA( string s )
        {
            return StringToIA( s, new char[ ] { ' ' } );
        }

        public static long[ ] StringToLongA( string s, char[ ] delim )
        {
            string[ ] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries );
            return SAToLongA( strSplit );
        }

        public static long[ ] StringToLongA( string s, char c )
        {
            return StringToLongA( s, new char[ ] { c } );
        }

        public static long[ ] StringToLongA( string s )
        {
            return StringToLongA( s, new char[ ] { ' ' } );
        }

        public static string[ ] StringToSA( string s, char[ ] delim )
        {
            string[ ] strSplit = s.Split(
                delim,
                StringSplitOptions.RemoveEmptyEntries );
            return strSplit;
        }

        public static string[ ] StringToSA( string s, char c )
        {
            return StringToSA( s, new char[ ] { c } );
        }

        public static string[ ] StringToSA( string s )
        {
            return StringToSA( s, new char[ ] { ' ' } );
        }
        #endregion Helper

        public const int INF = 1000 * 1000 * 1000;
        public const int OFFSET = 1000;

        protected System.IO.StreamWriter writer;

        public void Solve( string input, string output )
        {
            string filename = input;
            writer = new System.IO.StreamWriter( output );
            string[ ] strAll = System.IO.File.ReadAllText( filename ).Split(
                new char[ ] { '\r', '\n' },
                StringSplitOptions.RemoveEmptyEntries );

            ParseAndSolve( strAll );
            writer.Flush( );
        }

        virtual public void ParseAndSolve( string[ ] strAll )
        {
            throw new NotImplementedException( );
        }
    }

    public class A : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                string sres = "Case #" + i + ": ";
                string [] board = new string[4];
                Array.Copy(strAll, idx, board, 0, 4);
                idx += 4;
                sres += Solve(board);
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve(string[] board)
        {
            char[,] bd = new char[4,4];
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    bd[i, j] = board[i][j];
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                string s = string.Empty;
                for (int j = 0; j < 4; ++j)
                {
                    s += bd[i, j];
                }

                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                string s = string.Empty;
                for (int j = 0; j < 4; ++j)
                {
                    s += bd[j, i];
                }

                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            {
                string s = bd[0, 0] + "";
                s += bd[1, 1];
                s += bd[2, 2];
                s += bd[3, 3];
                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            {
                string s = bd[0, 3] + "";
                s += bd[1, 2];
                s += bd[2, 1];
                s += bd[3, 0];
                char check = GetOne(s);
                if (check == 'X')
                {
                    return "X won";
                }
                else if (check == 'O')
                {
                    return "O won";
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    if (bd[i, j] == '.')
                    {
                        return "Game has not completed";
                    }
                }
            }

            return "Draw";
        }

        private char GetOne(string s)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (s[i] == '.')
                {
                    return 'U';
                }
            }

            int xcount = 0;
            int ocount = 0;
            int tcount = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (s[i] == 'X')
                {
                    ++xcount;
                }
                else if (s[i] == 'O')
                {
                    ++ocount;
                }
                else
                {
                    ++tcount;
                }
            }

            if (xcount + tcount == 4)
            {
                return 'X';
            }

            if (ocount + tcount == 4)
            {
                return 'O';
            }

            return 'U';
        }
    }

    public class B : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                int[ ] nm = StringToIA( strAll[ idx++ ] );
                int n = nm[0];
                int m = nm[1];
                int[,] board = new int[n,m];
                for (int j = 0; j < n; ++j)
                {
                    int[] row = StringToIA(strAll[idx++]);
                    for (int k = 0; k < m; ++k)
                    {
                        board[j, k] = row[k];
                    }
                }

                string sres = "Case #" + i + ": ";
                sres += Solve(board);
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve(int[,] board)
        {
            long n = board.GetLongLength(0);
            long m = board.GetLongLength(1);

            if (n == 1 || m == 1)
            {
                return "YES";
            }

            int min = int.MaxValue;
            int mx = -1;
            int my = -1;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (board[i, j] < min)
                    {
                        min = board[i, j];
                        mx = i;
                        my = j;
                    }
                }
            }

            bool good = true;
            for (int i = 0; i < n; ++i)
            {
                if (board[i, my] != min)
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                int[,] next = new int[n,m - 1];
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (j == my)
                        {
                            continue;
                        }

                        next[i, j > my ? j - 1 : j] = board[i, j];
                    }
                }

                return Solve(next);
            }

            good = true;
            for (int i = 0; i < m; ++i)
            {
                if (board[mx, i] != min)
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                int[,] next = new int[n - 1, m];
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (i == mx)
                        {
                            continue;
                        }

                        next[i > mx ? i - 1 : i, j] = board[i, j];
                    }
                }

                return Solve(next);
            }

            return "NO";
        }
    }

    public class C : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            PreCalc();
            PreCalcBig();
            for ( int i = 1; i <= T; ++i )
            {
                var ab = strAll[idx++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                //long a = long.Parse(ab[0]);
                //long b = long.Parse(ab[1]);
                string sres = "Case #" + i + ": ";
                sres += SolveBig(ab[0], ab[1]);
                writer.WriteLine( sres );
                Console.WriteLine( sres );

                ////var solvesmall = Solve(a, b);
                ////var solvebig = SolveBig(ab[0], ab[1]);
                ////if (solvesmall != solvebig)
                ////{
                ////    throw new Exception(a + " " + b + ", " + solvesmall + ", " + solvebig);
                ////}
            }
        }

        private long[] cache = new long[10000];
        bool IsPal(string s)
        {
            int len = s.Length;
            for (int i = 0; i <= len / 2; ++i)
            {
                if (s[i] != s[len - 1 - i])
                {
                    return false;
                }
            }

            return true;
        }

        public void PreCalc()
        {
            int idx = 0;
            for (long i = 0; i < 1000 * 1000 * 100L; ++i)
            {
                if (!IsPal(i + ""))
                {
                    continue;
                }

                var square = i * i;
                if (IsPal(square + ""))
                {
                    Console.WriteLine(i + ", " + square);
                    cache[idx++] = square;
                }
            }

            Console.WriteLine("Done!");
        }

        private string Solve(long a, long b)
        {
            int count = 0;
            for (int i = 0; i < cache.Length; ++i)
            {
                if (cache[i] >= a && cache[i] <= b)
                {
                    ++count;
                }

                if (cache[i] > b)
                {
                    return count + string.Empty;
                }
            }

            return count + string.Empty;
        }

        private List<BigInteger> bigCache = new List<BigInteger>();
        private List<string> rootCache = new List<string>();
        public void PreCalcBig()
        {
            rootCache.Add(string.Empty);
            for (int i = 0; i < 4; ++i)
            {
                rootCache.Add(i + string.Empty);
                bigCache.Add(new BigInteger(i * i));
            }

            int countAtLastLen = rootCache.Count;
            for (int len = 2; len <= 55; ++len)
            {
                for (int i = 0; i < countAtLastLen; ++ i)
                {
                    string curr = rootCache[i];
                    if (curr.Length % 2 != len % 2)
                    {
                        continue;
                    }

                    while (curr.Length < len - 2)
                    {
                        curr = "0" + curr + "0";
                    }

                    Check("1" + curr + "1");
                    Check("2" + curr + "2");
                }

                countAtLastLen = rootCache.Count;
            }

            bigCache.Sort();
            foreach (var a in bigCache)
            {
                Console.WriteLine(a);
            }
            
            Console.WriteLine(bigCache.Count);
            Console.WriteLine("Done!");
        }

        private void Check(string curr)
        {
            var bi = BigInteger.Parse(curr);
            var square = bi * bi;
            if (IsPal(square.ToString()))
            {
                rootCache.Add(curr);
                bigCache.Add(square);
                Console.WriteLine(curr + "," + square);
            }
        }

        private string SolveBig(string a, string b)
        {
            int count = 0;
            var biA = BigInteger.Parse(a);
            var biB = BigInteger.Parse(b);
            for (int i = 0; i < bigCache.Count; ++i)
            {
                if (bigCache[i] >= biA && bigCache[i] <= biB)
                {
                    ++count;
                }

                if (bigCache[i] > biB)
                {
                    return count + string.Empty;
                }
            }

            return count + string.Empty;
        }
    }

    public class D : SolverBase
    {
        override public void ParseAndSolve( string[ ] strAll )
        {
            int idx = 0;
            int T = int.Parse( strAll[ idx++ ] );

            for ( int i = 1; i <= T; ++i )
            {
                string sres = "Case #" + i + ": ";
                sres += Solve( strAll[ idx++ ] );
                writer.WriteLine( sres );
                Console.WriteLine( sres );
            }
        }

        private string Solve( string p )
        {
            throw new NotImplementedException( );
        }
    }

    public class RunMain
    {
        static void Main(string[] args)
        {
            string dir = "D:\\MyProj\\CodeJam\\";

            //new A( ).Solve( dir + "ASample.txt", dir + "out.txt" );
            //new A( ).Solve( dir + "A-small-attempt0.in", dir + "out.txt" );
            //new A( ).Solve( dir + "A-large.in", dir + "out.txt" );

            //new B( ).Solve( dir + "BSample.txt", dir + "out.txt" );
            //new B( ).Solve( dir + "B-small-attempt0.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large.in", dir + "out.txt" );
            //new B( ).Solve( dir + "B-large-practice.in", dir + "out.txt" );

            //new C( ).Solve( dir + "CSample.txt", dir + "out.txt" );
            //new C().Solve(dir + "C-small-attempt0.in", dir + "out.txt");
            //new C().Solve(dir + "C-large-1.in", dir + "out.txt");
            new C().Solve(dir + "C-large-2.in", dir + "out.txt");

            //new D( ).Solve( dir + "DSample.txt", dir + "out.txt" );
            //new D( ).Solve( dir + "D-small-attempt0.in", dir + "out.txt" );
            //new D( ).Solve( dir + "D-large.in", dir + "out.txt" );
        }
    }
}
