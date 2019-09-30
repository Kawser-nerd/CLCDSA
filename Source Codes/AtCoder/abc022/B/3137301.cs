using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main(string[] args)
    {
        string sInp = Console.ReadLine().Trim();
        int iN = int.Parse(sInp);
        List<int> lstSmp = new List<int>();
        for (int i = 0; i < iN; i++)
        {
            sInp = Console.ReadLine().Trim();
            lstSmp.Add(int.Parse(sInp));
        }
        int iDup = lstSmp.Count;
        iDup -= lstSmp.Distinct().ToList().Count;
        Console.WriteLine("{0}", iDup.ToString());
    }
}