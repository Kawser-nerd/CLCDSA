import java.util.*;

public class Bacteria
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int i=1;i<=T;i++)
		{
			System.out.println("Case #"+i+": "+solveCase());
		}
	}
	static int solveCase()
	{
		boolean[][] grid = new boolean[300][300];
		boolean[][] temp = new boolean[300][300];
		int R = sc.nextInt();
		for(int i=0;i<R;i++)
		{
			int x1 = sc.nextInt(), y1 = sc.nextInt();
			int x2 = sc.nextInt(), y2 = sc.nextInt();
			x1--; x2--; y1--; y2--;
			for(int x=x1;x<=x2;x++)
				for(int y=y1;y<=y2;y++)
					grid[y][x] = true;
		}
		int res = 0;
		while(true)
		{
			boolean alive = false;
			for(int i=0;i<grid.length;i++)
				for(int j=0;j<grid[i].length;j++)
					alive |= grid[i][j];
			if(!alive)
				break;
			for(boolean[] arr:temp)
				Arrays.fill(arr, false);
			for(int i=0;i<grid.length;i++)
			{
				for(int j=0;j<grid[i].length;j++)
				{
					boolean north = i>0 && grid[i-1][j];
					boolean west = j>0 && grid[i][j-1];
					temp[i][j] = (grid[i][j] && (north||west)) || (north&&west);
				}
			}
			boolean[][] t = temp; temp = grid; grid = t;
			res++;
		}
		return res;
	}
}
