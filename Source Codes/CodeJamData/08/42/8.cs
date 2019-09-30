using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static int[] extended_gcd(int a, int b)
        {
            int x = 0, lastx = 1;
            int y = 1, lasty = 0;
            while (b != 0)
            {
                int t = b;
                int q = a / b;
                b = a % b;
                a = t;

                t = x;
                x = lastx - q * x;
                lastx = t;

                t = y;
                y = lasty - q * y;
                lasty = t;
            }
            return new int[] { a, lastx, lasty };
        }
        static int[] findsolns(int a, int b, int N, int max)
        {
            if (a == 0)
            {
                if (N % b != 0)
                    return null;
                if (N / b > max)
                    return null;
                return new int[] { 0, N / b };
            }
            if (b == 0)
            {
                if (N % a != 0)
                    return null;
                if (N / a > max)
                    return null;
                return new int[] { N / a, 0 };
            }
            int[] gcd = extended_gcd(a, b);
            //Console.WriteLine(a+" " +b);
            int g = gcd[0];
            //Console.WriteLine(g);
            if (N % g != 0)
                return null;
            int X = gcd[1] * N;
            int Y = -gcd[2] * N;
            //N /= g;
            a /= g;
            b /= g;
            /*if (X*a-Y*b < 0)
            {
                X *= -1;
                Y *= -1;
            }*/
            System.Diagnostics.Debug.Assert(X * a - Y * b == N);
            //Console.WriteLine(X*a - Y*b-N);
            //Console.WriteLine(g + " " + a + " " + b + " " + X + " " + Y+ " " + N);
            //System.Diagnostics.Debug.Assert(X >= 0);
            //System.Diagnostics.Debug.Assert(Y >= 0);
            if (X > max)
            {
                int mul = (X - max + b - 1) / b;
                X -= mul * b;
                Y -= mul * a;
            }
            else if (X < 0)
            {
                int mul = (-X + b - 1) / b;
                X += mul * b;
                Y += mul * a;
            }
            if (Y > max)
            {
                int mul = (Y - max + a - 1) / a;
                X -= mul * b;
                Y -= mul * a;
            }
            else if (Y < 0)
            {
                int mul = (-Y + a - 1) / a;
                X += mul * b;
                Y += mul * a;
            }
            //Console.WriteLine(X * a - Y * b - N);
            //Console.WriteLine(g + " " + a + " " + b + " " + X + " " + Y);
            if (X < 0 || Y < 0 || X > max || Y > max)
                return null;

            System.Diagnostics.Debug.Assert(X * a - Y * b == N);
            return new[] { X, Y };
        }
        static void Main(string[] args)
        {
            
            {
                StreamReader sr = new StreamReader(args[0]);
                int C = int.Parse(sr.ReadLine());
                for (int t = 1; t <= C; t++)
                {
                    string[] split = sr.ReadLine().Split();
                    int N = int.Parse(split[0]);
                    int M = int.Parse(split[1]);
                    int A = int.Parse(split[2]);
                    //case1
                    bool done = false;
                    for (int x2 = 1; x2 <= N; x2++)
                    {
                        //if (x2%1000==0)
                        //    Console.WriteLine(x2);
                        for (int x3 = 1; x3 <= x2; x3++)
                        {
                            if (Math.Max(x3, x2) * M < A)
                                continue;
                            int[] solns = findsolns(x2, x3, A, M);
                            if (solns != null)
                            {
                                Console.WriteLine("Case #{0}: 0 0 {1} {2} {3} {4}", t, x2, solns[1], x3, solns[0]);
                                done = true;
                                break;
                            }
                            solns = findsolns(x2,x2-x3, A, M);
                            if (solns != null)
                            {
                                Console.WriteLine("Case #{0}: 0 {1} {2} 0 {3} {4}", t, solns[1], x2, x3, solns[0]);
                                done = true;
                                break;
                            }
                        }
                        if (done)
                            break;
                    }
                    if (done)
                        continue;
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", t);

                }
            }
        }
    }
}
