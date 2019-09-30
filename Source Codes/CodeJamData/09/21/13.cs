using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections.Generic;

namespace A
{
    class Program1
    {
        static void Main(string[] args)
        {
            StreamReader re = File.OpenText("input.txt");
            FileInfo t = new FileInfo("output.txt");
            StreamWriter Tex = t.CreateText();
            
            int N = int.Parse(re.ReadLine());
            for (int i = 0; i < N; i++)
            {
                int L = int.Parse(re.ReadLine());
                string tree = "";
                for (int j = 0; j < L; j++)
                {
                    tree += re.ReadLine();
                }
                tree=tree.Replace("("," ( ");
                tree=tree.Replace(")"," ) ");
                while(tree.Contains("  "))                
                    tree = tree.Replace("  ", " ");                

                string [] des = tree.Split();

                // Output for one map
                Tex.WriteLine("Case #{0}:", i+1);

                int A = int.Parse(re.ReadLine());
                for (int j = 0; j < A; j++)
                {
                    string [] animal = re.ReadLine().Split();
                    int fN = int.Parse(animal[1]);
                    double p = 1;
                    // Check
                    int k=0; bool done = false;
                    while (!done)
                    {
                        //next node
                        while (des[k] != "(") k++;
                        k++;
                        double prob = double.Parse(des[k]);
                        p *= prob;
                        k++;
                        if (des[k] == ")")
                        {
                            done = true;
                        }
                        else
                        {
                            done = false;
                            // Check which subtree
                            string key = des[k]; // Key
                            bool present = false;
                            for (int x = 2; x < 2 + fN; x++)
                            {
                                if (animal[x] == key) { present = true; break; }
                            }
                            if (present) // Follow first subtree
                            {
                                //continue
                            }
                            else
                            { //Skip
                                k++; // points to (
                                int level = 0;
                                while (level >= 0)
                                {
                                    k++;
                                    if (des[k] == "(") level++;
                                    if (des[k] == ")") level--;
                                }
                                //Shall be pointing to the next subtree
                            }
                        }
                    }
                    Tex.WriteLine("{0}", p.ToString("0.#######"));
                }

            }
            re.Close();
            Tex.Close();
        }
    }
}
