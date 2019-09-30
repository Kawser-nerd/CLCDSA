using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ.GCJ2012.Round1C
{
    public class C
    {
        public static long Solve(string msk, List<long> boxes, List<long> toys)
        {
            if (msk.Length == 0)
                return 0;

            long maxVal = 0;
            int j = 1;
            for (int i = 0; i < boxes.Count; )
            {
                if (msk[i / 2] == '1')
                {
                    if (j < toys.Count && toys[j] == boxes[i + 1])
                    {
                        if (boxes[i] == toys[j - 1])
                        {
                            maxVal += boxes[i];
                            boxes[i] = 0;
                            toys[j - 1] = 0;
                            i += 2;
                            j += 2;
                        }
                        else if (boxes[i] < toys[j - 1])
                        {
                            maxVal += boxes[i];
                            toys[j - 1] -= boxes[i];
                            boxes[i] = 0;
                            i += 2;
                        }
                        else
                        {
                            maxVal += toys[j - 1];
                            boxes[i] -= toys[j - 1];
                            toys[j - 1] = 0;
                            j += 2;
                        }
                    }
                    else if (j < toys.Count)
                    {
                        var boxes1 = new List<long>();
                        boxes1.AddRange(boxes.GetRange(i, boxes.Count - i));
                        var toys1 = new List<long>();
                        toys1.AddRange(toys.GetRange(j + 1, toys.Count - j - 1));
                        string msk1 = msk.Substring(i / 2);


                        var boxes2 = new List<long>();
                        boxes2.AddRange(boxes.GetRange(i + 2, boxes.Count - i - 2));
                        var toys2 = new List<long>();
                        toys2.AddRange(toys.GetRange(j - 1, toys.Count - j + 1));
                        string msk2 = msk.Substring(i / 2 + 1);

                        long maxVal1 = Solve(msk1, boxes1, toys1);
                        long maxVal2 = Solve(msk2, boxes2, toys2);

                        maxVal += Math.Max(maxVal1, maxVal2);
                        break;
                    }
                    else
                        break;
                }
                else
                    i += 2;
            }
            return maxVal;
        }


        public static void Main()
        {
            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\C-small-attempt2.in");
            var outputStream = new StreamWriter(@"C:\Users\asaraswat\Downloads\C-small-attempt2.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = GetInt();
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                var nm = GetListOfInt();
                int n = nm[0], mm = nm[1];

                var boxes = GetListOfLong();
                var toys = GetListOfLong();

                var origBoxes = new List<long>(); var origToys = new List<long>();
                origBoxes.AddRange(boxes);
                origToys.AddRange(toys);



                long globalMax = 0;
                for (int m = 1; m < 8; ++m)
                {
                    string msk = Convert.ToString(m, 2);

                    if (msk.Length > n)
                        continue;

                    while (msk.Length < n)
                        msk = "0" + msk;

                    boxes.Clear();
                    boxes.AddRange(origBoxes);
                    toys.Clear();
                    toys.AddRange(origToys);

                    long maxVal = Solve(msk, boxes, toys);

                    globalMax = Math.Max(globalMax, maxVal);

                }
                Console.WriteLine("Case #{0}: {1}", cs, globalMax);
            }

            inputStream.Close();
            outputStream.Close();

        }

        private static int GetInt()
        {
            string p = Console.ReadLine();
            return Convert.ToInt32(p);
        }

        private static List<int> GetListOfInt(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => int.Parse(t)).ToList();
        }

        private static List<long> GetListOfLong(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => long.Parse(t)).ToList();
        }
    }
}
