using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Math;


namespace AtCodeeeer
{
    class AtCOOOOOOOOOOOder
    {
        static void Main(string[] args)
        {
            int[] s = ReadLine().Split(' ').Select(int.Parse).ToArray();
            int N = s[0];
            int Y = s[1];
            //?????????
            int yukiti = 0;
            int higuti = 0;
            int noguti = 0;
            int y = Y;
            while (y > 0)
            {
                if (y >= 10000)
                {
                    y -= 10000;
                    yukiti++;
                }
                else if (y >= 5000)
                {
                    y -= 5000;
                    higuti++;
                }
                else
                {
                    y -= 1000;
                    noguti++;
                }
            }
            //??phase
            bool find = false;
            while (yukiti + higuti + noguti <= N)
            {
                int n = yukiti + higuti + noguti;

                if (n == N)
                {
                    find = true;
                    break;
                }

                if (N - n >= 4 && higuti > 0)
                {
                    higuti--;
                    noguti += 5;
                }
                else if (N - n >= 1 && yukiti > 0)
                {
                    yukiti--;
                    higuti += 2;
                }
                else
                {
                    break;
                }
            }

            if (find)
            {
                WriteLine(yukiti + " " + higuti + " " + noguti);
            }
            else
            {
                WriteLine("-1 -1 -1");
            }
        }
    }
}