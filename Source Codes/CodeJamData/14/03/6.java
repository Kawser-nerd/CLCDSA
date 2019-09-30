import java.util.*;
import java.io.*;
public class c {
	static int[] di = new int[]{1, 1, 0, -1, -1, -1, 0, 1};
	static int[] dj = new int[]{0, 1, 1, 1, 0, -1, -1, -1};
	static PrintWriter out;
public static void main(String[] args) throws IOException
{
	Scanner input = new Scanner(System.in);
	out = new PrintWriter(new File("c.txt"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		out.printf("Case #%d:\n", t+1);
		int n = input.nextInt(), m = input.nextInt(), x = input.nextInt();
		char[][] grid = new char[n][m];
		for(char[] c: grid) Arrays.fill(c, '.');
		for(int i = 0; i<x; i++) grid[i/m][i%m] = '*';
		if(possible(grid))
		{
			print(grid);
			continue;
		}
		int lasti = (x-1)/m, lastj = (x-1)%m;
		boolean found = false;
		for(int i = 0; i<Math.min(100, x); i++)
		{
			if(lasti < n-(i+1))
			{
				grid[lasti][lastj] = '.';
				grid[lasti+(i+1)][0] = '*';
				if(possible(grid))
				{
					found = true;
					print(grid);
					break;
				}
				lastj--;
				if(lastj < 0)
				{
					lastj = m-1;
					lasti--;
				}
			}
			else if(lasti < n-1 && i < grid[0].length - 1)
			{
				grid[lasti][lastj] = '.';
				grid[lasti+1][i] = '*';
				if(possible(grid))
				{
					found = true;
					print(grid);
					break;
				}
				lastj--;
				if(lastj < 0)
				{
					lastj = m-1;
					lasti--;
				}
			}
			else break;
		}
		if(found) continue;
		if(square(n*m - x))
		{
			for(char[] c: grid) Arrays.fill(c, '*');
			int sqrt = (int)(.5+Math.sqrt(n*m-x));
			if(sqrt <= m && sqrt<= n)
			{
				for(int i = 0; i<sqrt; i++)
					for(int j = 0; j<sqrt; j++)
						grid[n-1-i][m-1-j] = '.';
				if(possible(grid))
				{
					print(grid);
					continue;
				}
			}
		}
		for(int xx = 1; xx<=m; xx++)
		{
			if((n*m - x)%xx != 0) continue;
			int yy = (n*m - x)/xx;
			if(yy > n) continue;
			for(char[] c: grid) Arrays.fill(c, '*');
			for(int i = 0; i<xx; i++)
				for(int j = 0; j<yy; j++)
				{
					grid[n-1-j][m-1-i] = '.';
				}
			if(possible(grid))
			{
				print(grid);
				found = true;
				break;
			}
		}
		if(found) continue;
		out.println("Impossible");
	}
	out.close();
}
static boolean square(int x)
{
	int sqrt = (int)(.5+Math.sqrt(x));
	return sqrt*sqrt == x;
}
static void print(char[][] grid)
{
	grid[grid.length-1][grid[0].length-1] = 'c';
	for(int i = 0; i<grid.length; i++) out.println(new String(grid[i]));
}
static boolean possible(char[][] grid)
{
	//for(char[] c: grid) System.out.println(new String(c));
	int count = 0;
	char[][] copy = new char[grid.length][grid[0].length];
	for(int i = 0; i<grid.length; i++)
		for(int j = 0; j<grid[0].length; j++)
		{
			copy[i][j] = grid[i][j];
			if(grid[i][j] == '.') count++;
		}
	//for(int i = 0; i<copy.length; i++) System.out.println(new String(copy[i]));
	int other = floodfill(grid.length-1, grid[0].length-1, copy);
	return count == other;
}
static int floodfill(int i, int j, char[][] grid)
{
	if(i<0 || j<0 || i>= grid.length || j>= grid[0].length || grid[i][j] != '.') return 0;
	grid[i][j] = '#';
	int res = 1;
	int count = 0;
	for(int k = 0; k<8; k++)
	{
		int ni = i+di[k], nj = j+dj[k];
		if(ni<0 || nj<0 || ni>=grid.length || nj>=grid[0].length) continue;
		if(grid[ni][nj] == '*') count++;
	}
	//System.out.println(i+" "+j+" "+count);
	if(count >0) return res;
	for(int k = 0; k<8; k++) res += floodfill(i+di[k], j+dj[k], grid);
	return res;
}
}
