using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Number_Sets
{
    class Program
    {
        static long[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                                73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 
                                157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
                                239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 
                                331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 
                                421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503,
                                509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 
                                613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
                                709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
                                821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
                                919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019,
                                1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097,
                                1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201,
                                1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289 };

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");
            int C = int.Parse(sr.ReadLine()); // number of cases
            long A, B, P;
            long[] sets;
            string[] ABP;
            long v;
            long result;



            for (int i = 1; i <= C; i++)
            {
                ABP = sr.ReadLine().Split(" ".ToCharArray());
                A = long.Parse(ABP[0]);
                B = long.Parse(ABP[1]);
                P = long.Parse(ABP[2]);
                sets = new long[B-A+1];
                sets[0] = A;

                for (long x = A; x <= B; x++)
                {
                    for (long y = x + 1; y <= B; y++)
                    {
                        if (x == A) sets[y-A] = y;
                        if (SharePrime(x, y, P))
                        {
                            v = sets[y-A];
                            for(long xx = A; xx<=B; xx++) 
                                if (sets[xx - A] == v) sets[xx - A] = sets[x - A];
                        }

                    }
                }

                result = (from aaa in sets select aaa).Distinct().Count();


                Console.WriteLine("Case #{0}: {1}", i, result);
                sw.WriteLine("Case #{0}: {1}", i, result);

            }

            sr.Close();
            sw.Flush();
            sw.Close();

        }

        static bool SharePrime(long x, long y, long P)
        {
            foreach(long i in primes) {
                if (i > y) break;
                if (i >= P)
                    if ((x % i == 0) && (y % i == 0)) return true;

            } 
            return false;
        }

    }
}
