
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		final int NUM_CASES = readInt();
		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
			pw.print("Case #" + casenum + ": ");
			int n = readInt();
			int[] one = new int[n];
			int[] two = new int[n];
			for(int i = 0; i < n; i++)	{
				one[i] = readInt();
				two[i] = readInt();
			}
			for(int i = 0; i < n; i++)	{
				for(int j = 0; j < n-1; j++)	{
					if(two[j] < two[j+1])	{
						int temp = two[j];
						two[j] = two[j+1];
						two[j+1] = temp;
						temp = one[j];
						one[j] = one[j+1];
						one[j+1] = temp;
					}
				}
			}
			int[] numHas = new int[n];
			int numCurr = 0;
			int ret = 0;
			outer: while(true)	{
				for(int i = 0; i < n; i++)	{
					if(numHas[i] < 2 && two[i] <= numCurr)	{
						while(numHas[i] < 2)	{
							numHas[i]++;
							numCurr++;
						}
						ret++;
						continue outer;
					}
				}
				for(int i = 0; i < n; i++)	{
					if(numHas[i] < 1 && one[i] <= numCurr)	{
						while(numHas[i] < 1)	{
							numHas[i]++;
							numCurr++;
						}
						ret++;
						continue outer;
					}
				}
				break;
			}
			if(numCurr != 2*n)
				pw.println("Too Bad");
			else
				pw.println(ret);
		}
		pw.close();
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}
