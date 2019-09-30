import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static char[][] grid;
	static int r, c;
	static int ret;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			pw.printf("Case #%d: ", casenum);
			r = readInt();
			c = readInt();
			grid = getGrid();
			int ret = 0;
			boolean poss = true;
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(grid[i][j] == '.') continue;
					int dx = 0;
					int dy = 0;
					if(grid[i][j] == '>') dy = 1;
					else if(grid[i][j] == '<') dy = -1;
					else if(grid[i][j] == 'v') dx = 1;
					else if(grid[i][j] == '^') dx = -1;
					else throw new RuntimeException("OOPS");
					int nextX = i+dx;
					int nextY = j+dy;
					boolean change = false;
					while(!arrow(nextX, nextY)) {
						if(!valid(nextX, nextY)) {
							change = true;
							break;
						}
						nextX += dx;
						nextY += dy;
					}
					if(!change) continue;
					boolean can = false;
					for(int k = 0; k < deltaX.length; k++) {
						boolean bad = false;
						if(deltaX[k] == dx && deltaY[k] == dy) continue;
						nextX = i + deltaX[k];
						nextY = j + deltaY[k];
						while(!arrow(nextX, nextY)) {
							if(!valid(nextX, nextY)) {
								bad = true;
								break;
							}
							nextX += deltaX[k];
							nextY += deltaY[k];
						}
						if(!bad) {
							can = true;
							ret++;
							break;
						}
					}
					if(!can) {
						poss = false;
					}
				}
			}
			if(!poss) {
				pw.println("IMPOSSIBLE");
			}
			else {
				pw.println(ret);
			}
		}
		pw.close();
	}

	static int[] deltaX = new int[]{-1,1,0,0};
	static int[] deltaY = new int[]{0,0,-1,1};
	
	public static boolean arrow(int x, int y) {
		return valid(x, y) && grid[x][y] != '.';
	}
	
	public static boolean valid(int x, int y) {
		return x >= 0 && x < r && y >= 0 && y < c;
	}
	
	public static char[][] getGrid() throws IOException {
		char[][] temp = new char[r][c];
		for(int i = 0; i < r; i++) {
			String s = nextToken();
			for(int j = 0; j < c; j++) {
				temp[i][j] = s.charAt(j);
			}
		}
		return temp;
	}

	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
