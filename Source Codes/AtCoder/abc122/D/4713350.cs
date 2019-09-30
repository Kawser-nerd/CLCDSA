using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Linq;

namespace _20190324_04 {
    class Program {
        static void Main(string[] args) {
            var n = int.Parse(Console.ReadLine());
            var c = new Dictionary<int, char>() {
                [0] = 'A',
                [1] = 'C',
                [2] = 'G',
                [3] = 'T',
            };
            var memo = new List<Dictionary<string, int>>();
            for (int i = 0; i < n + 1; i++) {
                memo.Add(new Dictionary<string, int>());
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 4; k++) {
                        var s = c[i].ToString() + c[j] + c[k];
                        switch (s) {
                            case "AGC":
                            case "ACG":
                            case "GAC":
                                memo[3][s] = 0;
                                break;
                            default:
                                memo[3][s] = 1;
                                break;
                        }
                        for (int l = 4; l <= n; l++) {
                            memo[l][s] = 0;
                        }
                    }
                }
            }
            for (int i = 4; i <= n; i++) {
                for (int j = 0; j < 4; j++) {
                    foreach (var item in memo[i - 1]) {
                        var last4 = item.Key + c[j];
                        if (isOK(last4)) {
                            var key = new string(last4.Skip(1).ToArray());
                            memo[i][key] = (memo[i][key] + item.Value) % 1000000007;
                        }
                    }
                }
            }
            var sum = 0;
            foreach (var item in memo[n]) {
                sum = (sum + item.Value) % 1000000007;
            }

            Console.WriteLine(sum);
        }

        static bool isOK(string last4) {
            for (int i = 0; i < 4; i++) {
                var t = last4.ToCharArray();
                if (i >= 1) {
                    t[i - 1] = last4[i];
                    t[i] = last4[i - 1];
                }
                var s = new string(t);
                if (Regex.IsMatch(s, "AGC")) {
                    return false;
                }
            }
            return true;
        }
    }
}