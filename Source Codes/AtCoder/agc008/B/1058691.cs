using System;
using System.IO;
using System.Linq;

namespace At{
    class agc008 {
        static string[] splits;
        static int current = 0;

        static int nextint(){
            if(splits == null || splits.Length == current){
                splits = Console.ReadLine().Split(' ').ToArray();
            }
            
            int n = int.Parse(splits[current]);
            current++;
            return n;
        }

        static long[] ints(){
            return Console.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();
        }

        static void Main(){
            int n = nextint();
            int k = nextint();

            long[] arr = ints();
            long total_plus = 0;
            long total_minus = 0;

            long[] plusto = new long[n];
            long[] minusto = new long[n];

            for(int i = 0; i <n ; i++){
                if(arr[i] > 0){
                    total_plus += arr[i];
                }
                else {
                    total_minus += arr[i];
                }
                plusto[i] = total_plus;
                minusto[i] = total_minus;
            }

            long blackout;
            long whiteout;
            
            long tmpmax = total_plus + minusto[k-1];

            // Console.WriteLine("Black");
            for(int i = 1; i < n - k + 1; i++){
                blackout = total_plus + minusto[i+k-1] - minusto[i-1];
                tmpmax = Math.Max(tmpmax,blackout);
                // Console.WriteLine(i + " ~ " + (i+k-1) +" " + blackout);
            }

            // Console.WriteLine("White");
            tmpmax = Math.Max(tmpmax, total_plus - plusto[k-1]);
            for(int i = 1; i < n - k + 1; i++){
                whiteout = total_plus - plusto[i+k-1] + plusto[i-1];
                tmpmax = Math.Max(tmpmax,whiteout);
                // Console.WriteLine(i + " ~ " + (i+k-1) +" " + whiteout);
            }

            Console.WriteLine(tmpmax);
        }
    }
}