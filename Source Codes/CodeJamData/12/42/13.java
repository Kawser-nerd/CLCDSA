import java.util.*;
import java.awt.*;
import java.math.*;

public class B
{
	public static Comparator<Thing> cmp1 = new Comparator<Thing>()
	{
		public int compare(Thing a, Thing b)
		{
			if(a.r > b.r) return -1;
			if(a.r == b.r) return 0;
			return 1;
		}
	};

	public static Comparator<Thing> cmp2 = new Comparator<Thing>()
	{
		public int compare(Thing a, Thing b)
		{
			return a.idx - b.idx;
		}
	};

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		Random rnd = new Random();


		for(int ca=1;ca <= T;ca++)
		{
			int n = scan.nextInt();
			double W = scan.nextDouble();
			double L = scan.nextDouble();

			Thing[] a = new Thing[n];

			for(int i=0;i < n;i++)
				a[i] = new Thing(i, scan.nextDouble());

			Arrays.sort(a, cmp1);

			int TRIALS = 10000;

			while(true)
			{
				//Collections.shuffle(r);
				boolean good = true;

				for(int i=0;i < n;i++) //Throw 'em somewhere
				{
					for(int j=0;j < TRIALS;j++)
					{
						a[i].x = rnd.nextDouble()*W;
						a[i].y = rnd.nextDouble()*L;

						//Sufficient?
						good = true;
						for(int k=0;k < i;k++)
						{
							if(Math.hypot(a[i].x -a[k].x, a[i].y - a[k].y) < a[i].r + a[k].r)
							{
								good = false;
								break;
							}
						}

						if(good) break;
					}

					if(!good)
						break;
				}

				//Check goodness once again
				for(int i=0;i < n;i++)
				for(int j=i+1;j < n;j++)
				{
					if(Math.hypot(a[i].x -a[j].x, a[i].y - a[j].y) < a[i].r + a[j].r)
						good = false;

				}

				if(good)
				{
					Arrays.sort(a, cmp2);
					System.out.print("Case #" + ca + ":");
					for(int i=0;i < n;i++)
						System.out.printf(" %.6f %.6f", a[i].x, a[i].y);
					System.out.println();
					break;
				}
			}
		}
	}
}



class Thing
{
	int idx;
		double r;
	double x, y;

	public Thing(int ii, double ir)
	{
		idx = ii;
		r = ir;
		x = 0;
		y = 0;
	}
}