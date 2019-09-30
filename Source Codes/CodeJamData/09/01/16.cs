using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam {
    class a {
        static void Main() {
            StreamReader cin = new StreamReader(@"a.in");
            StreamWriter cout = new StreamWriter("a.out");
            string s = cin.ReadLine();
            string[] tr = s.Split(' ');
            int l = int.Parse(tr[0]);
            int d = int.Parse(tr[1]);
            int n = int.Parse(tr[2]);
            string[] dt = new string[d];
            for (int i = 0; i < d; ++i) {
                dt[i] = cin.ReadLine();
            }
            for (int i = 0; i < n; ++i) {
                string tmp = cin.ReadLine();
                HashSet<char>[] st = new HashSet<char>[l];
                for (int j = 0; j < l; ++j) {
                    st[j] = new HashSet<char>();
                }
                int now = 0, deep = 0;
                foreach (char c in tmp) {
                    if (c == '(') {
                        ++deep;
                    } else if (c == ')') {
                        --deep;
                        ++now;
                    } else {
                        st[now].Add(c);
                        if (deep == 0) {
                            ++now;
                        }
                    }
                }
                int ans = 0;
                for (int j = 0; j < d; ++j) {
                    bool tf = true;
                    for (int k = 0; k < l; ++k) {
                        if (st[k].Contains(dt[j][k]) == false) {
                            tf = false;
                            break;
                        }
                    }
                    if (tf) {
                        ++ans;
                    }
                }
                cout.WriteLine(string.Format("Case #{0}: {1}", i + 1, ans));
                Console.WriteLine(ans);
            }
            cin.Close();
            cout.Close();
            //Console.WriteLine(s);
        }
    }
}
