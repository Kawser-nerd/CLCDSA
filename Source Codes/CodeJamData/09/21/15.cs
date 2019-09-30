using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace a
{
    class Program
    {
        public class TreeNode
        {
            public TreeNode first;
            public TreeNode second;
            public double weight;
            public string feature;

            private TreeNode(double w)
            {
                weight = w;
            }

            private TreeNode(string f, double w, TreeNode t1, TreeNode t2)
            {
                weight = w;
                feature = f;
                first = t1;
                second = t2;
            }


            private static void SkipSpaces(string source, ref int pos)
            {
                while (source[pos] == ' ' || source[pos] == '\n' || source[pos] == '\r')
                    ++pos;
            }

            public static TreeNode Parse(string source, ref int pos)
            {
                SkipSpaces(source, ref pos);
                ++pos;
                SkipSpaces(source, ref pos);
                int pos2 = pos;
                while (source[pos]=='.' || (source[pos]<='9' && source[pos]>='0'))
                    ++pos;
                double w = double.Parse(source.Substring(pos2, pos - pos2), CultureInfo.InvariantCulture);
                SkipSpaces(source, ref pos);
                if (source[pos] == ')')
                {
                    ++pos;
                    return new TreeNode(w);
                }

                pos2 = pos;
                while (source[pos]<='z' && source[pos]>='a')
                    ++pos;

                string f = source.Substring(pos2, pos - pos2);

                TreeNode t1 = Parse(source, ref pos);
                TreeNode t2 = Parse(source, ref pos);

                while (source[pos] != ')')
                    ++pos;

                ++pos;

                return new TreeNode(f, w, t1, t2);
            }

            public double EstimateCost(List<String> features)
            {
                if (feature == null)
                {
                    return weight;
                }

                if (features.Contains(feature))
                {
                    return weight*first.EstimateCost(features);
                }
                else
                {
                    return weight * second.EstimateCost(features);
                }
            }

        }

        
        
        static void Main(string[] args)
        {
            using (TextReader tr = new StreamReader(@"D:\Downloads\A-large.in"))
            using (TextWriter tw = new StreamWriter(@"D:\Downloads\output.txt"))
            {
                int n = int.Parse(tr.ReadLine());
                for (int i=1; i<=n; ++i)
                {
                    int l = int.Parse(tr.ReadLine());
                    StringBuilder sb = new StringBuilder();
                    for (int j=0; j<l; ++j)
                    {
                        sb.Append(tr.ReadLine());
                        sb.Append(' ');
                    }
                    l = int.Parse(tr.ReadLine());
                    string tree = sb.ToString();
                    int pos = 0;
                    TreeNode root = TreeNode.Parse(tree, ref pos);
                    tw.WriteLine("Case #{0}:", i);
                    for (int j=0; j<l; ++j)
                    {
                        string[] test = tr.ReadLine().Split(' ');
                        string[] features = new string[test.Length - 2];
                        Array.Copy(test, 2, features, 0, features.Length);
                        List<string> fts = new List<string>(features);
                        double ans = root.EstimateCost(fts);
                        tw.WriteLine(ans.ToString("0.000000", CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}
