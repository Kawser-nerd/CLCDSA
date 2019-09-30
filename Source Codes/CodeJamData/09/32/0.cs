using System;
using System.Collections.Generic;
using System.Text;

public class B
{
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		B task = new B ();
		
		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve (int.Parse (Console.ReadLine ())));
	}

	public string Solve (int n)
	{
		double x = 0, y = 0, z = 0, dx = 0, dy = 0, dz = 0;

		for (int i = 0; i < n; ++i)
		{
			string[] ss = Console.ReadLine ().Split (' ');
			x += double.Parse (ss[0]) / n;
			y += double.Parse (ss[1]) / n;
			z += double.Parse (ss[2]) / n;
			dx += double.Parse (ss[3]) / n;
			dy += double.Parse (ss[4]) / n;
			dz += double.Parse (ss[5]) / n;
		}

		double a = x * dx + y * dy + z * dz;
		double b = dx * dx + dy * dy + dz * dz;

		if (b < 1E-8 || -a / b < 0)
			return string.Format ("{0} {1}", vzd (x, y, z), 0);

		double t = -a / b;

		return string.Format ("{0} {1}", vzd (x + t * dx, y + t * dy, z + t * dz), t);
	}

	double vzd (double x, double y, double z)
	{
		return Math.Sqrt (x * x + y * y + z * z);
	}
}
