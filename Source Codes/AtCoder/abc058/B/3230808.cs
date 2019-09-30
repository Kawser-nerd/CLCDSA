using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var odd = ReadLine();
        var even = ReadLine();
        var isNotEven = odd.Length > even.Length ?true:false;
        for(var i = 0; i < odd.Length; i++)
        {
            Write(odd.Substring(i, 1));
            if (!(i == odd.Length - 1 && isNotEven)) Write(even.Substring(i, 1));
        }
        WriteLine();
    }
}