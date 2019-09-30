using System;
class Program
{
	static void Main()
	{
	string[] input = Console.ReadLine().Split(' ');//Split???????????????????
	int a = int.Parse(input[0]);
	int b = int.Parse(input[1]);
    int c = int.Parse(input[2]);
    int ok = 0;
      int aa = 0;
      for(int i = 0; i < 105; i++)
      {
        aa += a;
        if(aa % b == c)ok++;
      }
	//??
	Console.WriteLine((ok >= 1) ? "YES" : "NO");
	}
}