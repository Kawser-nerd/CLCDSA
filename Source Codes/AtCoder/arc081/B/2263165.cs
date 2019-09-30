using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC081D {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            string S1 = Console.ReadLine();
            string S2 = Console.ReadLine();
            long ans = 1;
            int updowndiff = -1;
            for (int i = 0; i < N; i++) {
                if (i != N - 1 && S1.Substring(i, 1) == S1.Substring(i + 1, 1)) {
                    if(updowndiff == -1) {
                        ans = (ans * 6) % mod;
                    }else if(updowndiff == 0) {
                        ans = (ans * 2) % mod;
                    } else {
                        ans = (ans * 3) % mod;
                    }
                    updowndiff = 1;
                    i++;
                } else {
                    if(updowndiff == -1) {
                        ans = (ans * 3) % mod;
                    }else if(updowndiff == 0) {
                        ans = (ans * 2) % mod;
                    } else {
                    }
                    updowndiff = 0;
                }
            }
            Console.WriteLine(ans);
        }

        //????
        const long mod = 1000000007;
    }
}