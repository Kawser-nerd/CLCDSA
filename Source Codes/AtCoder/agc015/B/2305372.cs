using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC015B {
    class Program {
        static void Main(string[] args) {
            string S = Console.ReadLine();
            long ans = 0;
            int len = S.Length;
            for(int i = 0; i < len; i++) {
                string ud = S.Substring(i, 1);
                if(ud == "U") {
                    ans += (len - i - 1) + (i * 2);
                } else {
                    ans += (len - i - 1) * 2 + i;
                }
            }
            Console.WriteLine(ans);
        }
    }
}