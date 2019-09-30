using System;
using System.Collections.Generic;
using System.Text;

namespace Google {
    class Speed {

        static void Main(string[] args) {
            long NN = Int64.Parse(Console.ReadLine());
            for (long cs = 1; cs <= NN; cs++) {
                string line = Console.ReadLine();
                string[] data = line.Split(' ');

                long n = Int64.Parse(data[0]);
                long m = Int64.Parse(data[1]);
                long X = Int64.Parse(data[2]);
                long Y = Int64.Parse(data[3]);
                long Z = Int64.Parse(data[4]);

                long[] A = new long[m];
                for (int i = 0; i < m; i++) {
                    A[i] = Int64.Parse(Console.ReadLine());
                }

                long[] limits = new long[n];
                long[] results = new long[n];

                for (int i = 0; i <= n - 1; i++) {
                    limits[i] = A[i % m];
                    A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
                }

                //for (int i = 0; i < n; i++) Console.Write(limits[i].ToString());
                results[0] = 1;
                for (int i = 1; i < n; i++) {                   
                    results[i] = 1;
                    for (int j = i - 1; j >= 0; j--) if (limits[j] < limits[i]) {
                            results[i] += results[j];
                            results[i] = results[i] % 1000000007;
                        }
                 }

                long result = 0;
                for (int i = 0; i < n; i++) result += results[i];
                result = result % 1000000007;
                Console.WriteLine("Case #" + cs.ToString() +": " + result.ToString());

            }
        }

    }
}