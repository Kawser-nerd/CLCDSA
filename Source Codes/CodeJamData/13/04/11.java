import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int[] keyCount;

	static int[] needs;
	static ArrayList<Integer>[] has;

	static LinkedList<Integer> ret;

	static boolean[] used;

	static Set<Integer> seen;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("d.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("d.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			System.out.println(casenum);
			seen = new HashSet<Integer>();
			pw.printf("Case #%d: ", casenum);
			keyCount = new int[201];
			int k = readInt();
			int n = readInt();
			needs = new int[n];
			has = new ArrayList[n];
			while(k-- > 0)	{
				keyCount[readInt()]++;
			}
			for(int i = 0; i < n; i++)	{
				needs[i] = readInt();
				int qqq = readInt();
				has[i] = new ArrayList<Integer>();
				while(qqq-- > 0)	{
					has[i].add(readInt());
				}
			}
			ret = new LinkedList<Integer>();
			used = new boolean[n];
			dfs(0);
			if(ret.isEmpty())	{
				pw.println("IMPOSSIBLE");
			}
			else	{
				StringBuilder sb = new StringBuilder();
				for(int out: ret)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
	}

	public static boolean dfs(int curr)	{
		if(curr == used.length)	{
			return true;
		}
		int mask = 0;
		for(int i = 0; i < used.length; i++)	{
			if(used[i])	{
				mask |= 1 << i;
			}
		}
		if(!seen.add(mask))
			return false;
		for(int i = 0; i < used.length; i++)	{
			if(!used[i] && keyCount[needs[i]] > 0)	{
				used[i] = true;
				keyCount[needs[i]]--;
				for(int out: has[i])	{
					keyCount[out]++;
				}
				if(dfs(curr+1)){
					ret.addFirst(i+1);
					return true;
				}
				for(int out: has[i])	{
					keyCount[out]--;
				}
				keyCount[needs[i]]++;
				used[i] = false;
			}
		}
		return false;
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
