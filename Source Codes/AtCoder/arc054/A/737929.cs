using System;

class a{
    public static void Main(){
	string[] input = Console.ReadLine().Split(' ');
	int l = int.Parse(input[0]);
	int x = int.Parse(input[1]);
	int y = int.Parse(input[2]);
	int s = int.Parse(input[3]);
	int d = int.Parse(input[4]);

	double ans = double.MaxValue;

	int dis = d - s >0 ? d- s: l - Math.Abs(d-s); 
	int rev = l - dis;

	ans = Math.Min(ans,(double)dis/(x+y));

	if(y-x > 0)
	    ans = Math.Min(ans,(double)rev/(y-x));

	Console.WriteLine(ans);
    }
}