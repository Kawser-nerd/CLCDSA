using System;
using System.Globalization;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    class Program
    {
        class Animal
        {
            public HashSet<string> features;
        }

        class Tree
        {
            public double Weight;
            public string Feature;
            public Tree First, Second;

            public static Tree Parse(string text, ref int index)
            {
                index = text.IndexOf('(', index) + 1;
                while (char.IsWhiteSpace(text, index))
                    index++;
                int next = text.IndexOfAny(new[] { ')', ' ' }, index);
                double weight = double.Parse(text.Substring(index, next - index).Trim());
                index = next;
                while (char.IsWhiteSpace(text, index))
                    index++;
                if (text[index] == ')')
                {
                    index++;
                    return new Tree { Weight = weight };
                }
                next = text.IndexOfAny(new[] {' ', '('}, index);
                string feature = text.Substring(index, next - index);
                index = next;
                Tree first = Parse(text, ref index);
                Tree second = Parse(text, ref index);
                index = text.IndexOf(')', index) + 1;
                return new Tree {
                    Weight = weight,
                    Feature = feature,
                    First = first,
                    Second = second
                };
            }

            public double Process(Animal animal)
            {
                if (Feature != null)
                {
                    return Weight * (animal.features.Contains(Feature) ? First : Second).Process(animal);
                }
                return Weight;
            }

        }

        const string InputFile = @"..\..\Input.txt";
        const string OutputFile = @"..\..\Output.txt";

        //static int[] SplitInts(string line)
        //{
        //    var tokens = line.Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries);
        //    var res = new int[tokens.Length];
        //    for (int i = 0; i < res.Length; i++)
        //        res[i] = int.Parse(tokens[i], CultureInfo.InvariantCulture);
        //    return res;
        //}

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(InputFile))
            using (StreamWriter writer = new StreamWriter(OutputFile))
            {
                int N = int.Parse(reader.ReadLine());
                for (int i = 0; i < N; i++)
                {
                    int L = int.Parse(reader.ReadLine());
                    StringBuilder builder = new StringBuilder();
                    for (int j = 0; j < L; j++)
                    {
                        builder.Append(reader.ReadLine());
                    }
                    int index = 0;
                    Tree tree = Tree.Parse(builder.ToString(), ref index);
                    int A = int.Parse(reader.ReadLine());
                    writer.WriteLine("Case #{0}:", i + 1);
                    for (int j = 0; j < A; j++)
                    {
                        var tokens = reader.ReadLine().Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                        Animal a = new Animal {
                            features = new HashSet<string>(tokens.Skip(2))
                        };
                        writer.WriteLine("{0:0.0000000}", tree.Process(a));
                    }
                }
            }
        }
    }
}