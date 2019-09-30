import java.util.*;

public class WhatAreBirds
{
	static final Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		for(int t=1;t<=T;t++)
		{
			System.out.print("Case #"+t+": ");
			int n = sc.nextInt();
			boolean birdPresent = false;
			
			int[] h = new int[n]; int[] w = new int[n];
			boolean[] isB = new boolean[n];
			for(int i=0;i<n;i++)
			{
				h[i] = sc.nextInt();
				w[i] = sc.nextInt();
				String str = sc.next();
				isB[i] = str.equals("BIRD");
				if(!isB[i])
					sc.next();
				birdPresent |= isB[i];
			}
			
			int uh = 0, lh = 1000000, uw = 0, lw = 1000000;
			for(int i=0;i<n;i++)
			{
				if(isB[i])
				{
					lh = Math.min(lh, h[i]);
					uh = Math.max(uh, h[i]);
					
					lw = Math.min(lw, w[i]);
					uw = Math.max(uw, w[i]);
				}
			}
			System.out.println();
			int m = sc.nextInt();
			for(int i=0;i<m;i++)
			{
				int height = sc.nextInt();
				int weight = sc.nextInt();
				
				boolean isNotBird = !birdPresent ||
					(height<lh || height >uh || weight<lw || weight>uw);
					
				int nlh = Math.min(lh, height);
				int nuh = Math.max(uh, height);
				int nlw = Math.min(lw, weight);
				int nuw = Math.max(uw, weight);
				boolean isBird = true;
				for(int j=0;j<n;j++)
				{
					if(!isB[j] &&
						h[j]>=nlh && h[j]<=nuh && w[j]>=nlw && w[j]<=nuw)
					{
						isBird = false;
						break;
					}
				}
				if((isBird && isNotBird))
					System.out.println("UNKNOWN");
				else if(isBird)
					System.out.println("BIRD");
				else
					System.out.println("NOT BIRD");
			}
		}
	}
}
