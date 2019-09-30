using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Tree
        {
            private double weight;
            private string feature;
            private Tree positive;
            private Tree negative;

            public Tree(string str, ref int index)
            {
                while (str[index] != '(')
                {
                    index += 1;
                }
                index += 1;

                while (str[index] == ' ')
                {
                    index += 1;
                }

                string weight = "";
                while ((str[index] >= '0' && str[index] <= '9') || str[index] == '.')
                {
                    weight += str[index];
                    index += 1;
                }
                this.weight = Double.Parse(weight, CultureInfo.InvariantCulture);

                while (str[index] == ' ')
                {
                    index += 1;
                }

                if (str[index] != ')')
                {
                    feature = "";
                    while (str[index] != ' ')
                    {
                        feature += str[index];
                        index += 1;
                    }

                    positive = new Tree(str, ref index);
                    negative = new Tree(str, ref index);
                    while (str[index] != ')')
                    {
                        index += 1;
                    }
                }
                index += 1;
            }

            public double Solve(Dictionary<string, bool> features)
            {
                if (feature == null)
                {
                    return weight;
                }
                if (features.ContainsKey(feature))
                {
                    return positive.Solve(features) * weight;
                }
                else
                {
                    return negative.Solve(features) * weight;
                }
            }
        }

        static string RemoveSpaces(string str)
        {
            StringBuilder sb = new StringBuilder();
            bool space = true;
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == ' ')
                {
                    if (!space)
                    {
                        space = true;
                        sb.Append(' ');
                    }
                }
                else
                {
                    space = false;
                    sb.Append(str[i]);
                }
            }
            return sb.ToString();
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
                {
                    int N = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < N; i++)
                    {
                        writer.WriteLine("Case #" + (i + 1) + ":");

                        int L = Int32.Parse(reader.ReadLine());
                        StringBuilder sb = new StringBuilder();
                        for (int j = 0; j < L; j++)
                        {
                            if (j > 0) sb.Append(' ');
                            sb.Append(reader.ReadLine());
                        }
                        int index = 0;
                        Tree tree = new Tree(sb.ToString(), ref index);

                        int A = Int32.Parse(reader.ReadLine());
                        for (int j = 0; j < A; j++)
                        {
                            string[] features = RemoveSpaces(reader.ReadLine()).Split();
                            Dictionary<string, bool> dict = new Dictionary<string, bool>();
                            for (int k = 2; k < features.Length; k++)
                            {
                                dict.Add(features[k], true);
                            }
                            writer.WriteLine(tree.Solve(dict).ToString("F7", CultureInfo.InvariantCulture));
                        }
                    }
                }
            }
        }
    }
}
