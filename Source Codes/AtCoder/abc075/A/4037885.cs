using System;
using System.Reflection;
using System.Linq.Expressions;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder {
    public class Program {
        static int[] getKeys(char delimiter) {
            var Keys = Console.ReadLine().Split(' ');
            int[] Ns = new int[Keys.Length];
            for (int i = 0; i < Keys.Length; i++) {
                Ns[i] = int.Parse(Keys[i]);
            }
            return Ns;
        }

        static void Main() {
            var Keys = getKeys(' ');
            if (Keys[0] == Keys[1]) {
                Console.WriteLine(Keys[2]);
            } else if (Keys[1] == Keys[2]) {
                Console.WriteLine(Keys[0]);
            } else {
                Console.WriteLine(Keys[1]);
            }
        }
    }
}