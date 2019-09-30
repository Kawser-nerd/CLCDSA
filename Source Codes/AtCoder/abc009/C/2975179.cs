using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace AtTest.C_Challenge
{
    class ABC_009
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int k = int.Parse(input[1]);
            string s = Console.ReadLine();
            var charList = new List<char>();
            string result = "";
            for (int i = 0; i < n; i++)
            {
                charList.Add(s[i]);
            }

            charList.Sort();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < charList.Count; j++)
                {
                    if (s[i] == charList[j] || i == n - 1)
                    {
                        result += charList[j];
                        charList.RemoveAt(j);
                        break;
                    }
                    else//????????
                    {
                        char temp = charList[j];
                        charList.RemoveAt(j);
                        int kCnt = 0;
                        char[] sToChar = s.ToArray();
                        var remainChars = new List<char>();
                        remainChars.AddRange(s.Substring(i + 1).ToArray());
                        for (int charI = 0; charI < charList.Count; charI++)
                        {
                            remainChars.Remove(charList[charI]);
                        }
                        string tempS = "";
                        for (int ii = 0; ii < remainChars.Count; ii++)
                            tempS += remainChars[ii];
                        //Console.WriteLine(tempS + " " + k);
                        if (remainChars.Count <= k - 1)//????
                        {
                            result += temp;
                            k--;
                            break;
                        }
                        else
                        {
                            charList.Insert(j, temp);
                        }
                    }
                }
            }
            Console.WriteLine(result);
        }
    }
}