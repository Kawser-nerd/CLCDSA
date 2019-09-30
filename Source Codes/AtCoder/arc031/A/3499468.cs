using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var name = ReadLine();
        var isO = true;
        for(var i = 0; i < name.Length / 2; i++) if (name[i] != name[name.Length - i-1]) { isO = false;break; }
        WriteLine(isO ? "YES" : "NO");
    }
    
}