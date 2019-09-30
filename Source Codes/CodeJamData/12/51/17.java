import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.*;

public class A
{
	public static Comparator<Point> cmp = new Comparator<Point>()
	{
		public int compare(Point a, Point b)
		{
			if(a.y > b.y) return -1;
			if(a.y < b.y) return 1;
			return a.x - b.x;
		}
	};

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			int n = scan.nextInt();
			for(int i=0;i < n;i++) scan.nextInt(); //Toss 1's
			Point[] a = new Point[n];
			for(int i=0;i < n;i++) a[i] = new Point(i, scan.nextInt());

			Arrays.sort(a,cmp);

			System.out.print("Case #" + ca + ":");

			for(int i=0;i < n;i++)
				System.out.print(" " + a[i].x);
			System.out.println();
		}
	}
}