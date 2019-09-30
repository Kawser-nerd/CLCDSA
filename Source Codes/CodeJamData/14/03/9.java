import java.util.*;
import java.io.*;
public class C
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new File("C-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("C-large.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int r = in.nextInt();
			int c = in.nextInt();
			int m = in.nextInt();
			
			char[][] grid = new char[r][c];
			for(int y = 0; y < grid.length; y++)
			{
				Arrays.fill(grid[y], '*');
			}
			
			int empty = r * c - m;
			
			boolean possible = true;
			if(empty == 1)
			{
				grid[0][0] = 'c';
			}
			else if(r == 1)
			{
				for(int z = 0; z < empty; z++)
				{
					grid[0][z] = '.';
				}
			}
			else if(c == 1)
			{
				for(int a = 0; a < empty; a++)
				{
					grid[a][0] = '.';
				}
			}
			else if(empty < 4)
			{
				possible = false;
			}
			else if(Math.min(r, c) == 2)
			{
				if(empty % 2 == 1)
				{
					possible = false;
				}
				else
				{
					even(grid, empty);
				}
			}
			else
			{
				if(empty % 2 == 0)
				{
					even(grid, empty);
				}
				else
				{
					if(empty < 9)
					{
						possible = false;
					}
					else
					{
						odd(grid, empty);
					}
				}
			}
			
			grid[0][0] = 'c';
			
			out.println("Case #" + (x + 1) + ":");
			if(!possible)
			{
				out.println("Impossible");
			}
			else
			{
				for(int z = 0; z < grid.length; z++)
				{
					out.println(new String(grid[z]));
				}
			}
		}
		
		out.close();
	}
	
	public static void even(char[][] grid, int empty)
	{
		for(int a = 0; a < grid.length; a++)
		{
			grid[a][0] = '.';
			grid[a][1] = '.';
			
			empty -= 2;
			if(empty == 0)
			{
				return;
			}
		}
		
		for(int b = 2; b < grid[0].length; b++)
		{
			grid[0][b] = '.';
			grid[1][b] = '.';
			
			empty -= 2;
			if(empty == 0)
			{
				return;
			}
		}
		
		for(int c = 2; c < grid.length; c++)
		{
			for(int d = 2; d < grid[0].length; d++)
			{
				grid[c][d] = '.';
				empty--;
				if(empty == 0)
				{
					return;
				}
			}
		}
	}
	
	public static void odd(char[][] grid, int empty)
	{
		for(int a = 0; a < 3; a++)
		{
			for(int b = 0; b < 3; b++)
			{
				grid[a][b] = '.';
				empty--;
			}
		}
		
		if(empty == 0)
		{
			return;
		}
		
		for(int c = 3; c < grid.length; c++)
		{
			grid[c][0] = '.';
			grid[c][1] = '.';
			
			empty -= 2;
			if(empty == 0)
			{
				return;
			}
		}
		
		for(int d = 3; d < grid[0].length; d++)
		{
			grid[0][d] = '.';
			grid[1][d] = '.';
			
			empty -= 2;
			if(empty == 0)
			{
				return;
			}
		}
		
		for(int e = 2; e < grid.length; e++)
		{
			for(int f = 2; f < grid[0].length; f++)
			{
				if(!(e == 2 && f == 2))
				{
					grid[e][f] = '.';
					empty--;
					if(empty == 0)
					{
						return;
					}
				}
			}
		}
	}
}
