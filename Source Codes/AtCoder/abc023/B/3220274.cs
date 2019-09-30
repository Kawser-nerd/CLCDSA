using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var str = ReadLine();
        var isMatch = false;
        switch ((num/2) % 3)
        {
            case 0:
                if (str.Substring(str.Length - 1) == "b" && str.Replace("bca", "") == "b") isMatch = true;
                break;
            case 1:
                if (str.Replace("abc", "") == "") isMatch = true;
                break;
            case 2:
                if (str.Substring(str.Length - 2) == "ca" && str.Replace("cab", "") == "ca") isMatch = true;
                break;
        }
        var result = isMatch ? num / 2 : -1;
        WriteLine(result);
    }
}