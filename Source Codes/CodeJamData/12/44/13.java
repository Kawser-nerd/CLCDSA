
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	static char[][] grid;
	static int r,c;
	
	static int[] dx = new int[]{-1,0,0};
	static int[] dy = new int[]{0,-1,1};
	
	static Set<String> seen;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		final int NUM_CASES = readInt();
		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
			pw.println("Case #" + casenum + ":");
			r = readInt();
			c = readInt();
			grid = new char[r][c];
			for(int i = 0; i < r; i++)
				grid[i] = nextToken().toCharArray();
			for(char ch = '0'; ch <= '9'; ch++)	{
				for(int i = 0; i < r; i++)	{
					for(int j = 0; j < c; j++)	{
						if(grid[i][j] == ch)	{
							seen = new HashSet<String>();
							solve(i,j);
						}
					}
				}
			}
		}
		pw.close();
	}

	public static void solve(int x, int y)	{
		boolean[][] reach = new boolean[r][c];
		LinkedList<State> q = new LinkedList<State>();
		q.add(new State(x,y));
		reach[x][y] = true;
		while(!q.isEmpty())	{
			State curr = q.removeFirst();
			for(int k = 0; k < dx.length; k++)	{
				int nx = curr.x + dx[k];
				int ny = curr.y + dy[k];
				if(!reach[nx][ny] && grid[nx][ny] != '#')	{
					reach[nx][ny] = true;
					q.addLast(new State(nx, ny));
				}
			}
		}
		boolean lucky = luck(reach, x, y);
		int count = 0;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				if(reach[i][j])
					count++;
		pw.println(grid[x][y] + ": " + count + " " + (lucky ? "Lucky" : "Unlucky"));
	}

	public static void print(boolean[][] grid)	{
		for(boolean[] a: grid)	{	
			for(boolean b: a)
				pw.print(b ? 1 : 0);
			pw.println();
		}
	}
	
	public static boolean luck(boolean[][] valid, int x, int y)	{
		//pw.println(x + " " + y);
		//print(valid);
		//pw.println();
		int count = 0;
		for(int i = x+1; i < r; i++)	{
			for(int j = 0; j < c; j++)
				if(valid[i][j])
					return false;
		}
		for(int i = 0; i < r; i++)	{
			for(int j = 0; j < c; j++)	{
				if(valid[i][j])
					count++;
			}
		}
		if(count == 1 && valid[x][y])
			return true;
		String str = get(valid);
		if(!seen.add(str))
			return false;
		for(int k = 0; k < dx.length; k++)	{
			boolean[][] next = new boolean[r][c];
			for(int i = 0; i < r; i++)	{
				for(int j = 0; j < c; j++)	{
					if(grid[i][j] == '#')
						continue;
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(valid(nx, ny) && valid[nx][ny])
						next[i][j] = true;
					int outX = i - dx[k];
					int outY = j - dy[k];
					if(valid[i][j] && (!valid(outX, outY) || grid[outX][outY] == '#'))
						next[i][j] = true;
				}
			}
			String nextA = get(next);
			if(!str.equals(nextA))
				if(luck(next, x, y))
					return true;
		}
		return false;
	}
	
	public static String get(boolean[][] grid)	{
		char[] sb = new char[r*c];
		int c = 0;
		for(boolean[] a: grid)
			for(boolean b: a)
				sb[c++] = (b?'0':'1');
		return new String(sb);
	}
	
	public static boolean valid(int x, int y)	{
		return x >= 0 && x < r && y >= 0 && y < c;
	}
	
	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
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
