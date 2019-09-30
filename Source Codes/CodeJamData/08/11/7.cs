using System;
using System.Collections.Generic;
using System.IO;

using System.Text;

public class Test
{
    public static void Main(string[] args)
    {
        using (StreamReader sr = new StreamReader("C:\\Users\\int\\Desktop\\test.in"))
        {
            int n = int.Parse(sr.ReadLine());
            using (StreamWriter sw = new StreamWriter("C:\\Users\\int\\Desktop\\test.out"))
            {
                for (int c = 0; c < n; c++)
                {
                    int l = int.Parse(sr.ReadLine());
                    int[]x = new int[l];
                    int[] y = new int[l];
                    string[] strs = sr.ReadLine().Split(' ');
                    for(int i=0; i<l; i++)
                    {
                        x[i] = int.Parse(strs[i]);
                    }
                    strs = sr.ReadLine().Split(' ');
                    for(int i=0; i<l; i++)
                    {
                        y[i] = int.Parse(strs[i]);
                    }
                    Array.Sort(x);
                    Array.Sort(y);                    
                    long ret = 0;
                    for (int i = 0; i < l; i++)
                    {
                        ret += (long)x[i] * (long)y[l - 1 - i];
                    }
                    sw.WriteLine("Case #{0}: {1}", c + 1, ret);
                }
            }
        }
    }
}
