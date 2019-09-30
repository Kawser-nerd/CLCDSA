using System;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var str1 = ReadLine();
        var str2 = ReadLine();
        var chara1 = new string[str1.Length];
        var chara2 = new string[str2.Length];
        for(var i = 0; i < str1.Length + str2.Length; i++)
        {
            if (i < str1.Length) chara1[i] = str1.Substring(i, 1);
            else chara2[i - str1.Length] = str2.Substring(i - str1.Length, 1);
        }
        str1 = "";
        str2 = "";
        Array.Sort(chara1);
        Array.Sort(chara2);
        for(var i = 0; i < chara1.Length + chara2.Length; i++)
        {
            if (i < chara1.Length) str1 += chara1[i]; 
            else str2 += chara2[chara2.Length - 1 - i + chara1.Length]; 
        }
        var s = new[] { str1, str2 };
        Array.Sort(s);
        var result = s[0] == str1 ? "Yes" : "No";
        if (str1 == str2) result = "No";
        WriteLine(result);
    }
}