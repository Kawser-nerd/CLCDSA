import java.util.*;

public class ModernArtEasy
{
	static final Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int t=1;t<=T;t++)
		{
			System.out.print("Case #"+t+": ");
			int n = sc.nextInt();
			a = new boolean[n][n];
			for(int i=0;i+1<n;i++)
			{
				int u = sc.nextInt()-1; int v =sc.nextInt()-1;
				a[u][v] = a[v][u] = true;
			}
			int m = sc.nextInt();
			b = new boolean[m][m];
			for(int i=0;i+1<m;i++)
			{
				int u = sc.nextInt()-1; int v =sc.nextInt()-1;
				b[u][v] = b[v][u] = true;
			}
			
			if(recurse(0, new boolean[n], new int[m]))
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
	static boolean[][] a, b;
	static boolean recurse(int index, boolean[] used, int[] ass)
	{
		int m = b.length, n = a.length;
		if(index<m)
		{
			for(int i=0;i<n;i++)
			{
				if(!used[i])
				{
					ass[index] = i;
					used[i] = true;
					if(recurse(index+1,used,ass))
						return true;
					used[i] = false;
				}
			}
		}
		else
		{
			for(int i=0;i<m;i++)
				for(int j=0;j<m;j++)
					if(a[ass[i]][ass[j]]!=b[i][j])
						return false;
			return true;
		}
		return false;
	}
	
}
