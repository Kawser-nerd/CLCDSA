using static System.Console;
class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        for(var i = 0; i <= int.MaxValue; i++)
        {
            str = str.Substring(0, str.Length - 2);
            var s = str.Substring(0, str.Length / 2);
            if (s + s == str) { WriteLine(str.Length);break; }
        }
    }
}