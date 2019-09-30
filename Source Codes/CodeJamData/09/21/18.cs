using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static string[] elem;
        static int index;
        static Dictionary<string, bool> dict;
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter("A-large.out"))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= T; tc++)
                    {
                        int lineCount = int.Parse(sr.ReadLine());
                        StringBuilder sb = new StringBuilder();
                        for (int i = 0; i < lineCount; i++)
                        {
                            sb.Append(sr.ReadLine());
                        }
                        elem = sb.ToString().Split(new char[] { ' ', '\n', '\r', '(', ')', '[', ']' }, StringSplitOptions.RemoveEmptyEntries);
                        index = 0;
                        Tree root = new Tree();
                        Parse(root);

                        int A = int.Parse(sr.ReadLine());
                        sw.WriteLine("Case #{0}:", tc);
                        for (int i = 0; i < A; i++)
                        {
                            string[] line = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                            int fcount = int.Parse(line[1]);
                            dict = new Dictionary<string, bool>();
                            for (int j = 0; j < fcount; j++)
                            {
                                dict[line[2 + j]] = true;
                            }

                            sw.WriteLine("{0:0.0000000}", Count(root));
                        }
                    }
                }
            }
        }
        static double Count(Tree root)
        {
            double res = root.weight;

            if (root.feature != null)
            {
                if (dict.ContainsKey (root.feature) == true)
                {
                    return res * Count(root.left);
                }
                else
                {
                    return res * Count(root.right);
                }
            }
            else
                return res;
        }
        static void Parse(Tree root)
        {
            root.weight = double.Parse(elem[index++]);
            if (index < elem.Length && !IsDouble(elem[index]))
            {
                root.feature = elem[index++];
                root.left = new Tree () ;
                root.right = new Tree ();
                Parse(root.left);
                Parse(root.right);
            }
        }

        static bool IsDouble(string text)
        {
            double x;
            if (double.TryParse(text, out x) == false)
            {
                return false;
            }
            return true;
        }
    }

    class Tree
    {
        public Tree left, right;
        public string feature;
        public double weight;
    }
}
