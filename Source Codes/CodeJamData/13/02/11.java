import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			int r = readInt();
			int c = readInt();
			int[][] want = new int[r][c];
			for(int i = 0; i < r; i++)	{
				for(int j = 0; j < c; j++)	{
					want[i][j] = readInt();
				}
			}
			boolean can = true;
			boolean[] rowCan = new boolean[r];
			boolean[] colCan = new boolean[c];
			Arrays.fill(rowCan, true);
			Arrays.fill(colCan, true);
			for(int h = 100; can && h >= 1; h--)	{
				for(int i = 0; i < r; i++)	{
					for(int j = 0; j < c; j++)	{
						if(want[i][j] > h)	{
							rowCan[i] = false;
							colCan[j] = false;
						}
					}
				}
				for(int i = 0; i < r; i++)	{
					for(int j = 0; j < c; j++)	{
						if(want[i][j] == h)	{
							if(!rowCan[i] && !colCan[j])	{
								can = false;
							}
						}
					}
				}
				
			}
			pw.println(can ? "YES" : "NO");
		}
		pw.close();
	}

	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}


}
