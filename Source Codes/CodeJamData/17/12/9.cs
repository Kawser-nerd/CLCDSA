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

namespace ConsoleApplicationB
{
    class TestCase
    {
        public int id;
        public int numIngredients;
        public int numPackages;

        public List<double> recipe = new List<double>();
        public List<List<double>> ingredients = new List<List<double>>();
        public List<List<Tuple<long, long>>> servingWindows = new List<List<Tuple<long, long>>>();

        public TestCase()
        {
        }

        public int solve()
        {
            long maxServs = 0;
            for (int i = 0; i < recipe.Count; i++)
            {
                servingWindows.Add(ingredients[i].Select(ing =>
                {
                    var temp = ing / recipe[i];
                    long high = Convert.ToInt64(Math.Floor(temp / 0.9));
                    long low = Convert.ToInt64(Math.Ceiling(temp / 1.1));

                    if (high > maxServs) maxServs = high;

                    return Tuple.Create(low, high);
                }).ToList());

                servingWindows[i].Sort((a1, a2) => {
                    var check = a1.Item1.CompareTo(a2.Item1);
                    if(check == 0)
                    {
                        check = a1.Item2.CompareTo(a2.Item2);
                    }
                    return check;
                    });
            }

            int solution = 0;
            long x = 1;
            while (servingWindows.All(swl => swl.Any()))
            {
                long lowestValue = long.MaxValue;
                var success = true;
                for (int j = 0; j < numIngredients; j++)
                {
                    while (servingWindows[j].Any() && servingWindows[j][0].Item2 < x)
                    {
                        servingWindows[j].RemoveAt(0);
                    }

                    if (servingWindows[j].Any())
                    {
                        var firstIngredient = servingWindows[j].First();
                        var hasMatchingIngredient = firstIngredient.Item1 <= x;
                        if (firstIngredient.Item1 < lowestValue) lowestValue = firstIngredient.Item1;
                        if (!hasMatchingIngredient) success = false;
                    }
                    else
                    {
                        success = false;
                    }
                }

                if (success == true)
                {
                    servingWindows.ForEach(swl => swl.RemoveAt(0));
                    solution++;
                }
                else if (x < lowestValue)
                {
                    x = lowestValue;
                }
                else
                {
                    x++;
                }
            }
            return solution;
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
                    tempTestCase.numIngredients = int.Parse(woot[0]);
                    tempTestCase.numPackages = int.Parse(woot[0]);


                    woot = sr.ReadLine().Split(' ');
                    tempTestCase.recipe = woot.Select(n => double.Parse(n)).ToList();


                    for (int j = 0; j < tempTestCase.numIngredients; j++)
                    {
                        woot = sr.ReadLine().Split(' ');
                        tempTestCase.ingredients.Add( woot.Select(n => double.Parse(n)).ToList());
                    }

                    int soultion = tempTestCase.solve();

                    if (soultion >= 0)
                    {
                        Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, soultion));
                        sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, soultion));
                    }
                    else
                    {
                        Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, "IMPOSSIBLE"));
                        sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, "IMPOSSIBLE"));
                    }
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
