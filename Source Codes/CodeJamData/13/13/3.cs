using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace GoodLuck
{
    class Program
    {
        static void Main(string[] args)
        {
            //StreamReader sr = new StreamReader("D:\\a.txt");
            //StreamWriter sw = new StreamWriter("D:\\b.txt");

            StreamReader sr = new StreamReader("D:\\C-small-1-attempt1.in");
            StreamWriter sw = new StreamWriter("D:\\C-small-1-attempt1.out");

            //StreamReader sr = new StreamReader("D:\\B-large.in");
            //StreamWriter sw = new StreamWriter("D:\\B-large.out");

            int numTestCases = Convert.ToInt32(sr.ReadLine());


            for (int i = 0; i < numTestCases; i++)
            {
                Console.WriteLine(i);
                sw.Write("Case #{0}: ", i + 1);
                sw.WriteLine();

                string[] str = sr.ReadLine().Split(' ');

                int numSets = Convert.ToInt32(str[0]);
                int numIntegers = Convert.ToInt32(str[1]);
                int maxInt = Convert.ToInt32(str[2]);
                int numProducts = Convert.ToInt32(str[3]);

                
                

                for (int j = 0; j < numSets; j++)
                {
                    str = sr.ReadLine().Split(' ');
                    
                    int[] products = new int[numProducts];

                    for (int k= 0; k < numProducts; k++)
                    {
                        products[k] = Convert.ToInt32(str[k]);
                    }
                    
                    int[] componentsTotal = new int[10];
                    int[] componentsMax = new int[10];
                    int[] outputComponents = new int[10];

                    for (int k = 0; k < componentsTotal.Length; k++)
                    {
                        componentsTotal[k] = 0;
                        componentsMax[k] = 0;
                        outputComponents[k] = 0;
                    }


                    int[] components = { 2, 3, 4, 5 };

                    for (int k = 0; k < numProducts; k++)
                    {

                        foreach (int factor in new int[] { 2, 3, 4, 5 })
                        {
                            if (factor > maxInt) continue;

                            int product = products[k];

                            int numOcur = 0;
                            while (product % factor == 0)
                            {
                                product /= factor;
                                numOcur++;
                            }
                            componentsTotal[factor] += numOcur;
                            if (numOcur > componentsMax[factor]) componentsMax[factor] = numOcur;

                        }

                    }

                    
                    List<int> output = new List<int>();

                    if (maxInt >= 3)
                    {
                        for (int k = 0; k < componentsMax[3] || k < componentsTotal[3] * 2 / numProducts; k++)
                        {
                            output.Add(3);
                        }
                    }

                    if (maxInt >= 5)
                    {
                        for (int k = 0; k < componentsMax[5] || k < componentsTotal[5] * 2 / numProducts; k++)
                        {
                            output.Add(5);
                        }
                    }

                    if (maxInt >= 4)
                    {
                        int numTwos = componentsTotal[2] * 2 / (3 * numProducts);
                        int numFours;
                        if (numIntegers - output.Count < componentsMax[2])
                        {
                            int numFoursMin = componentsMax[2] - (numIntegers - output.Count);
                            if (numFoursMin < 0) numFoursMin = 0;
                            for (int k = 0; k < numFoursMin; k++)
                            {
                                output.Add(4);
                            }

                        }
                    }
                    else
                    {
                        for (int k = 0; k < componentsMax[2] || k < componentsTotal[2] * 2 / numProducts; k++)
                        {
                            output.Add(2);
                        }
                    }

                    while (output.Count < numIntegers)
                    {
                        output.Add(2);
                    }

                    for (int k = 0; k < numIntegers; k++)
                    {
                        sw.Write(output[k]);
                    }
                    sw.WriteLine();

                }

                
            }
            sw.Close();
        }
    }
}
