using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Minimum_Scalar_Product
{
    StreamWriter writer = new StreamWriter("A-large.out");
    List<string> v1Str = new List<string>();
    List<string> v2Str = new List<string>();
    List<long> v1 = new List<long>();
    List<long> v2 = new List<long>();

    public void Parse()
    {
        using (StreamReader sr = File.OpenText("A-large.in"))
        {
            long numCases = Convert.ToInt32(sr.ReadLine());
            for (int i = 0; i < numCases; i++)
            {
                sr.ReadLine();

                v1Str = new List<string>(sr.ReadLine().Split(' '));
                v2Str = new List<string>(sr.ReadLine().Split(' '));
                v1.Clear();
                v2.Clear();

                foreach (string element in v1Str)
                {
                    v1.Add(Convert.ToInt32(element));
                }

                foreach (string element in v2Str)
                {
                    v2.Add(Convert.ToInt32(element));
                }

                long sum = GetMinProduct();
                writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, sum));
            }

        }
        writer.Close();
    }

    public long GetMinProduct()
    {
        v1.Sort();
        v2.Sort();

        long sum = 0;
        for (int i = 0; i < v1.Count; i++)
        {
            sum += (v1[i] * v2[v1.Count - i - 1]);
        }
        return sum;
    }
}
