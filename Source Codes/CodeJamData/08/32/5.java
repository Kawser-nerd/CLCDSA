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
	String st;
	int[] pos;
	int len;
	
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
			st = sc.next();
			System.out.println(solve() + " " + solveTrue());
			pw.println("Case #" + (i + 1) + ": " + solveTrue());
		}
		pw.close();
		sc.close();
		System.out.println("Exit");
	}
	
	void plus(int k)
	{
		pos[k]++;
		if (pos[k] == 3)
		{
			pos[k] = 0;
			plus(k-1);
		}
	}
	
	int can()
	{
		long val = 0;
		long a = st.charAt(0) - '0';
		int zn = 0;
		for (int i = 1; i < len; i++)
		{
			switch (pos[i])
			{
			case 1: 
			{
				switch (zn)
				{
				case 0: val += a; a = 0; break;
				case 1: val -= a; a = 0; break;
				}
				zn = 0;
				break;
			}
			case 2: 
			{
				switch (zn)
				{
				case 0: val += a; a = 0; break;
				case 1: val -= a; a = 0; break;
				}
				zn = 1;
				break;
			}
			}
			a = a * 10 + st.charAt(i) - '0'; 
		}
		switch (zn)
		{
		case 0: val += a; a = 0; break;
		case 1: val -= a; a = 0; break;
		}
		if (val % 2 == 0 || val % 3 == 0 || val % 5 == 0 || val % 7 == 0)
			return 1;
		return 0;
	}
	
	String solveTrue()
	{
		int res = 0;
		len = st.length();
		pos = new int[len];
		while (pos[0] == 0)
		{
			res += can();
			plus(len - 1);
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