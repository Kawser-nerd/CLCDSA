using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Round1C_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFn = "input.txt";
            var historyPostfix = DateTime.Now.ToString("HHmmss");

            File.Copy(inputFn, "input_" + historyPostfix + ".txt");
            Action<string> wl = line =>
            {
                Console.WriteLine(line);
                File.AppendAllLines("output_" + historyPostfix + ".txt", new[] { line });
            };

            //var stat = new List<Tuple<int, int, >>

            var inLines = File.ReadAllLines(inputFn);
            var testCaseCount = int.Parse(inLines[0]);
            var iLine = 1;
            for (int iCase = 1; iCase <= testCaseCount; iCase++)
            {
                var tribeCount = int.Parse(inLines[iLine + 0].Split(' ')[0]);

                var tribes = Enumerable.Range(1, tribeCount).Select(x => new Tribe(inLines[iLine + x].Split(' ').Select(int.Parse).ToArray())).ToArray();
                iLine += tribeCount + 1;

                var attacks = new List<Attack>();
                foreach (var tribe in tribes)
                {
                    for (var iAttack = 0; iAttack < tribe.AttackCount; iAttack++)
                        attacks.Add(new Attack()
                        {
                            AttackId = iAttack,
                            Day = tribe.FirstDay + tribe.dDay*iAttack,
                            Strength = tribe.Strength0 + tribe.dStrength*iAttack,
                            Xmin = tribe.Xmin + tribe.dX*iAttack,
                            Xmax = tribe.Xmax + tribe.dX*iAttack
                        });
                }


                var wall = new Dictionary<double, int>();

                Func<double, int> get = x =>
                {
                    int res;
                    if (!wall.TryGetValue(x, out res))
                        wall[x] = res = 0;
                    return res;
                };

                var result = 0;

                var attackDict = attacks.OrderBy(x => x.Day).GroupBy(x => x.Day).ToDictionary(x => x.Key, x => x.ToArray());
                foreach (var attackDayKvp in attackDict)
                {
                    int successCount = 0;
                    foreach (var attack in attackDayKvp.Value)
                    {
                        for (double i = attack.Xmin; i <= attack.Xmax; i += 0.5)
                            if (get(i) < attack.Strength)
                            {
                                successCount++;
                                break;
                            }
                    }
                    result += successCount;

                    foreach (var attack in attackDayKvp.Value)
                        for (double i = attack.Xmin; i <= attack.Xmax; i += 0.5)
                            if (get(i) < attack.Strength)
                                wall[i] = attack.Strength;
                }

                wl(String.Format("Case #{0}: {1}", iCase, result));
            }
        }
    }

    public class Attack
    {
        public Tribe Tribe;
        public int AttackId;
        public int Day;
        public int Xmin;
        public int Xmax;
        public int Strength;
    }

    public class Tribe
    {
        public int FirstDay;
        public int AttackCount;
        public int Xmin;
        public int Xmax;
        public int Strength0;
        public int dDay;
        public int dX;
        public int dStrength;

        public Tribe(int[] data)
        {
            FirstDay = data[0];
            AttackCount = data[1];
            Xmin = data[2];
            Xmax = data[3];
            Strength0 = data[4];
            dDay = data[5];
            dX = data[6];
            dStrength = data[7];
        }
    }

    public static class Ext
    {
        public static BigInteger Sqrt(this BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root /= 2;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }

        private static Boolean isSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);

            return (n >= lowerBound && n < upperBound);
        }
    }
}
