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
                    int ret = 0;
                    int s = int.Parse(sr.ReadLine());
                    sw.WriteLine("Case #{0}: {1}", c + 1, ret);
                }
            }
        }
    }
}
