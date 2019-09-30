using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TaskC
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var reader = new StreamReader("c.in");
            var writer = new StreamWriter("c.out");

            var countTest = Int32.Parse(reader.ReadLine());
            for (var iTest = 0; iTest < countTest; iTest++)
            {
                var line = reader.ReadLine().Split(' ');
                var N = Int32.Parse(line[0]);
                var L = Int32.Parse(line[1]);
                var H = Int32.Parse(line[2]);
                var a = reader.ReadLine().Split(' ').Select(i => Int32.Parse(i)).ToArray();

                var OkI = -1;
                for (var i = L; i <= H; i++)
                {
                    var flag = true;
                    foreach (var a1 in a)
                    {
                        if (!((a1%i == 0) || (i%a1 == 0)))
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        OkI = i;
                        break;
                    }
                }

                writer.Write("Case #{0}: ", iTest + 1);

                if (OkI != -1)
                {
                    writer.WriteLine(OkI);
                }
                else
                {
                    writer.WriteLine("NO");
                }
            }


            reader.Close();
            writer.Close();
        }
    }
}