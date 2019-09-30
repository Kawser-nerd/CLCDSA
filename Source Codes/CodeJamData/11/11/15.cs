using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam {
    class Program {
        static void Main(string[] args) {
            string line = Console.ReadLine();
            int testCount = int.Parse(line);
            var testTasks = new Task<string>[testCount];
            for (int testNumber = 1; testNumber <= testCount; testNumber++) {
                // Reading input
                var elements = Console.ReadLine().Split();
                var n = elements[0].TrimStart('0').Length > 2 ? 100 : int.Parse(elements[0]);
                var pd = int.Parse(elements[1]);
                var pg = int.Parse(elements[2]);

                testTasks[testNumber - 1] = Task.Factory.StartNew<string>(() => {
                    // Calculations
                    for (int i = 1; i <= n; i++) {
                        if ((i * pd) % 100 == 0) {
                            return (pd > 0 && pg == 0) || (pd < 100 && pg == 100) ? "Broken" : "Possible";
                        }
                    }
                    return "Broken";

                });
            }
            Task.WaitAll(testTasks);
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
                Console.WriteLine("Case #{0}: {1}", testNumber, testTasks[testNumber - 1].Result);
        }
    }
}
