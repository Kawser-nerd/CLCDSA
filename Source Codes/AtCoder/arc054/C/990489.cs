using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;

using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Program
{
	public Program() { }

	static void Main(string[] args)
	{
		new Program().prog();
	}
	Scanner cin;
	const int MOD = 1000000007;
	const int INF = int.MaxValue - 10;
	const long INFL = long.MaxValue - 10;
	const double EPS = 1e-7;
	const double PI = 3.1415926536;

	int N;

	void prog()
	{
		cin = new Scanner();
		int[,] dir8 = new int[8, 2] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
		int[,] dir4 = new int[4, 2] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };

		N = cin.nextInt();

		int[,] dat = new int[N, N];
		for (int i = 0; i < N; i++)
		{
			string str = cin.next();
			for (int j = 0; j < N; j++)
			{
				dat[i, j] = int.Parse(str[j].ToString());
			}
		}
		Mat mat = new Mat(dat, N, N);
		mat.ModInv(10 * N, MOD);
		//mat.show();
		int det = (int)Math.Round(Math.Abs(mat.determinant(2)));
		//Console.WriteLine(mat.determinant());
		if (det % 2 == 0)
		{
			Console.WriteLine("Even");
		}
		else
		{
			Console.WriteLine("Odd");
		}
	}

	class Mat
	{
		public int[,] mat;
		int row, col;
		int[] inv;

		// ??????????(mod??????)
		public void ModInv(int n, int mod)
		{
			inv = new int[n + 1];
			inv[0] = 0;
			inv[1] = 1;
			for (int i = 2; i <= n; i++)
			{
				inv[i] = mod - ((mod / i) * inv[mod % i] % mod);
			}
		}

		public double determinant(int mod)
		{
			if (row != col) return PI;
			int size = row;
			int buf;
			int[,] det = new int[size, size];
			int ans = 1;

			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					det[i, j] = mat[i, j];
				}
			}
			for (int i = 0; i < size; i++)
			{
				int pivot = i;
				for (int j = i + 1; j < size; j++)
				{
					if (Math.Abs(det[j, i]) > Math.Abs(det[pivot, i])) pivot = j;
				}
				if (Math.Abs(det[pivot, i]) < EPS) return 0;
				for (int j = i; j < size; j++)
				{
					int tmp = det[i, j];
					det[i, j] = det[pivot, j];
					det[pivot, j] = tmp;
				}
				for (int j = i + 1; j < size; j++)
				{
					buf = det[j, i] * inv[det[i, i]];
					for (int k = i; k < size; k++)
					{
						det[j, k] = (det[j, k] - det[i, k] * buf + 2) % 2;
					}
				}
			}
			for (int i = 0; i < size; i++)
			{
				ans *= det[i, i];
				ans %= 2;
			}
			return ans;
		}

		public Mat inverse()
		{
			if (row != col) return null;
			int size = row;
			int buf;
			Mat inv = new Mat(row, col);

			for (int i = 0; i < size; i++)
			{
				inv.mat[i, i] = 1;
			}
			for (int i = 0; i < size; i++)
			{
				buf = 1 / mat[i, i];
				for (int j = 0; j < size; j++)
				{
					mat[i, j] *= buf;
					inv.mat[i, j] *= buf;
				}
				for (int j = 0; j < size; j++)
				{
					if (i != j)
					{
						buf = mat[j, i];
						for (int k = 0; k < size; k++)
						{
							mat[j, k] -= mat[i, k] * buf;
							inv.mat[j, k] -= inv.mat[i, k] * buf;
						}
					}

				}
			}
			return inv;
		}

		public void show()
		{
			Console.WriteLine("mat==================");
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					Console.Write("{0} ", mat[i,j]);
				}
				Console.WriteLine();
			}
			Console.WriteLine("=====================");
		}

		public Mat(int r, int c)
		{
			mat = new int[r, c];
			row = r;
			col = c;
		}

		public Mat(int[,] dat, int r, int c)
		{
			row = r;
			col = c;
			mat = dat;
		}
	}
}

class Scanner
{
	string[] s;
	int i;

	char[] cs = new char[] { ' ' };

	public Scanner()
	{
		s = new string[0];
		i = 0;
	}

	public string next()
	{
		if (i < s.Length) return s[i++];
		string st = Console.ReadLine();
		while (st == "") st = Console.ReadLine();
		s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
		i = 0;
		return next();
	}

	public int nextInt()
	{
		return int.Parse(next());
	}

	public long nextLong()
	{
		return long.Parse(next());
	}

	public double nextDouble()
	{
		return double.Parse(next());
	}
}