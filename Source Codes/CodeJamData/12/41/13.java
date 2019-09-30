import java.util.*;
import java.awt.*;
import java.math.*;

public class A
{



	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			boolean rtn = false;
			int n = scan.nextInt();

			Point[] a = new Point[n];

			for(int i=0;i < n;i++)
			{
				a[i] = new Point(scan.nextInt(), scan.nextInt());
			}

			int d = scan.nextInt();


			int[] s = new int[n];
			s[0] = a[0].x;

			for(int i=0;i < n;i++)
			for(int j=i+1;j < n;j++)
			{
				if(a[j].x <= s[i] + a[i].x)
				{
					s[j] = Math.max(s[j], Math.min(a[j].x - a[i].x, a[j].y));
				}
			}

			for(int i=0;i < n;i++)
			{
				if(d <= a[i].x + s[i]) rtn = true;
			}


			System.out.println("Case #" + ca + ": " + (rtn ? "YES" : "NO"));
		}
	}
}