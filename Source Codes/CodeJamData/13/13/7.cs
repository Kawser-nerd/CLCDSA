using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamCS {
    class GoodLuck {
        private const string ProblemLetter = "C";
        private readonly StreamReader _reader;
        private readonly StreamWriter _writer;

        public GoodLuck(StreamReader reader, StreamWriter writer) {
            _reader = reader;
            _writer = writer;
        }

        static void Main(string[] args) {
            var difficulty = "small-1-attempt2";
            var inputFile = string.Format("{0}-{1}.in", ProblemLetter, difficulty);
            var outputFile = string.Format("{0}-{1}.out", ProblemLetter, difficulty);
            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
                new GoodLuck(reader, writer).Run();
        }

        private void Run() {
            int testCount = int.Parse(_reader.ReadLine());
            for (int test = 1; test <= testCount; ++test) {
                var answer = SolveTest();
                _writer.Write("Case #{0}:\n{1}", test, answer);
            }
        }

        private Dictionary<string, Dictionary<int, double>> probs = new Dictionary<string, Dictionary<int, double>>(); 
        private Dictionary<string, HashSet<int>> productSets = new Dictionary<string, HashSet<int>>(); 
        private Dictionary<string, double> prior = new Dictionary<string, double>(); 

        private void UpdateDict<K>(Dictionary<K, double> dictionary, K key, double delta) {
            if (!dictionary.ContainsKey(key))
                dictionary[key] = 0;
            dictionary[key] += delta;
        }

        private string SolveTest() {
            var line = _reader.ReadLine().Split(' ');
            int R = int.Parse(line[0]), N = int.Parse(line[1]), M = int.Parse(line[2]), K = int.Parse(line[3]);
            // R = 100, N = 3, M = 5, K = 7
            for (int a1 = 2; a1 <= M; a1++) {
                for (int a2 = 2; a2 <= M; a2++) {
                    for (int a3 = 2; a3 <= M; a3++) {
                        string digitKey = string.Concat(new[] { a1, a2, a3 }.OrderBy(x => x));
                        if (!probs.ContainsKey(digitKey)) {
                            probs[digitKey] = new Dictionary<int, double>();
                            productSets[digitKey] = new HashSet<int>();
                            prior[digitKey] = 0;
                        }
                        prior[digitKey] += 1;
                        UpdateDict(probs[digitKey], 1, 1);
                        UpdateDict(probs[digitKey], a1, 1);
                        UpdateDict(probs[digitKey], a2, 1);
                        UpdateDict(probs[digitKey], a3, 1);
                        UpdateDict(probs[digitKey], a1 * a2, 1);
                        UpdateDict(probs[digitKey], a2 * a3, 1);
                        UpdateDict(probs[digitKey], a1 * a3, 1);
                        UpdateDict(probs[digitKey], a1 * a2 * a3, 1);
                    }
                }
            }

            foreach (var key in probs.Keys) {
                var sum = probs[key].Values.Sum();
                var products = probs[key].Keys.ToArray();
                foreach (var product in products) {
                    probs[key][product] /= sum;
                }
                productSets[key] = new HashSet<int>(probs[key].Keys);
            }
            var totalKeys = prior.Values.Sum();
            foreach (var key in probs.Keys)
                prior[key] /= totalKeys;

            // Start solving

            int correctCount = 0;
            var answer = new StringBuilder();
            for (int test = 0; test < R; ++test) {
                //var products = GenerateProducts(N, M, K);
                var products = _reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var givenProductSet = new HashSet<int>(products);
                var possibleSets = probs.Keys.Where(key => givenProductSet.IsSubsetOf(productSets[key])).ToArray();
                if (possibleSets.Length == 1) {
                    answer.AppendLine(possibleSets[0]);
                    ++correctCount;
                    continue;
                }

                string maxPossibleKey = possibleSets[0];
                double maxPosterior = double.NegativeInfinity;
                foreach (var key in possibleSets) {
                    var posterior = prior[key];
                    foreach (var p in products)
                        posterior *= probs[key][p];
                    if (posterior > maxPosterior) {
                        maxPosterior = posterior;
                        maxPossibleKey = key;
                    }
                }
                answer.AppendLine(maxPossibleKey);

                Console.WriteLine("{0} chosen out of {1} options", maxPossibleKey, possibleSets.Length);
                Console.WriteLine("> " + string.Join(" ", products.OrderBy(x => x)));
                Console.WriteLine(maxPossibleKey + ": " + string.Join(" ", productSets[maxPossibleKey].OrderBy(x => x)));
                foreach (var key in possibleSets)
                    if (key != maxPossibleKey)
                        Console.WriteLine(key + ": " + string.Join(" ", productSets[key].OrderBy(x => x)));
                //if (maxPossibleKey == _correctKey)
                //    correctCount++;
                //Console.WriteLine("{0}, correct = {1}", maxPossibleKey, _correctKey);
                Console.WriteLine();
            }

            Console.WriteLine("{0}/{1}", correctCount, R);
            return answer.ToString();
        }

        private readonly Random _rand = new Random();
        private string _correctKey;

        private int[] GenerateProducts(int N, int M, int K) {
            var digits = new int[N];
            for (int i = 0; i < N; i++) {
                digits[i] = _rand.Next(M - 1) + 2;
            }
            _correctKey = string.Concat(digits.OrderBy(x => x));

            var products = new List<int>();
            for (int i = 0; i < K; i++) {
                var subset = new List<int>();
                foreach (var n in digits)
                    if (_rand.Next(2) == 0)
                        subset.Add(n);
                products.Add(subset.Aggregate(1, (x, y) => x * y));
            }
            return products.ToArray();
        }
    }
}
