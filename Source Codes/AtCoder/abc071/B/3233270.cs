using System.Collections.Generic;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var charas = new HashSet<string>();
        var alfa = "abcdefghijklmnopqrstuvwxyz";
        var result = "";
        for(var i = 0; i < str.Length; i++)
        {
            charas.Add(str.Substring(i, 1));
        }
        for(var i = 0; i < alfa.Length; i++)
        {
            if (!charas.Contains(alfa.Substring(i, 1))){ result = alfa.Substring(i, 1);break; }
        }
        if (result=="") WriteLine("None");
        else WriteLine(result);
    }
}