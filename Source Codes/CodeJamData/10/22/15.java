import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for(int c = 1; c <= cases; c++)
		{
			int n = sc.nextInt();
			int k = sc.nextInt();
			int barnloc = sc.nextInt();
			int targetTime = sc.nextInt();
			
			int[] start = new int[n];
			int[] v = new int[n];
			boolean[] elect = new boolean[n];
			
			for(int i = 0; i < n; i++)
				start[i] = sc.nextInt();
			for(int i = 0; i < n; i++)
				v[i] = sc.nextInt();
				
			for(int i = 0; i < n; i++)
				elect[i] = (start[i] + v[i] * targetTime >= barnloc);
			
			int rem = k;
			int swaps = 0;
			for(int i = n - 1; i >= 0; i--)
			{
				if(elect[i])
					rem--;
				else
					swaps += rem;
				
				if(rem == 0)
					break;
			}
			
			if(rem == 0)
				System.out.println("Case #" + c + ": " + swaps);
			else
				System.out.println("Case #" + c + ": IMPOSSIBLE");
		}
	}
	
}