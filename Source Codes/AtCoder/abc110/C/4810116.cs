using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Get_AC
{
    class Program
    {
        public static void Main(string[] args)
        {
            using (var sc = new SetConsole())
            {
                var s = Console.ReadLine();
                var t = Console.ReadLine();
                var dic = new Dictionary<char, char>();
                string result = "Yes";
                for (int i = 0; i < s.Length; i++)
                {
                    if (dic.ContainsKey(s[i]))
                    {
                        if (dic[s[i]] != t[i])
                        {
                            result = "No";
                            break; 
                        }
                    }
                    else
                    {
                        dic.Add(s[i], t[i]);
                    }
                }
                dic.Clear();
                for (int i = 0; i < s.Length; i++)
                {
                    if (dic.ContainsKey(t[i]))
                    {
                        if (dic[t[i]] != s[i])
                        {
                            result = "No";
                            break;
                        }
                    }
                    else
                    {
                        dic.Add(t[i], s[i]);
                    }
                }

                CWrite(result);
            }
        }

        static string[] GetArrayCharInput() => Console.ReadLine().Split();
        static int[] GetArrayIntInput() => Console.ReadLine().StringToIntArray();
        static int GetIntInput() => Console.ReadLine().ToInt();
        static void CWrite(string str) => Console.WriteLine(str);

    }

    class SetConsole : IDisposable
    {
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
        public SetConsole()
        {
            sw.AutoFlush = false;
            Console.SetOut(sw);
        }
        public void Dispose()
        {
            Console.Out.Flush();
            sw.AutoFlush = true;
            Console.SetOut(sw);
        }
    }

    static class ExtentionsLibrary
    {
        public static int[] StringToIntArray(this string str) =>
            str.Split().Select(int.Parse).ToArray();
        public static int ToInt(this string str) => int.Parse(str);
    }
}