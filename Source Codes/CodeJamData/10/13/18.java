import java.util.*;

public class NumberGame
{
	static Scanner sc = new Scanner(System.in);
	static final int MAX = 1000000;
	static boolean solve(int low, int high)
	{
		if(low==high)
			return false;
		boolean res = true;
		while(true)
		{
			if(2*low<=high)
				return res;
			high -= low;
			int temp = low;
			low = high;
			high = temp;
			res = !res;
		}
	}
	public static void main(String[] args)
	{
		int T = sc.nextInt();
		int[] a1 = new int[T]; int[] a2 = new int[T];
		int[] b1 = new int[T]; int[] b2 = new int[T];
		long[] res = new long[T];
		for(int i=0;i<T;i++)
		{
			a1[i] = sc.nextInt(); a2[i] = sc.nextInt();
			b1[i] = sc.nextInt(); b2[i] = sc.nextInt();
			int count = 0;
			for(int a=a1[i];a<=a2[i];a++)
			{
				for(int b=b1[i];b<=b2[i];b++)
				{
					if(solve(Math.min(a,b), Math.max(a,b)))
						count++;
				}
			}
			System.out.println("Case #"+(i+1)+": "+count);
			//res[i] = (long)(a2[i]-a1[i]+1)*(b2[i]-b1[i]+1);
		}
		/*
		
		int count = 0;
		for(int j=1;j<=MAX;j++)
		{
			for(int i=0;i<T;i++)
			{
				if(j>=a1[i] && j<=a2[i] &&
					j>=b1[i] && j<=b2[i])
					res[i]--;
			}
		}
		for(int next=2;next<=MAX;next++)
		{
			int a = next, b = a+1;
			while(b<=MAX)
			{
				int lower = a, upper = b;
				while(upper <= MAX)
				{
					//A.spr(lower+":"+upper);
					for(int i=0;i<T;i++)
					{
						if(lower>=a1[i] && lower<=a2[i] &&
							upper>=b1[i] && upper<=b2[i])
							res[i]--;
						if(lower>=b1[i] && lower<=b2[i] &&
							upper>=a1[i] && upper<=a2[i])
							res[i]--;
					}
					lower += a; upper += b;
				}
				int temp = a;
				a = b;
				b += temp;
				temp = a;
				a = b;
				b += temp;
			}
		}
		for(int i=0;i<T;i++)
		{
			System.out.println("Case #"+(i+1)+": "+res[i]);
		}
		*/
	}
}
