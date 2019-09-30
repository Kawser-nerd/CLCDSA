using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Library;
using Library.DataStructures;
using Library.Extensions;

namespace Competition
{
	class Class2
	{
		public void Arg()
		{
			var file = System.IO.File.ReadAllLines(@"C:\Users\root\Documents\Downloads\B-large.in");
//            var file2 = @"3
//3
//3 0 -4 0 0 3
//-3 -2 -1 3 0 0
//-3 -1 2 0 3 0
//3
//-5 0 0 1 0 0
//-7 0 0 1 0 0
//-6 3 0 1 0 0
//4
//1 2 3 1 2 3
//3 2 1 3 2 1
//1 0 0 0 0 -1
//0 10 0 0 -10 -1";
//            var file = file2.Replace("\r", "").Split('\n');

			int line = 0;
			int cases = int.Parse(file[line++]);

			var sb = new System.Text.StringBuilder();
			for (int c = 1; c <= cases; c++)
			{
				int N = int.Parse(file[line++]);

				F[] flys = new F[N];
				for (int i = 0; i < N; i++) flys[i] = new F(file[line++]);

				//find inital location
				double xi = 0;
				double yi = 0;
				double zi = 0;

				double xiv = 0;
				double yiv = 0;
				double ziv = 0;

				foreach (F f in flys)
				{
					xi += f.x;
					yi += f.y;
					zi += f.z;

					xiv += f.vx;
					yiv += f.vy;
					ziv += f.vz;
				}

				double dN = N;
				xi /= dN;
				yi /= dN;
				zi /= dN;

				xiv /= dN;
				yiv /= dN;
				ziv /= dN;

				//we have a set of three solve it
				double[] move = new double[3];
				move[0] = xiv;
				move[1] = yiv;
				move[2] = ziv;

				//xi + move[0] * t
				//yi + move[1] * t
				//zi + move[2] * t

				//double timeX = move[0] * move[0] + move[1] * move[1] + move[2] * move[2];
				//double timeY = ((xi + move[0]) * move[0]) +
				//    ((yi + move[1]) * move[1]) +
				//    ((zi + move[2]) * move[2]);
				double timeB = move[0] * move[0] + move[1] * move[1] + move[2] * move[2];

				double timeT = (move[0] * xi) +
					(move[1] * yi) +
					(move[2] * zi);

				double time = -(timeT / timeB);
				if (timeB == 0)
				{
					time = 0;
				}

				if (time < 0) time = 0;

				double res = Distance(xi + time * move[0],
					yi + time * move[1],
					zi + time * move[2]);

				sb.AppendFormat("Case #{0}: {1:0.00000000} {2:0.00000000}", c, res, time);
				sb.AppendLine();
			}

			System.IO.File.WriteAllText(@"C:\Pub\b.txt", sb.ToString());
		}

		private double Distance(double x, double y, double z)
		{
			return Math.Sqrt(x * x + y * y + z * z);
		}

		private class F
		{
			public F(string line)
			{
				var sp = line.Split(' ');
				x = int.Parse(sp[0]);
				y = int.Parse(sp[1]);
				z = int.Parse(sp[2]);

				vx = int.Parse(sp[3]);
				vy = int.Parse(sp[4]);
				vz = int.Parse(sp[5]);
			}

			public int x;
			public int y;
			public int z;

			public int vx;
			public int vy;
			public int vz;
		}


	}
}