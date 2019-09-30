using System;
using System.Collections.Generic;
using System.Linq;

namespace D {
    class Program {
        static void Main (string[] args) {
            var W = int.Parse (Console.ReadLine ());
            var NK = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
            var N = NK[0];
            var K = NK[1];
            var A = new List<int> ();
            var B = new List<int> ();
            foreach (var i in Enumerable.Range (0, N)) {
                var AB = Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
                A.Add (AB[0]);
                B.Add (AB[1]);
            }

            /*
            ?????dp[i][j][k]?k?????????????i?????j?????
            dp[i][j][k + 1]??
            dp[i][j][k]?dp[i-A[k]][j-1][k] + B[k]?????
            */

            var dp = new int[W + 1, K + 1, N + 1];
            foreach (var i in Enumerable.Range (0, W + 1)) {
                foreach (var j in Enumerable.Range (0, K + 1)) {
                    foreach (var k in Enumerable.Range (0, N)) {
                        if (i - A[k] < 0 || j - 1 < 0) {
                            // ????????
                            dp[i, j, k + 1] = dp[i, j, k];
                        } else {
                            dp[i, j, k + 1] = Math.Max (dp[i, j, k], dp[i - A[k], j - 1, k] + B[k]);
                        }
                    }
                }
            }

            var max = 0;
            foreach (var i in Enumerable.Range (0, W + 1)) {
                foreach (var j in Enumerable.Range (0, K + 1)) {
                    max = Math.Max (max, dp[i, j, N]);
                }
            }
            Console.WriteLine (max);
        }
    }
}