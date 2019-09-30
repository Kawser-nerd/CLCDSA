using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var charaCounter = new Dictionary<string, int>();
        for(var i = 0; i < str.Length; i++)
        {
            if (charaCounter.ContainsKey(str.Substring(i, 1))) charaCounter[str.Substring(i, 1)]++;
            else charaCounter[str.Substring(i, 1)] = 1;
        }
        var result = charaCounter.Count ==charaCounter.Count(c=>c.Value%2==0) ? "Yes" : "No";
        WriteLine(result);
    }
}