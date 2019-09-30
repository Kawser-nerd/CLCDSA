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
                var n = int.Parse(elements[0]);
                var m = int.Parse(elements[1]);
                var words = new string[n];
                var patterns = new int[n, 26];
                for (int i = 0; i < n; i++) {
                    words[i] = Console.ReadLine();
                    for (int c = 0; c < words[i].Length; c++)
                        patterns[i, words[i][c] - 'a'] |= 1 << c;
                }
                var orders = new char[m][];
                for (int i = 0; i < m; i++)
                    orders[i] = Console.ReadLine().ToCharArray();

                testTasks[testNumber - 1] = Task.Factory.StartNew<string>(() => {
                    // Calculations

                    var maxWords = new string[m];
                    for (int i = 0; i < m; i++) {
                        var maxPrice = -1;
                        for (int j = 0; j < n; j++) {
                            var price = 0;
                            for (int k = 0; k < 26; k++) {
                                if (patterns[j, orders[i][k] - 'a'] == 0) {
                                    for (int jj = 0; jj < n; jj++)
                                        if (j != jj && words[j].Length == words[jj].Length && patterns[jj, orders[i][k] - 'a']!= 0) {
                                            bool match = true;
                                            for (int kk = 0; kk < k; kk++)
                                                if (patterns[j, orders[i][kk] - 'a'] != patterns[jj, orders[i][kk] - 'a']) {
                                                    match = false;
                                                    break;
                                                }
                                            if (match) {
                                                price++;
                                                break;
                                            }
                                        }
                                }
                            }
                            if (price > maxPrice) {
                                maxPrice = price;
                                maxWords[i] = words[j];
                            }
                        }
                    }
                    return string.Join(" ", maxWords);
                });
            }
            Task.WaitAll(testTasks);
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
                Console.WriteLine("Case #{0}: {1}", testNumber, testTasks[testNumber - 1].Result);
        }
    }
}
