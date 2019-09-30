using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;


public class Round1A
{
    class DTree
    {
        public double p;
        public string name;
        public DTree TrueTree;
        public DTree FalseTree;
        public DTree(string treestr)
        {
            //Console.WriteLine("parse p");
            double tp = 0.0;
            double t = 1.0;
            int i = 1;
            bool flag = true;
            while (treestr[i] <= '9' && treestr[i] >= '0' || treestr[i] == '.')
            {
                if (treestr[i] == '.')
                {
                    flag = false;
                    ++i;
                    continue;
                }
                if (flag)
                {
                    tp *= 10.0;
                    tp += treestr[i] - '0';
                }
                else
                {
                    t /= 10.0;
                    tp += t * (treestr[i] - '0');
                }
                ++i;
            }
            p = tp;

            //Console.WriteLine("parse name and subtree");
            int len = 0;
            while (treestr[i + len] <= 'z' && treestr[i + len] >= 'a')
            {
                ++len;
            }
            if (len == 0)
            {
                name = null;
                TrueTree = null;
                FalseTree = null;
            }
            else
            {
                name = treestr.Substring(i, len);

                // parse TrueTree
                i += len;
                len = 1;
                int cnt = 1;
                while (cnt != 0)
                {
                    ++len;
                    if (treestr[i + len] == '(')
                        ++cnt;
                    else if (treestr[i + len] == ')')
                        --cnt;
                }
                ++len;
                TrueTree = new DTree(treestr.Substring(i, len));

                // parse FalseTree
                i += len;
                len = 1;
                cnt = 1;
                while (cnt != 0)
                {
                    ++len;
                    if (treestr[i + len] == '(')
                        ++cnt;
                    else if (treestr[i + len] == ')')
                        --cnt;
                }
                ++len;
                FalseTree = new DTree(treestr.Substring(i, len));
            }
        }
    }

    class Animal
    {
        public double p;
        public string name;
        public HashSet<string> features = new HashSet<string>();
    }

    static StreamReader sr = new StreamReader(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\in.txt");
    static StreamWriter sw = new StreamWriter(@"C:\Users\yuzou\Documents\TestProgram\CSharpTest\CSharpTest\CSharpTest\out.txt");

    public static void Main(string[] args)
    {
        DateTime start = DateTime.Now;


        string str = sr.ReadLine();
        int tt = int.Parse(str);


        for (int t = 1; t <= tt; t++)
        {
            sw.WriteLine("Case #{0}:", t);

            str = sr.ReadLine().Trim();
            int lines = int.Parse(str);
            DTree root = CreateDTree(lines);

            str = sr.ReadLine();
            int num = int.Parse(str);

            for (int i = 0; i < num; i++)
            {
                Animal ani = GetAnimal();
                ani.p = 1.0;
                Calcu(ani, root);
                sw.WriteLine(ani.p.ToString("0.0000000"));
            }
        }

        sw.Close();
        DateTime end = DateTime.Now;
        Console.WriteLine(end - start);
    }

    private static void Calcu(Animal ani, DTree tree)
    {
        ani.p *= tree.p;
        if (string.IsNullOrEmpty(tree.name))
            return;
        if (ani.features.Contains(tree.name))
        {
            Calcu(ani, tree.TrueTree);
        }
        else
        {
            Calcu(ani, tree.FalseTree);
        }
    }

    private static Animal GetAnimal()
    {
        string[] aniArgs = sr.ReadLine().Split(' ');
        Animal ani = new Animal();
        ani.name = aniArgs[0];
        ani.features = new HashSet<string>();
        for (int i = 2; i < aniArgs.Length; i++)
        {
            ani.features.Add(aniArgs[i]);
        }
        return ani;
    }

    private static DTree CreateDTree(int lines)
    {
        StringBuilder treestr = new StringBuilder("");
        for (int i = 0; i < lines; i++)
        {
            treestr = treestr.Append(sr.ReadLine().Replace(" ", ""));
        }

        return new DTree(treestr.ToString());
    }
}
