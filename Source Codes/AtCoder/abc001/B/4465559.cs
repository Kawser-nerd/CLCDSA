using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190304_02 {
    class Program {
        static void Main(string[] args) {
            var range = int.Parse(Console.ReadLine()) / 1000.0;
            if (range < 0.1) {
                Console.WriteLine("00");
                return;
            }
            if (range <= 5) {
                Console.WriteLine((range * 10).ToString("00"));
                return;
            }
            if (range <= 30) {
                Console.WriteLine((range + 50).ToString("00"));
                return;
            }
            if (range <= 70) {
                Console.WriteLine(((range - 30) / 5 + 80).ToString("00"));
                return;
            }
            Console.WriteLine("89");
        }
    }
}