using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace decision
{
    class Tree
    {
        public double p = 0;
        public bool leaf = true;
        public string feature = "";
        public Tree t1, t2;

        public Tree(string s, ref int ofs)
        {
            for (; s[ofs] != '('; ofs++);
            for (; s[ofs] < '0' || s[ofs] > '9'; ofs++);
            int sofs = ofs;
            for (; (s[ofs] >= '0' && s[ofs] <= '9') || s[ofs] == '.'; ofs++);
            p = double.Parse(s.Substring(sofs, ofs-sofs).Replace('.', ','));
            for (; s[ofs] == ' '; ofs++);
            if (s[ofs] == ')')
            {
                ofs++;
                return;
            }
            leaf = false;
            sofs = ofs;
            for (; s[ofs] != ' ' && s[ofs] != '('; ofs++);
            feature = s.Substring(sofs, ofs - sofs);
            t1 = new Tree(s, ref ofs);
            t2 = new Tree(s, ref ofs);
            for (; s[ofs] != ')'; ofs++);
            ofs++;
        }

        public double Compute(ref HashSet<string> features)
        {
            if (leaf) return p;
            if (features.Contains(feature)) return p * t1.Compute(ref features);
            return p * t2.Compute(ref features);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        void Run()
        {
            int tn = int.Parse(Console.ReadLine());
            for (int ti = 1; ti <= tn; ti++)
            {
                int linen = int.Parse(Console.ReadLine());
                string s = "";
                for (int i = 0; i < linen; i++)
                {
                    s += Console.ReadLine();
                }
                int ofs = 0;
                Tree t = new Tree(s, ref ofs);
                int animaln = int.Parse(Console.ReadLine());
                Console.WriteLine("Case #{0}:", ti);
                for (int i = 0; i < animaln; i++)
                {
                    string[] sp = Console.ReadLine().Split();
                    int fn = int.Parse(sp[1]);
                    HashSet<string> features = new HashSet<string>();
                    for (int j = 0; j < fn; j++)
                    {
                        features.Add(sp[2 + j]);
                    }
                    Console.WriteLine(String.Format("{0:0.0000000}", t.Compute(ref features)).Replace(',', '.'));
                }
            }
        }
    }
}
