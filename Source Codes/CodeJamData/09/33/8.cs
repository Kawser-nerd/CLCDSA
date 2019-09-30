using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google_Code_Jam
{
	
	#region ProblemA
	class ProblemA
	{
		public string a;
		public ProblemA(string str)
		{
			a = str;
		}
		public string Calc()
		{
			char[] A = a.ToCharArray();
			bool[] B = new bool[A.Length];
			bool[] U = new bool[40];
			int[] X = new int[A.Length];
			for (int j = 0; j < 40; j++)
				U[j] = false;
			for (int j = 0; j < X.Length; j++)
				X[j] = 0;
			for (int j = 0; j < B.Length; j++)
				B[j] = false;
			int i = 0;
			while (i < A.Length)
			{
				if (B[i] == true)
				{
					i++;
					continue;
				}
				if (i == 0)
				{
					U[1] = true;
					for (int j = i; j < A.Length; j++)
						if (A[j] == A[i])
						{
							X[j] = 1;
							B[j] = true;
						}
					continue;
				}
				int min = 0;
				while (U[min])
					min++;
				U[min] = true;
				for (int j = i; j < A.Length; j++)
					if (A[j] == A[i])
					{
						B[j] = true;
						X[j] = min;
					}
			}
			int bas = 0;
			for (int j = 0; j < X.Length; j++)
				if (bas < X[j]) bas = X[j];
			bas++;
			if (bas == 1)
				bas = 2;
			double ans = 0;
			for (int j = 0; j < A.Length; j++)
			{
				ans = ans * bas + X[j];
			}
			Int64 ans1 = 0;
			for (int j = 0; j < A.Length; j++)
			{
				ans1 = ans1 * bas + X[j];
			}
			if (ans.ToString("0.") != ans1.ToString()) 
			{
				ans = 1.0* ans;
			}
			return ans.ToString("0.");
		}
		public static void Solve(TextReader tr, TextWriter tw)
		{
			int L = int.Parse(tr.ReadLine());
			for (int i = 1; i <= L; i++)
			{
				ProblemA problem = new ProblemA(tr.ReadLine().Trim());
				Console.WriteLine("Case #{0}: {1}", i, problem.a);
				tw.WriteLine(String.Format("Case #{0}: ", i) + problem.Calc());
			}
		}
	}
	#endregion

	#region ProblemB
	class ProblemB
	{
		int x, y, z, vx, vy, vz;
		int K;
		public ProblemB(int x, int y, int z, int vx, int vy, int vz, int K)
		{
			this.x = x;
			this.y = y;
			this.z = z;
			this.vx = vx;
			this.vy = vy;
			this.vz = vz;
			this.K = K;
		}
		public string Calc()
		{
			double a = 1.0 * vx * vx + 1.0 * vy * vy + 1.0 * vz * vz;
			double b = 1.0 * x * vx + 1.0 * y * vy + 1.0 * z * vz;
			double c = 1.0 * x * x + 1.0 * y * y + 1.0 * z * z;

			if (Math.Abs(a) < 1e-5)
			{
				return (Math.Sqrt(c)/K).ToString("0.########") + " 0";
			}

			double t = - b / a;
			if (t < 0)
				t = 0;
			double r = Math.Sqrt(a * t * t + 2 * b * t + c)/K;
			return r.ToString("0.########") + " " + t.ToString("0.########");
		}
		public static void Solve(TextReader tr, TextWriter tw)
		{
			int L = int.Parse(tr.ReadLine());
			for (int i = 1; i <= L; i++)
			{

				int K = int.Parse(tr.ReadLine());
				int x = 0, y = 0, z = 0, vx = 0, vy = 0, vz = 0;
				for (int j = 0; j < K; j++)
				{
					string[] s = tr.ReadLine().Split(' ');
					x += int.Parse(s[0]);
					y += int.Parse(s[1]);
					z += int.Parse(s[2]);
					vx += int.Parse(s[3]);
					vy += int.Parse(s[4]);
					vz += int.Parse(s[5]);
				}
				if (i == 17)
				{
					L = L;
				}
				ProblemB problem = new ProblemB(x, y, z, vx, vy, vz, K);
				tw.WriteLine("Case #{0}: {1}", i, problem.Calc());
			}
		}
	}
	#endregion

	class ProblemC
	{
		int[] released;
		int P, Q;
		bool[] isReleased;
		int[,] A;
		bool[,] B;
		public ProblemC(int P, int Q, int[] released)
		{
			this.P = P;
			this.Q = Q;
			this.released = released;
		}

		private int Find(int i, int j)
		{
			if (B[i, j])
				return A[i, j];
			if (i >= j)
			{
				B[i, j] = true;
				A[i, j] = 0;
				return 0;
			}
			if (i == j - 1)
			{
				A[i, j] = 0;
				B[i, j] = true;
				return 0;
			}
			int min = 10000000;
			for (int k = i + 1; k < j; k++)
			{
				int x = released[j] - released[i] - 2;
				x += Find(i, k) + Find(k, j);
				if (x < min)
					min = x;
			}
			A[i, j] = min;
			B[i, j] = true;
			return min;
		}

		public int Calc()
		{
			A = new int[Q + 2, Q + 2];
			B = new bool[Q + 2, Q + 2];
			for (int i = 0; i < Q + 2; i++)
				for (int j = 0; j < Q + 2; j++)
					B[i, j] = false;
			return Find(0, Q + 1);
		}

		public static void Solve(TextReader tr, TextWriter tw)
		{
			int L = int.Parse(tr.ReadLine());
			for (int i = 1; i <= L; i++)
			{
				string[] s = tr.ReadLine().Split(' ');
				int P = int.Parse(s[0]);
				int Q = int.Parse(s[1]);
				int[] pr = new int[Q + 2];
				s = tr.ReadLine().Split(' ');
				for (int j = 0; j < Q; j++)
					pr[j + 1] = int.Parse(s[j]);
				pr[0] = 0;
				pr[Q + 1] = P + 1;
				ProblemC problem = new ProblemC(P, Q, pr);
				tw.WriteLine("Case #{0}: {1}", i, problem.Calc());
			}
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			TextReader tr = new StreamReader(@"C:\Google Code Jam\C-large.in");
			TextWriter tw = new StreamWriter(@"C:\Google Code Jam\C-large.txt");
			ProblemC.Solve(tr, tw);
			tr.Close(); tw.Close();
			Console.ReadKey();
		}
	}
}
