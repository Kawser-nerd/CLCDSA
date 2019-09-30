using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190308_02 {
    class Program {
        static void Main(string[] args) {
            var n = int.Parse(Console.ReadLine());
            var list = new string[n, 2];
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Split(' ').ToArray();
                list[i, 0] = line[0];
                list[i, 1] = line[1];
            }
            var sum = 0.0;
            for (int i = 0; i < n; i++) {
                if (list[i, 1] == "JPY") {
                    sum += double.Parse(list[i, 0]);
                } else {
                    sum += double.Parse(list[i, 0]) * 380000.0;
                }
            }
            Console.WriteLine(sum);
        }
    }
}