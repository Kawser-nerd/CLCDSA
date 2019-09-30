using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DiamondInheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            var cases = int.Parse(Console.ReadLine());

            for (int i = 1; i <= cases; i++)
            {
                var n = int.Parse(Console.ReadLine());
                var classes = new List<Class>(n);
                for (int j = 0; j < n; j++)
                    classes.Add(new Class(j));
                for (int j = 0; j < n; j++)
                {
                    var line = Console.ReadLine();
                    var tokes = line.Split(' ');
                    var count = int.Parse(tokes[0]);
                    for (int k = 1; k < tokes.Length; k++)
                    {
                        var anc = int.Parse(tokes[k]) - 1;
                        classes[j].Ancestors.Add(anc);
                        classes[anc].Descendents.Add(j);
                    }
                }

                var result = Solve(classes);
                Console.WriteLine("Case #{0}: {1}", i, result ? "Yes" : "No");
            }
        }

        static bool Solve(List<Class> classes)
        {
            var roots = classes.Where(c => c.Ancestors.Count == 0).Select(c => c.name);

            //For each root, make sure we reach each class at most once
            foreach (var root in roots)
            {
                //Console.WriteLine("Class {0} is a root", root);

                var visited = classes.Select(c => false).ToList();

                if (Visit(root, classes, visited))
                    return true;
            }

            return false;
        }

        static bool Visit(int clazz, List<Class> classes, List<bool> visited)
        {
            foreach(var descendent in classes[clazz].Descendents)
            {
                if (visited[descendent])
                    return true;
                visited[descendent] = true;
                //Console.WriteLine("{0} <- {1}", descendent, clazz);
                if(Visit(descendent, classes, visited))
                    return true;
            }

            return false;
        }
    }

    public class Class
    {
        public HashSet<int> Ancestors = new HashSet<int>();
        public HashSet<int> Descendents = new HashSet<int>();
        public int name;

        public Class(int name)
        {
            this.name = name;
        }
    }
}
