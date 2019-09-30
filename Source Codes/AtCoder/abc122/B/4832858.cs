using static System.Console;
using static System.Math;

class AtCoder 
{
    public static void Main()
    {
        var s = ReadLine();
        int ans = 0;
        int ct;
        for (int i = 0; i < s.Length; i++){
            ct = 0;    
            while (i+ct < s.Length && isACGT(s[i+ct])){ ct++; }
            ans = Max(ans, ct);
        }
        WriteLine(ans);
    }

    static bool isACGT(char c) {
        return (c == 'A' || c == 'C' || c == 'G' || c == 'T');
    }
}