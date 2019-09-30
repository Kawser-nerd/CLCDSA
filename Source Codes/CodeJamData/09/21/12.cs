using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace R1_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string filePath = @"C:\A-large.in";

            using (StreamReader reader = new StreamReader(filePath))
            {
                using (StreamWriter writer = new StreamWriter(@"C:\result.txt"))
                {
                    int N = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= N; i++)
                        GetCase(reader, writer, i);
                }
            }
        }

        public static void GetCase(StreamReader reader, StreamWriter writer, int caseNumber)
        {
            int L = int.Parse(reader.ReadLine());
            string tree = "";
            for (int i = 0; i < L; i++)
                tree += reader.ReadLine() + '\n';

            int A = int.Parse(reader.ReadLine());
            string[] animals = new string[A];
            for (int i = 0; i < A; i++)
                animals[i] = reader.ReadLine();

            writer.WriteLine(string.Format("Case #{0}:", caseNumber));
            var nodes = GetTree(tree);

            foreach (string animal in animals)
            {
                var stuff = animal.Split(' ');
                var idents = stuff.Skip(2).ToArray();

                writer.WriteLine(GetProbability(1, nodes, idents).ToString("0.0000000"));
            }
        }

        public static string TreeString = null;
        public static int Index = 0;

        public static DecisionNode GetTree(string t)
        {
            TreeString = t;
            Index = 0;
            return ConsumeNode();
        }

        public static DecisionNode ConsumeNode()
        {
            DecisionNode newNode = new DecisionNode();
            ConsumeParen('(');
            newNode.Probability = ConsumeProbability();
            newNode.Identifier = ConsumeIdentifier();

            if (newNode.Identifier == null)
                ConsumeParen(')');
            else
            {
                newNode.Positive = ConsumeNode();
                newNode.Negative = ConsumeNode();
                ConsumeParen(')');
            }

            return newNode;
        }

        public static void ConsumeWhitespace()
        {
            while (char.IsWhiteSpace(TreeString[Index])) Index++;
        }

        public static void ConsumeParen(char paren)
        {
            ConsumeWhitespace();
            Index++;
        }

        public static double ConsumeProbability()
        {
            ConsumeWhitespace();

            string p = "";
            while (char.IsDigit(TreeString[Index]) || TreeString[Index] == '.')
            {
                p += TreeString[Index];
                Index++;
            }

            return double.Parse(p);
        }

        public static string ConsumeIdentifier()
        {
            ConsumeWhitespace();

            string ident = "";
            while (char.IsLetter(TreeString[Index]))
            {
                ident += TreeString[Index];
                Index++;
            }

            return string.IsNullOrEmpty(ident) ? null : ident;
        }

        public static double GetProbability(double p, DecisionNode node, IEnumerable<string> identifiers)
        {
            if (node.Identifier == null)
                return p * node.Probability;

            if (identifiers.Contains(node.Identifier))
                return GetProbability(p * node.Probability, node.Positive, identifiers);
            else
                return GetProbability(p * node.Probability, node.Negative, identifiers);
        }

        public class DecisionNode
        {
            public string Identifier;
            public double Probability;
            public DecisionNode Positive;
            public DecisionNode Negative;
        }
    }
}
