using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.ComponentModel;
using System.Globalization;

namespace R1A
{
    class Program
    {
        static void Main(string[] args)
        {
            var InputFile = "input.txt";
            if (args.Length >= 1)
            {
                InputFile = args[0];
            }

            OpenFile(InputFile);
            StartCompute();

            char[] whitespaces = { ' ' };

            int N = Read<int>();
            for (int n = 1; n <= N; n++)
            {
                Console.WriteLine("Case #{0}:", n);

                int L = Read<int>();
                StringBuilder sb = new StringBuilder(L * 10);

                for (int l = 0; l < L; l++)
                {
                    sb.Append(reader.ReadLine());
                }

                int offset = 0;
                TreeObject tree = ParseTree(sb.ToString(), ref offset);

                int A = Read<int>();
                for (int a = 0; a < A; a++)
                {
                    var features = new HashSet<String>();

                    string f = reader.ReadLine();
                    string[] fs = f.Split(whitespaces, StringSplitOptions.RemoveEmptyEntries);
                    foreach (string feature in fs.Skip(2))
                        features.Add(feature);

                    double res = tree.Evaluate(1.0, features);
                    //Console.WriteLine("{0,1.7}", res);
                    Console.WriteLine(res.ToString("0.0000000", System.Globalization.CultureInfo.InvariantCulture.NumberFormat));
                }
            }

            EndCompute();
        }


        //static IFormatProvider

        static TreeObject ParseTree(string str, ref int offset) {
            while (str[offset] != '(') offset++;
            offset++;

            while (Char.IsWhiteSpace(str[offset])) offset++;

            StringBuilder sb = new StringBuilder(10);
            while (Char.IsDigit(str[offset]) || str[offset] == '.')
            {
                sb.Append(str[offset]);
                offset++;
            }

            double p;
            p = Double.Parse(sb.ToString(), NumberStyles.Number, System.Globalization.CultureInfo.InvariantCulture.NumberFormat);                  

            while (Char.IsWhiteSpace(str[offset])) offset++;
            if (str[offset] == ')')
            {
                TreeLeaf leaf = new TreeLeaf();
                leaf.probability = p;
                offset++;
                return leaf;
            }

            sb = new StringBuilder(10);

            while (Char.IsLetter(str[offset]))
            {
                sb.Append(str[offset]);
                offset++;
            }

            TreeNode node = new TreeNode();
            node.probability = p;
            node.feature = sb.ToString();

            sb = null;
            node.firstTree = ParseTree(str, ref offset);
            node.secondTree = ParseTree(str, ref offset);

            while (Char.IsWhiteSpace(str[offset])) offset++;
            if (str[offset] != ')') throw new Exception("ukoncovaci zavorka chybi");

            offset++;
            return node;
        }

        // Read methods

        static int time;
        static void StartCompute()
        {
            int time = System.Environment.TickCount;
        }

        static int EndCompute()
        {
            return System.Environment.TickCount - time;
        }

        static TextReader reader;
        static Queue<string> LineBuffer;

        static void OpenFile(string FileName)
        {
            reader = new StreamReader(FileName);
            LineBuffer = new Queue<string>();
        }

        static T Read<T>() where T : struct
        {
            if (LineBuffer == null)
                throw new NullReferenceException("Word queue is not initilized.");

            if (reader == null)
                throw new NullReferenceException("Text file reader is not initialized.");

            if (LineBuffer.Count == 0)
            {
                string line = reader.ReadLine();
                foreach (string val in line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
                    LineBuffer.Enqueue(val);
            }

            if (TypeDescriptor.GetConverter(typeof(T)).CanConvertFrom(typeof(string)))
                return (T)TypeDescriptor.GetConverter(typeof(T)).ConvertFrom(null, CultureInfo.GetCultureInfo(0x0409), LineBuffer.Dequeue());

            throw new Exception("Unknown error while reading value.");
        }
 
    }


    interface TreeObject
    {
        double Evaluate(double p, HashSet<String> features);
    }

    class TreeNode: TreeObject
    {
        public TreeObject firstTree;
        public TreeObject secondTree;
        public double probability;
        public String feature;

        public TreeNode() { }

        public double Evaluate(double p, HashSet<String> features)
        {
            p = p * probability;

            if (features.Contains(feature))
            {
                return firstTree.Evaluate(p, features);
            }
            else
            {
                return secondTree.Evaluate(p, features);
            }

        }
    }

    class TreeLeaf: TreeObject 
    {
        public double probability;

        public TreeLeaf() { }

        public double Evaluate(double p, HashSet<string> features)
        {
            return p * probability;
        }
    }
}
