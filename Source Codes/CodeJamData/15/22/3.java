import java.util.*;
public class b {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t =  1; t<=T; t++)
	{
		System.out.print("Case #"+t+": ");
		int r = input.nextInt(), c = input.nextInt(), n = input.nextInt();
		boolean[][] grid = new boolean[r][c];
		ArrayList<Integer> poss = new ArrayList<Integer>();
		for(int i = 0; i<r; i++)
			for(int j = 0; j<c; j++)
			{
				if((i+j)%2 == 0)
				{
					poss.add(0);
					grid[i][j] = true;
				}
			}
		for(int i = 0; i<r; i++)
			for(int j = 0; j<c; j++)
			{
				if(grid[i][j]) continue;
				int count = 0;
				if(i>0) count++;
				if(j>0) count++;
				if(i<r-1)count++;
				if(j<c-1) count++;
				poss.add(count);
			}
		Collections.sort(poss);
		int res1 = 0;
		for(int i = 0; i<n; i++) res1 += poss.get(i);
		grid = new boolean[r][c];
		poss = new ArrayList<Integer>();
		for(int i = 0; i<r; i++)
			for(int j = 0; j<c; j++)
			{
				if((i+j)%2 == 1)
				{
					poss.add(0);
					grid[i][j] = true;
				}
			}
		for(int i = 0; i<r; i++)
			for(int j = 0; j<c; j++)
			{
				if(grid[i][j]) continue;
				int count = 0;
				if(i>0) count++;
				if(j>0) count++;
				if(i<r-1)count++;
				if(j<c-1) count++;
				poss.add(count);
			}
		Collections.sort(poss);
		int res2 = 0;
		for(int i = 0; i<n; i++) res2 += poss.get(i);
		System.out.println(Math.min(res1, res2));
	}
}
}
