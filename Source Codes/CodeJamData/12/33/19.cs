using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace ProjectC
{
    class Program
    {
        const string ASmall = "C-small-attempt0.in";
        const string ALarge = "C-large.in";

        static void Main(string[] args)
        {
            StreamReader readStream = new StreamReader(ASmall);
            StreamWriter writer = new StreamWriter("out.txt");

            string firstLine = readStream.ReadLine();

            int N = int.Parse(firstLine);
            for (int i = 1; i <= N; i++)
            {
                string s = readStream.ReadLine();
                int numOfBoxSeq = int.Parse(s.Split(' ')[0]);
                int numOfToySeq = int.Parse(s.Split(' ')[1]);
                string s1 = readStream.ReadLine();
                string s2 = readStream.ReadLine();
                string result = solve(numOfBoxSeq, numOfToySeq, s1, s2);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            readStream.Close();
            writer.Close();

            //string[] animals = { "Dog", "Cat", "Mouse" };
            //List<List<string>> result = new List<List<string>>();
            //int cnt = 1 << animals.Length;
            //for (int i = 0; i < cnt; i++)
            //{
            //    List<string> item = new List<string>();

            //    BitArray b = new BitArray(new byte[]{(byte)i});                             


            //    for (int j = 0; j < animals.Length; j++)
            //    {

            //        if (b[j])
            //            item.Add(animals[j]);
            //    }
            //    result.Add(item);
            //}
        }

        private static string solve(int numOfBoxSeq, int numOfToySeq, string s1, string s2)
        {
            string result = string.Empty;

            KeyValuePair<long, long>[] boxes = new KeyValuePair<long, long>[numOfBoxSeq];
            KeyValuePair<long, long>[] toyes = new KeyValuePair<long, long>[numOfToySeq];

            for (int i = 0; i < numOfBoxSeq; i++)
            {
                string[] s1s = s1.Split(' ');
                boxes[i] = new KeyValuePair<long, long>(long.Parse(s1s[2 * i + 1]), long.Parse(s1s[2 * i]));
            }
            for (int i = 0; i < numOfToySeq; i++)
            {
                string[] s2s = s2.Split(' ');
                toyes[i] = new KeyValuePair<long, long>(long.Parse(s2s[2 * i + 1]), long.Parse(s2s[2 * i]));
            }

            long resultInt = getMax(boxes, toyes);


            return resultInt.ToString();
        }

        private static long getMax(KeyValuePair<long, long>[] boxes, KeyValuePair<long, long>[] toyes)
        {
            long result = 0;
            if (Math.Min(boxes.Length, toyes.Length) > 0)
            {
                if (boxes[0].Key == toyes[0].Key)
                {
                    
                    if (boxes[0].Value < toyes[0].Value)
                    {
                        result += boxes[0].Value;
                        List<KeyValuePair<long, long>> tmp = boxes.ToList();
                        tmp.RemoveAt(0);
                        KeyValuePair<long, long>[] newBoxes = tmp.ToArray();

                        tmp = toyes.ToList();
                        tmp.RemoveAt(0);
                        tmp.Insert(0, new KeyValuePair<long, long>(toyes[0].Key, toyes[0].Value - boxes[0].Value));
                        KeyValuePair<long, long>[] newToys = tmp.ToArray();
                        result += getMax(newBoxes, newToys);
                    }
                    else
                    {
                        result += toyes[0].Value;
                        List<KeyValuePair<long, long>> tmp = toyes.ToList();
                        tmp.RemoveAt(0);
                        KeyValuePair<long, long>[] newToys = tmp.ToArray();

                        tmp = boxes.ToList();
                        tmp.RemoveAt(0);
                        if (boxes[0].Value != toyes[0].Value)
                            tmp.Insert(0, new KeyValuePair<long, long>(boxes[0].Key, boxes[0].Value - toyes[0].Value));
                        KeyValuePair<long, long>[] newBoxes = tmp.ToArray();
                        result += getMax(newBoxes, newToys);
                    }

                     
                }
                else
                {
                    List<KeyValuePair<long, long>> tmpBox = boxes.ToList();
                    tmpBox.RemoveAt(0);
                    KeyValuePair<long, long>[] newBoxes = tmpBox.ToArray();

                    tmpBox = toyes.ToList();
                    tmpBox.RemoveAt(0);
                    KeyValuePair<long, long>[] newToys = tmpBox.ToArray();

                    result += Math.Max(getMax(boxes, newToys), getMax(newBoxes, toyes));

                }
            }
            return result;
        }
    }
}
