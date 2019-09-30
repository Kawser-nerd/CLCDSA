#if DEBUG
using Microsoft.VisualStudio.TestTools.UnitTesting;
#endif

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split('/');
            var x = long.Parse(str[0]);
            var y = long.Parse(str[1]);

            var ret = GetAns(x, y);

            if (ret.Count() == 0) Console.WriteLine("Impossible");
            else
            {
                foreach (var r in ret) Console.WriteLine(r.Item1 + " " + r.Item2);
            }
        }

        public static List<Tuple<long, long>> GetAns(BigInteger x, BigInteger y)
        {
            var ret = new List<Tuple<long, long>>();
            for (BigInteger n = 2 * x / y - 100; n <= 2 * x / y + 100; n++)
            {
                if ((x * n) % y != 0) continue;

                var m = (n * (n + 1)) / 2 - (x * n) / y;

                if (m < 1 || m > n) continue;
                ret.Add(new Tuple<long, long>((long)n, (long)m));
            }
            return ret;
        }
    }

#if DEBUG
    [TestClass]
    public class Test
    {
        [TestMethod]
        public void TestMethod()
        {
            var r = Program.GetAns(4, 3);
            Assert.AreEqual(1, r.Count());
            Assert.AreEqual(3, r.First().Item1);
            Assert.AreEqual(2, r.First().Item2);

            r = Program.GetAns(4, 6);
            Assert.AreEqual(0, r.Count());

            r = Program.GetAns(49995, 10);
            Assert.AreEqual(1, r.Count());
            Assert.AreEqual(10000, r.First().Item1);
            Assert.AreEqual(10000, r.First().Item2);

            r = Program.GetAns(1, 400);
            Assert.AreEqual(0, r.Count());
        }
    }
#endif
}