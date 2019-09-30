using System;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace task1
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader reader = null;
            TextWriter writer = null;
            try
            {
                reader = new StreamReader(args[0], Encoding.ASCII);
                writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
                var cases = int.Parse(reader.ReadLine());
                Console.WriteLine("Cases {0}", cases);
                for (var i = 1; i <= cases; ++i)
                {
                    var rowNumber1 = int.Parse(reader.ReadLine()) - 1;
                    string row1 = null;
                    for (var r = 0; r < 4; ++r)
                    {
                        var s = reader.ReadLine();
                        if (r == rowNumber1)
                        {
                            row1 = s;
                        }
                    }
                    var rowNumber2 = int.Parse(reader.ReadLine()) - 1;
                    string row2 = null;
                    for (var r = 0; r < 4; ++r)
                    {
                        var s = reader.ReadLine();
                        if (r == rowNumber2)
                        {
                            row2 = s;
                        }
                    }
                    var data1 = row1.Split(new[] { ' ' });
                    var data2 = row2.Split(new[] { ' ' });
                    var result = data1.Intersect(data2).ToArray();
                    string output;
                    switch (result.Length)
                    {
                        case 1:
                            output = result[0];
                            break;
                        case 0:
                            output = "Volunteer cheated!";
                            break;
                        default:
                            output = "Bad magician!";
                            break;
                    }
                    var final = String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, output);
                    writer.WriteLine(final);
                }
            }
            finally
            {
                if (writer != null)
                    writer.Close();
                if (reader != null)
                    reader.Close();
            }
        }
    }
}
