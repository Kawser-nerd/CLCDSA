using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var gri = new string[num];
        for (var i = 0; i < num; i++)
            gri[i] = ReadLine();
        var result = 0;
        for(var i = 0; i < num; i++)
        {
            for(var j = 0; j < 9; j++)
            {
                if (gri[i][j] == 'x') result++;
                if (gri[i][j] == 'o' && (i == 0 || (i != 0 && gri[i - 1][j] != 'o')))
                    result++;
            }
        }
        WriteLine(result);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}