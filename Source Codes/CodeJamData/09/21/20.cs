using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace GCJR1B
{
    class P1
    {
        class DecisionTree
        {
            public double Weight;
            public string Description;
            public DecisionTree LeftChild;
            public DecisionTree RightChild;

            public override string ToString()
            {
                return string.Format("{{{0}{1}}}", Weight, Description == null ? "" : ", " + Description);
            }
        }

        static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.Open(args[1], FileMode.Create)))
                {
                    int numCases = int.Parse(reader.ReadLine());

                    for (int i = 1; i <= numCases; i++)
                    {
                        writer.WriteLine("Case #{0}:", i);

                        var tree = Parse(reader, int.Parse(reader.ReadLine()));

                        var numQueries = int.Parse(reader.ReadLine());

                        for (int j = 0; j < numQueries; j++)
                        {
                            var fields = reader.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                            var numDesc = int.Parse(fields[1]);

                            List<string> descs = new List<string>();

                            for (int k = 0; k < numDesc; k++)
                                descs.Add(fields[2 + k]);

                            writer.WriteLine("{0:0.0000000}", ProbCute(tree, descs));
                        }
                    }
                }
            }
        }

        static double ProbCute(DecisionTree tree, List<string> descs)
        {
            double p = 1;

            while (true) 
            {
                p *= tree.Weight;

                if (tree.Description == null)
                    return p;
                else if (descs.Contains(tree.Description))
                    tree = tree.LeftChild;
                else
                    tree = tree.RightChild;
            }
        }

        static DecisionTree Parse(TextReader reader, int numLines)
        {
            var tree = "";

            for (int i = 0; i < numLines; i++)
            {
                tree += reader.ReadLine() + " ";
            }

            var it = tree.Split("() ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).OfType<string>().GetEnumerator();

            it.MoveNext();

            return Parse(it);
        }

        static DecisionTree Parse(IEnumerator<string> tokens)
        {
            var tree = new DecisionTree();

            tree.Weight = double.Parse(tokens.Current);

            tokens.MoveNext();

            double dummy;

            if (!double.TryParse(tokens.Current, out dummy))
            {
                tree.Description = tokens.Current;

                tokens.MoveNext();

                tree.LeftChild = Parse(tokens);
                tree.RightChild = Parse(tokens);
            }

            return tree;
        }
    }

    class P2
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.Open(args[1], FileMode.Create)))
                {
                    int numCases = int.Parse(reader.ReadLine());

                    for (int i = 1; i <= numCases; i++)
                    {
                        writer.WriteLine("Case #{0}: {1}", i, Next(reader.ReadLine()));
                    }
                }
            }
        }

        static string Next(string n)
        {
            var input = ("0" + n).ToCharArray().Reverse().ToArray();

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] > input[i + 1])
                {
                    var c = input[i + 1];
                    input[i + 1] = input[i];
                    input[i] = c;

                    char min = input.Take(i + 2).Where(x => x > input[i]).Min();

                    for (int j = 0; j <= i; j++)
                    {
                        if (input[j] == min)
                        {
                            input[j] = input[i + 1];
                            input[i + 1] = min;
                            break;
                        }
                    }

                    var sorted = input.Take(i + 1).OrderByDescending(x => x).ToArray();

                    for (int j = 0; j <= i; j++)
                        input[j] = sorted[j];

                    var output = new string(input.Reverse().ToArray());

                    return output[0] == '0' ? output.Substring(1) : output;
                }
            }

            throw new ApplicationException("should've never been reached");
        }
    }

    class P3
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(File.OpenRead(args[0])))
            {
                using (var writer = new StreamWriter(File.Open(args[1], FileMode.Create)))
                {
                }
            }
        }
    }
}
