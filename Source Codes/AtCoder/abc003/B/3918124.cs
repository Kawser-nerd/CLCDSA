using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{
    const string wildChars = "atcoder";
    static bool Equal(string strA, string strB)
    {
        if(strA.Length != strB.Length)
            return false;
        foreach(int i in Enumerable.Range(0, strA.Length))
        {
            //Console.WriteLine($"{strA[i]} {strB[i]}");
            if(strA[i] != strB[i])
            {
                if(!(strA[i] == '@' && wildChars.Contains(strB[i])) &&
                    !(strB[i] == '@' && wildChars.Contains(strA[i])))
                return false;
            }
        }
        return true;
    }
    public Program()
    {
        string strA = Console.ReadLine();
        string strB = Console.ReadLine();
        Console.WriteLine(Equal(strA, strB) ? "You can win" : "You will lose");
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}