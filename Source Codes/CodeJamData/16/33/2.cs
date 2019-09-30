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
                int j = int.Parse(aux[0]), p = int.Parse(aux[1]), s = int.Parse(aux[2]), k = int.Parse(aux[3]);

                Console.WriteLine("Case #{0}: {1}", test, j * p * Math.Min(s, k));
                if (k >= s) {
                    for (int a = 1; a <= j; a++) {
                        for (int b = 1; b <= p; b++) {
                            for (int c = 1; c <= s; c++) {
                                Console.WriteLine("{0} {1} {2}", a, b, c);
                            }
                        }
                    }
                } else {
                    for (int a = 1; a <= j; a++) {
                        for (int b = 1; b <= p; b++) {
                            int start = a + b - 1;
                            while (start > s) {
                                start -= s;
                            }
                            for (int cnt = 1; cnt <= k; cnt++) {
                                Console.WriteLine("{0} {1} {2}", a, b, start);
                                start++;
                                while (start > s) {
                                    start -= s;
                                }
                            }
                        }
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