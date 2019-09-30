using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20190308_06 {
    class Program {
        static void Main(string[] args) {
            var line0 = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var n = line0[0];
            var m = line0[1];
            var line1 = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            var list = new List<int>();
            for (int j = 0; j < line1[0]; j++) {
                list.Add(line1[j + 1]);
            }
            for (int i = 1; i < n; i++) {
                var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).Skip(1).ToArray();
                list = list.Where(x => line.Any(d => d == x)).ToList();
            }
            Console.WriteLine(list.Count);
        }
    }
}