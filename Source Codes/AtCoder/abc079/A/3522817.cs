using System;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder {
    public class Program {
        public static void Main() {
            string s = Console.ReadLine();
            if ((s[0] == s[1] && s[1] == s[2])|| (s[1] == s[2] && s[2] == s[3])) {
                Console.WriteLine("Yes");
            }            else{
                Console.WriteLine("No");
            }
        }
    }
}