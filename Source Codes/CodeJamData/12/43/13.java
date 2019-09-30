import java.util.*;
import java.awt.*;
import java.math.*;

public class C
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			boolean rtn = false;
			int n = scan.nextInt();

			int[] a = new int[n-1];
			for(int i=0;i < n-1;i++)
				a[i] = scan.nextInt() - 1;

			int TRIALS = 10000000;
			int[] h = new int[n];

			while(TRIALS --> 0)
			{
				//Find a problem
				boolean good = true;
				
				for(int i=0;i < n-1;i++)
				{
					double m = -999999999;
					int max = -1;

					for(int j=i+1;j < n;j++)
					{
						double tm = (double)(h[j] - h[i]) / (j-i);
						if(tm > m)
						{
							m = tm;
							max = j;
						}
					}

					if(max != a[i]) //Problem!
					{
						good = false;
						h[a[i]]++;
						break;
					}
				}



				if(good) break;
			}
			
			

			System.out.print("Case #" + ca + ":");

			if(TRIALS <= 0) System.out.println(" Impossible");
			else
			{
				for(int i=0;i < n;i++)
					System.out.print(" " + h[i]);
				System.out.println();
			}
		}
	}
}