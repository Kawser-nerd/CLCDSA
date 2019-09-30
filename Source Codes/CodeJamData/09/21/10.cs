using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GCJ2009R1B {
    class Program {
        class Node {
            public double p;
            public string feature;
            public Node True, False;
            public Node parent;
            public Node(Node parent) {
                this.parent = parent;
            }
            public override string ToString() {
                if (feature != null)
                    return string.Format("({0} {1} {2} {3})", p, feature, True, False);
                else return string.Format("({0})", p);
            }
            public double Evaluate(string[] Features) {
                if (feature == null) return p;
                else {
                    Node branch = (Features.Contains(feature))?True:False;
                    return p * branch.Evaluate(Features);
                }
            }
        }
        private int ReadSubTree(string[] Tokens, Node Root,int pos) {
            Debug.Assert(Tokens[pos]=="(");
            Root.p = double.Parse(Tokens[pos + 1]);
            if (Tokens[pos + 2] != ")") {
                // This is non leaf node
                Root.feature = Tokens[pos + 2];
                Root.True = new Node(Root);
                int pos1 = ReadSubTree(Tokens, Root.True, pos + 3);
                Root.False = new Node(Root);
                int pos2 = ReadSubTree(Tokens, Root.False, pos1 + 1);
                Debug.Assert(Tokens[pos2 + 1] == ")");
                return pos2 + 1;
            }
            else {
                Debug.Assert(Tokens[pos + 2] == ")");
                return pos + 2;
            }
        }
        private Node ReadTree() {
            Node Tree = new Node(null);
            int lines = int.Parse(Console.ReadLine());
            string StrTree="";
            for (int i = 0; i < lines; ++i) StrTree += Console.ReadLine();
            StrTree = StrTree.Replace("("," ( ").Replace(")"," ) ");
            string[] Tokens = StrTree.Split(new char[]{' ','\t','\r','\n'}).Where(p=>(p!="")).ToArray();
            ReadSubTree(Tokens,Tree,0);
            return Tree;
        }
        public Program() {
            int ncases = int.Parse(Console.ReadLine());
            for (int i = 0; i < ncases; ++i) {
                Console.WriteLine("Case #{0}:", i + 1);
                Node Tree = ReadTree();
                int nAnimals = int.Parse(Console.ReadLine());
                for (int a = 0; a < nAnimals; ++a) {
                    string[] sAnimal = Console.ReadLine().Split().Skip(2).ToArray();
                    Console.WriteLine("{0:0.0000000}",Tree.Evaluate(sAnimal));
                }
            }
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
