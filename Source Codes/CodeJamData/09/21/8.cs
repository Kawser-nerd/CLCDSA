using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace cjcs
{
    class Program
    {

        class AnimalSolver
        {
            class TreeNode
            {
                public double weight;
                public string feature = null;
                public TreeNode left = null;
                public TreeNode right = null;
            }

            private TreeNode root;
            private string[] animals;

            public AnimalSolver(string tree, string[] animals)
            {
                root = ProcessTree(tree, 0, tree.Length);
                this.animals = animals;
            }

            private TreeNode ProcessTree(string tree, int st, int en)
            {
//                Console.Error.WriteLine(tree.Substring(st, en - st));
                int p = st;
                while (tree[p] == '(' || tree[p] == ' ') p++;
                int q = p;
                while (tree[q] != ' ' && tree[q] != ')') q++;
                TreeNode node = new TreeNode();
                node.weight = double.Parse(tree.Substring(p, q - p));
                while (tree[q] == ' ') q++;
                if (tree[q] == ')') return node;
                int r = tree.IndexOf(' ', q);
                node.feature = tree.Substring(q, r-q);
                r = tree.IndexOf('(', r);
                q = r;
                int c = 1;
                while (c > 0) 
                {
                    r++;
                    if (tree[r] == ')') c--;
                    else if (tree[r] == '(') c++;
                }
                node.left = ProcessTree(tree, q, r + 1);
                r = tree.IndexOf('(', r);
                q = r;
                c = 1;
                while (c > 0)
                {
                    r++;
                    if (tree[r] == ')') c--;
                    else if (tree[r] == '(') c++;
                }
                node.right = ProcessTree(tree, q, r + 1);
                return node;
            }

            public void Solve(StreamWriter sw)
            {
                foreach (string ani in animals)
                {
                    string[] ll = ani.Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
                    int n = int.Parse(ll[1]);
                    HashSet<string> se = new HashSet<string>();
                    for (int i=0; i<n; i++) se.Add(ll[2 + i]);
                    double ans = FindValue(root, se);
                    sw.WriteLine("{0:f7}", ans);
                }
            }

            private double FindValue(TreeNode root, HashSet<string> set)
            {
                if (root.feature == null)
                {
                    return root.weight;
                }
                else
                {
                    if (set.Contains(root.feature))
                    {
                        return root.weight * FindValue(root.left, set);
                    }
                    else
                        return root.weight * FindValue(root.right, set);
                }
            }
        }

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("r1a.in"))
            {
                using (StreamWriter sw = new StreamWriter("r1a.out"))
                {
                    string sn = sr.ReadLine().Trim();
                    int N = int.Parse(sn);
                    for (int i=0; i<N; i++)
                    {
                        string sl = sr.ReadLine().Trim();
                        int l = int.Parse(sl);
                        StringBuilder sb = new StringBuilder();
                        for (int j=0; j<l; j++)
                        {
                            string s = sr.ReadLine().Trim();
                            sb.Append(' ').Append(s);
                        }
                        string sa = sr.ReadLine().Trim();
                        int a = int.Parse(sa);
                        string[] animals = new string[a];
                        for (int j = 0; j < a; j++) animals[j] = sr.ReadLine().Trim();
                        sw.WriteLine("Case #{0}:", i+1);
                        new AnimalSolver(sb.ToString(), animals).Solve(sw);
                    }
                }
            }
        }
    }
}
