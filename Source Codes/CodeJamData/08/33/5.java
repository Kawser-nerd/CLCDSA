import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;

public class Olymp
{
	static String INPUT_NAME = "input.txt";
	static String OUTPUT_NAME = "output.txt";
	static double eps = 1e-10;
	
	int n;
	long z;
	String st;
	long[] a;
	long[] mas;
	long[] res;
	long[] tree;
	int[] left;
	int[] right;
	int con = (1 << 19);
	long[] vals;
	
	
	void prln(String st)
	{
		System.out.println(st);
	}
	
	void input() throws IOException
	{
		Scanner sc = new Scanner(new File(INPUT_NAME));
		PrintWriter pw = new PrintWriter(OUTPUT_NAME);
		int kolC = sc.nextInt();
		for (int j = 0; j < kolC; j++)
		{
			System.out.println();
			System.out.println("New case " + (j));
			n = sc.nextInt();
			long m = sc.nextInt();
			long x = sc.nextInt();
			long y = sc.nextInt();
			z = sc.nextInt();
			a = new long[(int)m];
			for (int i = 0; i < m; i++)
				a[i] = sc.nextLong();
			mas = new long[n];
			long mx = 0;
			vals = new long[n + 1];
			for (long i = 0; i < n; i++)
			{
				mas[(int)i] = a[(int)(i % m)];
				vals[(int)i + 1] = mas[(int)i];
				mx = max(mx,vals[(int)i + 1]);
				//prln(" " + mas[(int)i]);
				a[(int)(i % m)] = (x * a[(int)(i % m)] + y * (i + 1)) % z;
			}
			Arrays.sort(vals);
			for (int i = 1; i < n; i++)
				while (vals[i] == vals[i + 1] && vals[i] != mx)
					for (int k = i + 1; k < n; k++)
						vals[k] = vals[k + 1];
			int tek = 0;
			for (int i = 1; vals[i] != mx; i++)
				tek = i;
			for (int i = tek + 2; i < n + 1; i++)
				vals[i] = mx + 1;
			//System.out.println(solve() + " " + solveTrue());
			pw.println("Case #" + (j + 1) + ": " + solve());
		}
		pw.close();
		sc.close();
		System.out.println("Exit");
	}
	
	class Summator
	{
		long[] mas;
		
		Summator()
		{
			mas = new long[(int)(n+ 1)];
		}
		
		void add(long val, int pos)
		{
			pos = Arrays.binarySearch(vals,pos);
			while (pos <= n - 1)
			{
				mas[pos] = (mas[pos] + val) % 1000000007;
				pos = (pos << 1) - (pos & (pos - 1));
			}
		}
		
		long get(int pos)
		{
			pos = Arrays.binarySearch(vals,pos) - 1;
			long val = 0;
			while (pos > 0)
			{
				val = (val + mas[pos]) % 1000000007;
				pos = pos & (pos - 1);
			}
			return val;
		}
	}
	
	String solveTrue()
	{
		long resOne = 0;
		res = new long[n];
		for (int i = 0; i < n; i++)
		{
			res[i] = 1;
			for (int j = 0; j < i; j++)
				if (mas[i] > mas[j])
					res[i] = (res[i] + res[j]) % 1000000007;
			resOne = (resOne + res[i]) % 1000000007;
			if (i % 10000 == 0)
				prln(" " + (i + 1));
		}
		return String.valueOf(resOne);
	}
	
	String solve()
	{
		Summator sum = new Summator();
		long resOne = 0;
		res = new long[n];
		for (int i = 0; i < n; i++)
		{
			res[i] = (sum.get((int)mas[i]) + 1) % 1000000007;
			sum.add(res[i],(int)mas[i]);
			resOne = (resOne + res[i]) % 1000000007;
		}
		return String.valueOf(resOne);
	}
	
	public static void main(String args[]) throws IOException
	{
		Olymp ol = new Olymp();
		ol.input();
		
	}
}