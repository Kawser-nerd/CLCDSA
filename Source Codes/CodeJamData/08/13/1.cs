using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream inStream = File.OpenRead(args[0]);
            FileStream outStream = File.Create("numbers.out");

            StreamReader reader = new StreamReader(inStream);
            StreamWriter writer = new StreamWriter(outStream);

            try
            {
                int nCases = Int32.Parse(reader.ReadLine());

                for (int c = 1; c <= nCases; c++)
                {
                    int n = Int32.Parse(reader.ReadLine());
                    decimal exp = 5.236067977499789696409173668731276235440618359611525724270897245410520925638m;
                    decimal result = 1;
                    for (int i = 0; i < n; i++) 
                    {
                        result *= exp;
                    }
                    result = Math.Floor(result);
                    string str = result.ToString("F0");
                    while(str.Length < 3) 
                    {
                        str = "0" + str;
                    }
                    writer.WriteLine("Case #{0}: {1}", c, str.Substring(str.Length-3));
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
