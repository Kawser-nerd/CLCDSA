using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ
{
    public class PerfectHarmony
    {
        public void Solve()
        {
            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\B.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\B.out");

            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\C-small-attempt0.in");
            var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\C-small-attempt0.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt1.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt1.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-small-attempt1.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-small-attempt1.out");

            //var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-large.in");
            //var outputStream = new StreamWriter(@"D:\Projects\GCJ\GCJ\A-large.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = int.Parse(Console.ReadLine());
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                var nlh = Console.ReadLine().Split(' ');
                int n = int.Parse(nlh[0]);
                int l = int.Parse(nlh[1]);
                int h = int.Parse(nlh[2]);

                var others = Console.ReadLine().Split(' ');
                List<int> tunes = new List<int>();
                for (int i = 0; i < others.Length; ++i)
                    tunes.Add(int.Parse(others[i]));

                int res = -1;

                for (int i = l; i <= h; ++i)
                {
                    bool isCurrentGood = true;

                    for (int j = 0; isCurrentGood && j < tunes.Count; ++j)
                    {
                        if (i % tunes[j] != 0 && tunes[j] % i != 0)
                            isCurrentGood = false;
                    }

                    if (isCurrentGood)
                    {
                        res = i;
                        break;
                    }
                }

                Console.WriteLine("Case #{0}: {1}", cs, res == -1 ? "NO" : res.ToString());


            }

            inputStream.Close();
            outputStream.Close();
        }
    }
}
