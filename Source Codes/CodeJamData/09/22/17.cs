using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam09 {
    class Program {
        static void Main(string[] args) {
            using (StreamReader rdr = new StreamReader(new FileStream("input.in", FileMode.Open))) {
                using (StreamWriter writer = new StreamWriter(new FileStream("output.out", FileMode.Create))) {
                    CallOncePerCase(rdr, writer);
                }
            }
        }

        private static void CallOncePerCase(StreamReader rdr, StreamWriter writer) {
            int n = int.Parse(rdr.ReadLine());
            for (int ii = 1; ii <= n; ii++) {
                writer.WriteLine("Case #{0}: {1}", ii, RunNextNumber(rdr));
            }
        }

        private static void CallOnce(StreamReader rdr, StreamWriter writer) {
            List<string> outputs = new List<string>(); // RunAlienLanguage(rdr);
            int n = outputs.Count;
            for (int ii = 1; ii <= n; ii++) {
                writer.WriteLine("Case #{0}: {1}", ii, outputs[ii- 1]);
            }
        }

        static string RunDecisionTree(StreamReader rdr) {
            string tree = string.Empty;
            List<Animal> animalList = new List<Animal>();

            int l = int.Parse(rdr.ReadLine().Split(' ')[0]);
            for (int ii = 0; ii < l; ii++) {
                tree += " " + rdr.ReadLine();
            }
            int a = int.Parse(rdr.ReadLine().Split(' ')[0]);
            for (int ii = 0; ii < a; ii++) {
                string[] vals = rdr.ReadLine().Split(' ');
                Animal animal = new Animal() { Name = vals[0] };
                for (int jj = 1; jj < vals.Length; jj++) {
                    animal.Features.Add(vals[jj]);
                }
                animalList.Add(animal);
            }
            DecisionTree dTree = new DecisionTree(tree, animalList);
            return dTree.GetOutput();

        }

        static string RunWelcome(StreamReader rdr) {
            Welcome welcome = new Welcome(rdr.ReadLine());
            return welcome.GetOutput();
        }

        static string RunNextNumber(StreamReader rdr) {
            NextNumber nextNum = new NextNumber(rdr.ReadLine());
            return nextNum.Next;
        }
    }
}
