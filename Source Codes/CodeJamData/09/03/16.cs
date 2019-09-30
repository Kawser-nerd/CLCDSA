using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam {
    class c {
        static void Main() {
            StreamReader cin = new StreamReader("c.in");
            StreamWriter cout = new StreamWriter("c.out");
            string init = "welcome to code jam";
            int ca = int.Parse(cin.ReadLine());
            for (int cc = 0; cc < ca; ++cc) {
                int ans = 0;
                cout.Write(string.Format("Case #{0}: ", cc + 1));
                string s = cin.ReadLine();
                int[,] dp = new int[s.Length + 1, init.Length + 1];
                for (int i = 1; i <= s.Length; ++i) {
                    for (int j = 1; j <= init.Length; ++j) {
                        if (s[i - 1] == init[j - 1]) {
                            if (j == 1) {
                                dp[i, j] = 1;
                                continue;
                            }
                            for (int k = 1; k < i; ++k) {
                                dp[i, j] = (dp[i, j] + dp[k, j - 1]) % 10000;
                            }
                        }
                    }
                    ans = (ans + dp[i, init.Length]) % 10000;
                }
                StringBuilder tmp = new StringBuilder();
                while (ans > 0) {
                    tmp.Append(ans % 10);
                    ans /= 10;
                }
                while (tmp.Length < 4) {
                    tmp.Append('0');
                }
                for (int i = tmp.Length - 1; i >= 0; --i) {
                    cout.Write(tmp[i]);
                }
                cout.WriteLine();
            }
            cin.Close();
            cout.Close();
        }
    }
}
