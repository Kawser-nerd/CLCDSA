using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ.Round1B.A
{
    class Program
    {
        static int nCases;
        static string tree;
        static int pos;

        static string iFN = "X:/A.in";
        static string oFN = "X:/A.Output.txt";

        static bool numeric(char c)
        {
            switch (c)
            {
                case '.':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0': return true; 
                default: return false; 
            }
        }

        static string featureName()
        {
            string name = "";
            for (int i = pos + 1; i < tree.Length; i++)
            {
                if (tree[i] == ')') return name;
                if (tree[i] == '(') return name;
                if (!numeric(tree[i])) name += tree[i];
            }
            return name;
        }

        static double featureValue()
        {
            string name = "";
            for (int i = pos + 1; i < tree.Length; i++)
            {
                if (numeric(tree[i])) name += tree[i].ToString().Replace('.', ',');
                else return double.Parse(name);
            }
            return double.Parse(name);
        }

        static int findpos1()
        {
            for (int i = pos + 1; i < tree.Length; i++)
            {
                if (tree[i] == '(') return i;
            }
            return -1;
        }

        static int findpos2()
        {
            int open = 0;
            int closed = 0;
            for (int i = pos + 1; i < tree.Length; i++)
            {
                if (tree[i] == '(')
                {
                    if ((open > 0) && (open == closed)) return i;
                    open++;
                }
                if (tree[i] == ')')
                {
                    closed++;
                }
            }
            return -1;
        }

        static void Main(string[] args)
        {
            try
            {
                FileStream ifs = File.OpenRead(iFN);
                FileStream ofs = File.Create(oFN);

                StreamReader reader = new StreamReader(ifs);
                StreamWriter writer = new StreamWriter(ofs);

                nCases = int.Parse(reader.ReadLine());
                for (int Case = 1; Case <= nCases; Case++)
                {
                    writer.WriteLine("Case #{0}:", Case);
                    int L = int.Parse(reader.ReadLine());

                    tree = ""; 
                    for (int t = 0; t < L; t++) tree += reader.ReadLine();
                    tree = tree.Replace(" ", "");

                    int A = int.Parse(reader.ReadLine()); 
                    for (int animalId = 0; animalId < A; animalId++)
                    {
                        string[] parts = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                        List<string> features = new List<string>();
                        for (int feature = 2; feature < parts.Length; feature++)
                            features.Add(parts[feature]);

                        double p = 1;
                        pos = 0;
                        while (true)
                        {
                            string fname = featureName();
                            p *= featureValue();
                            
                            if (fname == "") break;

                            if (features.IndexOf(fname) >= 0) pos = findpos1();
                            else pos = findpos2();
                        }
                        writer.WriteLine("{0,-10:F7}", p);
                    }
                }
                Console.ReadLine();

                writer.Close();
                reader.Close();
                ofs.Close();
                ifs.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.ReadKey();
            }
        }
    }
}
