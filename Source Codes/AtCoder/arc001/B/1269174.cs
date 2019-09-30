using System;

class ARC001B
{
	static public void Main(string[] args)
	{
		int A, B;
		string[] vals = Console.ReadLine().Split(' ');
		A = int.Parse(vals[0]);
		B = int.Parse(vals[1]);

		int d = Math.Abs(B-A);
		int count = 0;
		if(d >= 10)
		{
			int c10 = d / 10;
			count += c10;
			d -= c10 * 10;
		}
		switch(d)
		{
			case 9:
				count += 2;
				break;
			case 8:
				count += 3;
				break;
			case 7:
				count += 3;
				break;
			case 6:
				count += 2;
				break;
			case 5:
				count += 1;
				break;
			case 4:
				count += 2;
				break;
			case 3:
			case 2:
			case 1:
			case 0:
				count += d;
				break;
		}
		Console.WriteLine(count);
	}
}