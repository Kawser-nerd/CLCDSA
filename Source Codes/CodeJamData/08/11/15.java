import java.io.*;
import java.util.*;

public class A 
{
	public static int n;
	public static long [] x;
	public static long [] y;
	public static long sol;

	public static void solve ()
	{
		Arrays.sort (x);
		Arrays.sort (y);
		sol = 0;
		for (int i = 0; i < n; i++)
			sol += (x [i] * y [n - i - 1]);
	}

	public static void main(String[] args) throws IOException 
	{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-large.out"));
		
		int numTest = Integer.parseInt(in.readLine());
		for (int testCase = 0; testCase < numTest; testCase++)
		{
			n = Integer.parseInt(in.readLine());
			x = new long [n];
			String [] tmp = in.readLine().split(" ");
			for (int i = 0; i < n; i++)
				x [i] = Long.parseLong(tmp [i]);
			y = new long [n];
			tmp = in.readLine().split(" ");
			for (int i = 0; i < n; i++)
				y [i] = Long.parseLong(tmp [i]);
			
			solve ();
			
			out.write("Case #" + (testCase + 1) + ": " + sol);
			out.newLine();
		}
		in.close();
		out.close();
	}

}
