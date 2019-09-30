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
        static int totalTest = 0;
        static void read() {
            totalTest = int.Parse(Console.ReadLine());
        }

        static void solve() {
            totalTest = int.Parse(Console.ReadLine());

            for (int test = 1; test <= totalTest; test++) {
                int n = int.Parse(Console.ReadLine());
                int[] v = Array.ConvertAll(Console.ReadLine().Split(' '), ts => int.Parse(ts));

                int v1 = 0, v2 = 0, p1 = -1, p2 = -1;
                for (int i = 0; i < n; i++) {
                    if (v[i] > v1) {
                        p2 = p1;
                        v2 = v1;

                        p1 = i;
                        v1 = v[i];
                    } else if (v[i] > v2) {
                        v2 = v[i];
                        p2 = i;
                    }
                }

                Console.Write("Case #{0}: ", test);

                while (v1 > v2) {
                    Console.Write("{0} ", (char)('A' + p1));
                    v1--;
                }

                for (int i = 0; i < n; i++) {
                    if (i != p1 && i != p2) {
                        for (int j = 0; j < v[i]; j++) {
                            Console.Write("{0} ", (char)('A' + i));
                        }
                    }
                }
                for (int i = 0; i < v1; i++) {
                    Console.Write("{0}{1} ", (char)('A' + p1), (char)('A' + p2));
                }

                Console.WriteLine();
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