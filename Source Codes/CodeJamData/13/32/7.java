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
			int x = readInt();
			int y = readInt();
			int dist = Math.abs(x) + Math.abs(y);
			int max = 1;
			while((max*max+max)/2 < dist || ((max*max+max)/2)%2 != dist%2)	{
				max++;
			}
			char[] list = new char[max];
			for(int i = max-1; i >= 0; i--)	{
				if(Math.abs(x) > Math.abs(y))	{
					if(x > 0)	{
						list[i] = 'E';
						x -= i+1;
					}
					else {
						list[i] = 'W';
						x += i+1;
					}
				}
				else	{
					if(y > 0)	{
						list[i] = 'N';
						y -= i+1;
					}
					else	{
						list[i] = 'S';
						y += i+1;
					}
				}
			}
			pw.println(new String(list));
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
