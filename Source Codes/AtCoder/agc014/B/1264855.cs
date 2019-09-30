using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC14 {
    class Program {
        static int[] inp,a,b,e;
        static int n, m;
        static void Main(string[] args) {
            inp = Scan;
            n = inp[0];
            m = inp[1];
            e = new int[n+1];
            a = new int[m];
            b = new int[m];
            for (int i = 0; i <= n; i++)
                e[i] = 0;
            for(int i = 0; i < m; i++) {
                inp = Scan;
                a[i] = inp[0];
                b[i] = inp[1];
            }
            if (Solve())
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }
        static bool Solve() {
            for(int i = 0; i < m; i++) {
                e[a[i]]++;
                e[b[i]]++;
            }
            for(int i = 1; i <= n; i++) {
                if (e[i] % 2 == 1)
                    return false;
            }
            return true;
        }
       static int[] Scan {
            get {
                return Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            }
        }
    }
}