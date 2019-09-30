using System;
using System.Collections.Generic;
class Program
{
    static void Main(string[] args)
    {
            List<int> lstSmp = new List<int>();
            string[] sInp = Console.ReadLine().Trim().Split(' ');
            for (int j = 0; j < 3; j++) { lstSmp.Add(int.Parse(sInp[j])); }
            lstSmp.Sort();
            Console.WriteLine("{0}", lstSmp[1].ToString());
    }
}