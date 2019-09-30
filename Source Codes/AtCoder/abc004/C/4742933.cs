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
            int N = int.Parse(ReadLine()) % 60;
            int[] arr = { 1, 2, 3, 4, 5, 6 };
            int tmp = 0;

            for(int i = 0;i < N; i++) {
                tmp = arr[i % 5];
                arr[i % 5] = arr[i % 5 + 1];
                arr[i % 5 + 1] = tmp;
            }

            foreach (var e in arr)
                Write(e);
            WriteLine();


            ProgramEndPointLabel:;

            ReadLine();
        }
    }
}