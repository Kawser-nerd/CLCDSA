using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _2010CJR0
{
    class R1P3
    {

        static Int64 calc(List<Int32> inp, Int32 target)
        {
            //is pure
            Int32 pos = (inp.Count);
            
            if (inp[inp.Count - 1] == target)
            {

                while (pos > 1)
                {
                    if (inp.Contains(pos))
                    {
                        pos = inp.FindIndex(delegate(Int32 item)
                        {
                            return item == pos;
                        }) + 1;
                    }
                    else
                    {
                        return (0);
                    }
                }


                //foreach (int elem in inp)
                //{
                //    Console.Write(elem.ToString() + " ");
                //}
                //Console.WriteLine();
                return 1;
            }
            else
            {
                Int64 res = 0;
                for (Int32 tt = inp[inp.Count - 1] + 1; tt <= target; tt++)
                {
                    List<Int32> copy = new List<Int32>(inp.ToArray());
                    copy.Add(tt);
                    res += calc(copy, target);
                    res = res % 100003;
                }
                return (res);
            }

        }

        static void Main(string[] args)
        {
            String fileData = File.ReadAllText("c:\\DataR1_1_T.txt");
            String[] temp = fileData.Split('\n');
            int T;
            File.Create("c:\\2010CJR1.txt").Close();
            T = Int32.Parse(temp[0].Split(' ')[0]);
            for (int i = 0; i < T; i++)
            {

                Int32 N = Int32.Parse(temp[i + 1].Split(' ')[0]);

                Int64 res = 0;
                for (Int16 tt = 2; tt <= N; tt++)
                {
                    List<Int32> copy = new List<Int32>();
                    copy.Add(tt);
                    res += calc(copy, N);
                    res = res % 100003;
                }

                File.AppendAllText("c:\\2010CJR1.txt", "Case #" + (i + 1).ToString() + ": " + res.ToString() + "\n");
                Console.WriteLine("Case #" + (i + 1).ToString() + ": " + res.ToString() + "\n");

            }

        }
    }
}