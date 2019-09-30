using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;
using System.IO;

namespace ConsoleApp2
{
    class Program {
        static decimal C(int a,int b) {
            decimal res = 1;
            for (int i = 0; i < b; i++) {
                res *= (a - i);
                res /= (i + 1);
            }
            return res;
        }


        static void Main(string[] Args) {
            string[] str = new string[4];
            for (int i = 0; i < 4; i++)
                str[i] = ReadLine().Replace(" ","");

            for (int i = 3; i >= 0; i--) {
                for (int j = 3; j >= 0; j--)
                    Write(str[i][j] + " ");
                WriteLine();
            }

            ProgramEndPointLabel:;

            ReadLine();
        }
    }
}