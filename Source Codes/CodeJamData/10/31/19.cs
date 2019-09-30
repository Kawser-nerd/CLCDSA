namespace Rope
{
    using System;
    using System.Collections.Generic;

    public class Rope
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            int n;
            List<int> a = new List<int>();
            List<int> b = new List<int>();
            int r;
            int curA;
            int curB;

            for (int i = 0; i < t; i++)
            {
                n = int.Parse(Console.ReadLine());
                r = 0;
                a.Clear();
                b.Clear();

                for (int j = 0; j < n; j++)
                {
                    string[] testCase = Console.ReadLine().Split(' ');
                    curA = int.Parse(testCase[0]);
                    curB = int.Parse(testCase[1]);

                    for (int k = 0; k < a.Count; k++)
                    {
                        if ((curA < a[k] && curB > b[k]) || (curA > a[k] && curB < b[k]))
                            r++;
                    }

                    a.Add(curA);
                    b.Add(curB);
                }                

                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, r));
            }
        }
    }
}


