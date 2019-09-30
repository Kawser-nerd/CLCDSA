using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;

namespace ConsoleApp {

    class Program {
        static void Main(string[] args) {
            var num = int.Parse(Console.ReadLine());
            var gcf = GetGCF(num, 2);

            Console.WriteLine(num * 2 / gcf);
        }

        private static int GetGCF(int x, int y) {
            //x>=y???
            if (y > x) {
                var temp = y;
                y = x;
                x = temp;
            }

            int r;

            while ((r = x % y) != 0) {
                x = y;
                y = r;
            }
            return y;
        }
    }
    
}