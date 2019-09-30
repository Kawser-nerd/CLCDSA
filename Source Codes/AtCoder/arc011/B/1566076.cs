using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            List<CharacterInfo> charinfo = new List<CharacterInfo>()
            {
                new CharacterInfo(1, 'b', 'c'),
                new CharacterInfo(2, 'd', 'w'),
                new CharacterInfo(3, 't', 'j'),
                new CharacterInfo(4, 'f', 'q'),
                new CharacterInfo(5, 'l', 'v'),
                new CharacterInfo(6, 's', 'x'),
                new CharacterInfo(7, 'p', 'm'),
                new CharacterInfo(8, 'h', 'k'),
                new CharacterInfo(9, 'n', 'g'),
                new CharacterInfo(0, 'z', 'r')
            };

            int N = int.Parse(ReadLine());
            string[] words = ReadLine().ToLower().Split(' ');
            List<string> nums = new List<string>();
            for (int i = 0; i < words.Length; i++)
            {
                StringBuilder sb = new StringBuilder();
                foreach(char c in words[i])
                {
                    CharacterInfo info = charinfo.Where(_ => _.Characters.Contains(c)).FirstOrDefault();
                    if (info != null)
                        sb.Append(info.Number);
                }
                if(sb.Length > 0)
                    nums.Add(sb.ToString());
            }
            WriteLine(String.Join(" ", nums));
            ReadLine();
        }
    }
    class CharacterInfo
    {
        public int Number { get; set; }
        public List<char> Characters { get; set; }
        public CharacterInfo(int n, params char[] chrs)
        {
            Number = n;
            Characters = new List<char>(chrs);
        }
    }
}