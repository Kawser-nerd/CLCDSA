using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ConsoleApplicationA
{
    class TestCase
    {
        public int id;
        public int rows;
        public int cols;

        public List<List<char>> cake = new List<List<char>>();

        public TestCase()
        {
        }

        public string solve()
        {
            var firstValidRow = cake.IndexOf(cake.First(r => r.Any(c => c != '?')));

            for(int i = 0; i < rows; i++)
            {
                int rowToCopy = firstValidRow > i-1 ? firstValidRow : i-1;
                if (cake[i].All(c => c == '?')) cake[i] = cake[rowToCopy].Select(c => c).ToList();

                
                for (int j = 0; j < cols; j++)
                {
                    var firstChar = cake[i].First(c => c != '?');

                    if (cake[i][j] == '?') cake[i][j] = j > 0 ? cake[i][j - 1] : firstChar;
                }
            }

            return "\n" + string.Join("\n", cake.Select(r => string.Join("", r)));
        }
    }

    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            string fileName = OpenFileDialog();

            using (StreamReader sr = new StreamReader(fileName))
            using (StreamWriter sw = new StreamWriter(Path.ChangeExtension(fileName, ".out"), false))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    var woot = sr.ReadLine().Split(' ');
                    tempTestCase.rows = int.Parse(woot[0]);
                    tempTestCase.cols = int.Parse(woot[1]);

                    for (int j = 0; j < tempTestCase.rows; j++)
                    {
                        var temp = sr.ReadLine();
                        tempTestCase.cake.Add(temp.ToList());
                    }

                    string soultion = tempTestCase.solve();

                    //if (soultion >= 0)
                    //{
                        Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, soultion));
                        sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, soultion));
                    //}
                    //else
                    //{
                    //    Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, "IMPOSSIBLE"));
                    //    sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, "IMPOSSIBLE"));
                    //}
                }
            }

            Console.ReadLine();
        }

        private static string OpenFileDialog()
        {
            string fileName;
            OpenFileDialog fd = new OpenFileDialog();
            fd.InitialDirectory = "Desktop";
            fd.Filter = "in files (*.in)|*.in|All files (*.*)|*.*";
            fd.ShowDialog();
            fileName = fd.FileName;
            return fileName;
        }

        static BigInteger GetGCD(BigInteger num1, BigInteger num2)
        {
            while (num1 != num2)
            {
                if (num1 > num2)
                {
                    num1 = num1 - num2;
                }
                else
                {
                    num2 = num2 - num1;
                }
            }

            return num1;
        }


        static BigInteger GetLCM(BigInteger num1, BigInteger num2)
        {
            return (num1 * num2) / GetGCD(num1, num2);
        }
    }
}
