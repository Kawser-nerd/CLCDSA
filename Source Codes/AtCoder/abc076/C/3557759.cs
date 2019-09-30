using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var substr = ReadLine();
        var q = substr.Length-1;
        var last = -1;
        for(var i = 0; i < str.Length - substr.Length+1; i++)
        {
            var s = str.Substring(i, substr.Length);
            var isCle = true;
            for(var j = 0; j < substr.Length; j++)
            {
                if (s[j] != '?' && s[j] != substr[j]) isCle = false;
            }
            if (isCle) last = i;
        }
        if(last!=-1)
        str = str.Substring(0, last) + substr + str.Substring(last+substr.Length);
        WriteLine(last!=-1?str.Replace('?', 'a'): "UNRESTORABLE");
    }
}