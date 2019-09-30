import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static char[][] grid;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("a.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d: ", casenum);
			grid = new char[4][4];
			int num = 0;
			for(int i = 0; i < 4; i++)	{
				grid[i] = nextToken().toCharArray();
				for(int j = 0; j < 4; j++)	{
					if(grid[i][j] == '.')
						num++;
				}
			}
			boolean xWon = false;
			boolean oWon = false;
			for(int i = 0; i < 4; i++)	{
				xWon |= rowCount(i, 'X') == 3 && rowCount(i, 'T') == 1;
				xWon |= rowCount(i, 'X') == 4;
				xWon |= colCount(i, 'X') == 3 && colCount(i, 'T') == 1;
				xWon |= colCount(i, 'X') == 4;
				xWon |= diagCount(i, 'X') == 3 && diagCount(i, 'T') == 1;
				xWon |= diagCount(i, 'X') == 4;
				oWon |= rowCount(i, 'O') == 3 && rowCount(i, 'T') == 1;
				oWon |= rowCount(i, 'O') == 4;
				oWon |= colCount(i, 'O') == 3 && colCount(i, 'T') == 1;
				oWon |= colCount(i, 'O') == 4;
				oWon |= diagCount(i, 'O') == 3 && diagCount(i, 'T') == 1;
				oWon |= diagCount(i, 'O') == 4;
			}
			if(xWon)	{
				pw.println("X won");
			}
			else if(oWon)	{
				pw.println("O won");
			}
			else if(num == 0)	{
				pw.println("Draw");
			}
			else	{
				pw.println("Game has not completed");
			}
		}
		pw.close();
	}

	public static int rowCount(int row, char ch)	{
		int ret = 0;
		for(int i = 0; i < 4; i++)	{
			if(grid[row][i] == ch)	{
				ret++;
			}
		}
		return ret;
	}

	public static int colCount(int row, char ch)	{
		int ret = 0;
		for(int i = 0; i < 4; i++)	{
			if(grid[i][row] == ch)	{
				ret++;
			}
		}
		return ret;
	}

	public static int diagCount(int dir, char ch)	{
		int ret = 0;
		for(int i = 0; i < 4; i++)	{
			if(dir == 1)	{
				if(grid[i][i] == ch)	{
					ret++;
				}
			}
			else	{
				if(grid[i][3-i] == ch)	{
					ret++;
				}
			}
		}
		return ret;
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
