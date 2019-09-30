using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("input.txt");
            StreamWriter writer = new StreamWriter("output.txt");
            int n = int.Parse(reader.ReadLine());
            for (int i = 1; i <= n; i++)
            {

                int c = int.Parse(reader.ReadLine());
                string[] parts = reader.ReadLine().Split(' ');
                int[] cs = new int[c];
                int[] cycle = new int[c];
                int temp;
                double average = 0;
                for (int j = 0; j < c; j++)
                {
                    temp = int.Parse(parts[j]);
                    if (temp != j + 1)
                        average++;
                    //cs[j] = temp;
                }


                /*int num = 1;
                int count = 0;
                for (int j = 0; j < c; j++)
                {
                    count = 0;
                    int index = cs[j] - 1;
                    while (cycle[index] == 0)
                    {
                        count++;
                        cycle[index] = num;
                        index = cs[index] - 1;
                    }
                    num++;

                    if(count != 1)
                        average += count;
                }*/



                writer.WriteLine("Case #{0}: {1}.000000", i, average);
            }
            reader.Close();
            writer.Close();
        }
    }
}
