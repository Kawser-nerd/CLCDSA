import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import java.math.*;

public class Olymp
{
	static String INPUT_NAME = "input.txt";
	static String OUTPUT_NAME = "output.txt";
	static double eps = 1e-10;
	
	int n,k,p,l;
	long[] fr;
	
	void prln(String st)
	{
		System.out.println(st);
	}
	
	void input() throws IOException
	{
		Scanner sc = new Scanner(new File(INPUT_NAME));
		PrintWriter pw = new PrintWriter(OUTPUT_NAME);
		int kolC = sc.nextInt();
		for (int i = 0; i < kolC; i++)
		{
			System.out.println();
			System.out.println("New case " + (i + 1));
			n = sc.nextInt();
			p = sc.nextInt();
			l = sc.nextInt();
			fr = new long[l];
			for (int j = 0; j < l; j++)
				fr[j] = sc.nextInt();
			System.out.println(solve() + " " + solveTrue());
			pw.println("Case #" + (i + 1) + ": " + solveTrue());
		}
		pw.close();
		sc.close();
		System.out.println("Exit");
	}
	
	String solveTrue()
	{
		Arrays.sort(fr);
		int val = l - 1;
		long res = 0;
		for (long i = 1; i <= n; i++)
			for (int j = 0; j < p; j++)
			{
				res += i * fr[val--];
				if (val == -1)
					return String.valueOf(res);
			}
		return String.valueOf(res);
	}
	
	String solve()
	{
		return "No";
	}
	
	public static void main(String args[]) throws IOException
	{
		Olymp ol = new Olymp();
		ol.input();
		
	}
}