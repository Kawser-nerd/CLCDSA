using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _011
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            string[] strs = Read().Split(' ');
            string res = "";
            for(int i = 0; i < n; i++)
            {
                string tmp = "";
                for(int j = 0; j < strs[i].Length; j++)
                {
                    switch (strs[i][j])
                    {
                        case 'b':
                        case 'c':
                        case 'B':
                        case 'C':
                            tmp += '1';
                            break;
                        case 'd':
                        case 'w':
                        case 'D':
                        case 'W':
                            tmp += '2';
                            break;
                        case 't':
                        case 'j':
                        case 'T':
                        case 'J':
                            tmp += '3';
                            break;
                        case 'f':
                        case 'q':
                        case 'F':
                        case 'Q':
                            tmp += '4';
                            break;
                        case 'l':
                        case 'v':
                        case 'L':
                        case 'V':
                            tmp += '5';
                            break;
                        case 's':
                        case 'x':
                        case 'S':
                        case 'X':
                            tmp += '6';
                            break;
                        case 'p':
                        case 'm':
                        case 'P':
                        case 'M':
                            tmp += '7';
                            break;
                        case 'h':
                        case 'k':
                        case 'H':
                        case 'K':
                            tmp += '8';
                            break;
                        case 'n':
                        case 'g':
                        case 'N':
                        case 'G':
                            tmp += '9';
                            break;
                        case 'z':
                        case 'r':
                        case 'Z':
                        case 'R':
                            tmp += '0';
                            break;
                    }
                }
                if (res.Length>0&&tmp.Length>0) res += ' ';
                res += tmp;
            }
            WriteLine(res);
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}