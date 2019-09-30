using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _20180502_pra
{
    class Program
    {
        static void Main(string[] args)
        {

            string s = Console.ReadLine();
            var slist = new List<string>();

            for (int i = 0; i < s.Length; i++)
            {
                if(s[i].ToString()== "B")
                {
                    if(slist.Count()-1>=0)
                    slist.RemoveAt(slist.Count()-1);
                }
                else
                {
                    slist.Add(s[i].ToString());
                }
            }

            foreach (var item in slist)
            {
                Console.Write(item);
            }


        }
    }
}