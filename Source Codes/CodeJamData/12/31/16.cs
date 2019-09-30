using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Dynamic;

namespace CodeJam_1C_2012
{
    class Problem_B
    {
        public static void Prob_B(string[] args)
        {
            string inputFile = "A-large.in";
           // string inputFile = "B-small-attempt0.in";
            string outputFile = "A-large-result.out";

            TextReader reader = new StreamReader(inputFile);
            TextWriter writer = new StreamWriter(outputFile);

            int TestCases = int.Parse(reader.ReadLine());

            for (int caseCount = 0; caseCount < TestCases; caseCount++)
            {
                string line = reader.ReadLine();
                string[] words = line.Split(' ');

                //output:
                string sout = "Case #" + (caseCount + 1) + ": ";
                writer.Write(sout);
                Console.Write(sout);
                writer.Flush();

                int nrnodes = int.Parse(words[0]);

                List<dynamic> Nodes = new List<dynamic>();
                for (int nodeCounter = 0; nodeCounter < nrnodes; nodeCounter++)
                {
                    line = reader.ReadLine();
                    words = line.Split(' ');
                    dynamic node = new ExpandoObject();
                    Nodes.Add(node);
                    node.Neighbours = new LinkedList<int>();
                    for (int i = 1; i < words.Count(); i++)
                    {
                        node.Neighbours.AddLast(int.Parse(words[i]));
                    }
                }


                bool result = false;
                for (int nodeCounter = 1; nodeCounter <= nrnodes; nodeCounter++)
                {
                    dynamic node = Nodes[nodeCounter-1];
                    LinkedList<int> reachables = new LinkedList<int>();
                    LinkedList<int> actual = new LinkedList<int>();
                    LinkedList<int> newGen = new LinkedList<int>();

                    foreach (var item in node.Neighbours)
                    {
                        reachables.AddLast(item);
                        actual.AddLast(item);
                    }

                    while (actual.Count > 0)
                    {
                        newGen = new LinkedList<int>();
                        foreach (var item in actual)
                        {
                            foreach (var itemChild in Nodes[item-1].Neighbours)
                            {
                                if (reachables.Contains(itemChild))
                                {
                                    result = true;
                                    break;
                                }
                                newGen.AddLast(itemChild);
                                reachables.AddLast(itemChild);
                            }
                        }
                        actual = newGen;
                    }


                }

                if (result)
                {
                    writer.WriteLine("Yes");
                    Console.WriteLine("Yes");
                    writer.Flush();
                }
                else
                {
                    writer.WriteLine("No");
                    Console.WriteLine("No");
                    writer.Flush();
                }

            }



            Console.ReadLine();
        }
    }
}
