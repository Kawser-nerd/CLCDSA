using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC059D {
    class Program {
        static void Main(string[] args) {
            string s = Console.ReadLine();
            int ansa = -1;
            int ansb = -1;
            for (int i = 0; i < s.Length; i++) {
                string x = s.Substring(i, 1);
                if (i < s.Length - 1) {
                    if (x == s.Substring(i + 1, 1)) {
                        ansa = i + 1;
                        ansb = i + 2;
                        break;
                    }
                }
                if (i < s.Length - 2) {
                    if (x == s.Substring(i + 2, 1)) {
                        ansa = i + 1;
                        ansb = i + 3;
                        break;
                    }
                }
            }
            Console.WriteLine(ansa.ToString() + " " + ansb.ToString());
        }
    }
}