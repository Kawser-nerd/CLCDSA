﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.IO;
using System.Numerics;
using System.Globalization;
using System.Threading;


namespace probleme {
    class Program {
        static void read() {
        }

        static void solve() {
            int totalTest = int.Parse(Console.ReadLine());

            for (int test = 1; test <= totalTest; test++) {
                string[] aux = Console.ReadLine().Split(' ');
                Console.Write("Case #{0}: ", test);
                int b = int.Parse(aux[0]);
                long m = long.Parse(aux[1]);
                if (m > (1L << (b - 2))) {
                    Console.WriteLine("IMPOSSIBLE");
                } else {
                    Console.WriteLine("POSSIBLE");
                    int[,] ans = new int[b, b];
                    for (int i = 0; i < b; i++) {
                        for (int j = i + 1; j < b; j++) {
                            ans[i, j] = 1;
                        }
                    }
                    m--;
                    for (int i = 2; i < b; i++) {
                        if ((m & (1L << (i - 2))) == 0) {
                            ans[i - 1, b - 1] = 0;
                        }
                    }
                    for (int i = 0; i < b; i++) {
                        for (int j = 0; j < b; j++) {
                            Console.Write(ans[i, j]);
                        }
                        Console.WriteLine();
                    }
                }
            }
           
        }

        static void Main(string[] args) {

            Console.SetIn(new StreamReader("file.in"));
            
            FileStream filestream = new FileStream("out.txt", FileMode.Create);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);
            

            solve();


            //Console.ReadKey();
        }
    }
}