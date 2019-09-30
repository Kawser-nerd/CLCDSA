using static System.Console;
using static System.Convert;

class Program
{
    static void Main(string[] args)
    {
        var str = ReadLine();
        var result = "";
        for(var i = 0; i < str.Length; i++)
        {
            switch (str.Substring(i, 1))
            {
                case "0":
                    result += "0";
                    break;
                case "1":
                    result += "1";
                    break;
                case "B":
                    if(result.Length!=0)
                    result=result.Substring(0,result.Length-1);
                    break;
            }
        }

        WriteLine(result);
    }
}