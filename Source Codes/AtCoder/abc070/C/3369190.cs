using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        long lcm = 1;
        for(var i = 0; i < num; i++)
        {
            lcm=Calculation.LCM(lcm, ToInt64(ReadLine()));
        }
        WriteLine(lcm);
    }
}
public class Calculation
{
  public static long LCM(long num1, long num2)
    {
        return num1 / GCD(num1, num2) * num2;
    }
  public static long GCD(long num1, long num2)
    {
        return num1 < num2 ? GCD(num2, num1) :
            num2 > 0 ? GCD(num2, num1 % num2) : num1;
    }
}