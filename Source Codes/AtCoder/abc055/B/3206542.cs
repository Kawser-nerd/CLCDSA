using System;
class Program
{
	static void Main()
	{
	long n = long.Parse(Console.ReadLine());//int.Parse???????????
    long pow = 1;
    for(int i = 1; i <= n; i ++)
    {
     pow *= i; 
     while(pow > 1000000007)pow -= 1000000007;
    }
	
	//??
	Console.WriteLine(pow % 1000000007);//WriteLine?Write?????????????
	}
}