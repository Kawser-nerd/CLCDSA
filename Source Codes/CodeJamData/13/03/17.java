import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	
	static Set<BigInteger> set;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		set = new HashSet<BigInteger>();
		for(int i = 1; i <= 102; i++)	{
			System.out.println(i);
			char[] list = new char[i];
			dfs(0, list, 0);
		}
		BigInteger[] list = new BigInteger[set.size()];
		int qqqq = 0;
		for(BigInteger out: set)	{
			list[qqqq++] = out;
		}
		Arrays.sort(list);
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			System.out.println(casenum);
			pw.printf("Case #%d: ", casenum);
			BigInteger small = new BigInteger(nextToken());
			BigInteger big = new BigInteger(nextToken());
			int min = 0;
			int max = list.length-1;
			while(min != max)	{
				int mid = (min+max)/2;
				if(list[mid].compareTo(small) < 0)	{
					min = mid+1;
				}
				else	{
					max = mid;
				}
			}
			int left = min;
			min = 0;
			max = list.length-1;
			while(min != max)	{
				int mid = (min+max)/2;
				if(min == mid)	{
					mid++;
				}
				if(list[mid].compareTo(big) > 0)	{
					max = mid-1;
				}
				else	{
					min = mid;
				}
			}
			int right = min;
			pw.println(right-left+1);
		}
		pw.close();
	}
	
	public static void dfs(int index, char[] list, int sum)	{
		if(index > list.length-1-index)	{
			BigInteger left = new BigInteger(new String(list));
			left = left.pow(2);
			if(palin(left))	{
				set.add(left);
			}
			return;
		}
		for(int dig = 0; dig < 4; dig++)	{
			if(sum + dig * dig >= 10) break;
			int first = index;
			int second = list.length-1-first;
			if(first != second && sum + 2 * dig * dig < 10)	{
				list[first] = (char)('0' + dig);
				list[second] = (char)('0' + dig);
				dfs(index+1, list, sum + 2 * dig * dig);
			}
			else if(first == second && sum + dig * dig < 10)	{
				list[first] = (char)('0' + dig);
				dfs(index+1, list, sum + dig * dig);
			}
		}
	}
	
	public static boolean palin(BigInteger curr)	{
		String str = curr.toString();
		return str.equals(new StringBuilder(str).reverse().toString());
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
