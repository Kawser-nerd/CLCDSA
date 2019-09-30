using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MinimumScalarProduct
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream inStream = File.OpenRead(args[0]);
            FileStream outStream = File.Create("minimumscalarproduct.out");

            StreamReader reader = new StreamReader(inStream);
            StreamWriter writer = new StreamWriter(outStream);

            try
            {
                int nCases = Int32.Parse(reader.ReadLine());

                for (int c = 1; c <= nCases; c++)
                {
                    int n = Int32.Parse(reader.ReadLine());
                    List<int> v1, v2;
                    v1 = new List<int>(n);
                    v2 = new List<int>(n);

                    string[] parts = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    for (int i = 0; i < n; i++)
                    {
                        v1.Add(Int32.Parse(parts[i]));
                    }
                    parts = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    for (int i = 0; i < n; i++)
                    {
                        v2.Add(Int32.Parse(parts[i]));
                    }

                    v1.Sort();
                    v2.Sort();

                    long result = 0;
                    for (int i = 0; i < n; i++) 
                    {
                        result += ((long)v1[i]) * ((long)v2[n - i - 1]);
                    }

                    writer.WriteLine("Case #{0}: {1}", c,result);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
            }
        }
    }
}
