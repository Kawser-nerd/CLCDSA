using System.Collections.Generic;
using static System.Console;
class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var charas = new HashSet<string>();
        var isContain = false;
        for(var i = 0; i < str.Length; i++)
        {
            var chara = str.Substring(i, 1);
            if (charas.Contains(chara)) { isContain = true;break; }
            charas.Add(chara);
        }
        var result = isContain ? "no" : "yes";
        WriteLine(result);
    }
}