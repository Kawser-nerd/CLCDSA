using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderConsole
{
    class Program
    {        
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // ???????????
            int n = int.Parse(input);

            // ???n?string?????
            string[] member = new string[n];

            // ???????
            for(int i = 0; i < n; i++)
            {
                member[i] = Console.ReadLine();
            }

            // Dictionary???
            Dictionary<string, int> dic = new Dictionary<string, int>();
            foreach(string name in member)
            {
                if (dic.ContainsKey(name))
                {
                    dic[name]++;
                }
                else
                {
                    dic.Add(name, 1);
                }
            }

            // Vallue????????
            int valMax = 0;

            foreach(int v in dic.Values)
            {
                if(valMax < v)
                {
                    valMax = v;
                }
            }

            // Value??Key???
            var key = dic.First(x => x.Value == valMax).Key;

            // ???????
            Console.WriteLine(key);
        }
    }
}