import java.util.*;

public class C
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		final double EPS = 1e-14;

		int T = scan.nextInt();

		for(int ca=1;ca <= T;ca++)
		{
			int n = scan.nextInt();
			int[] a = new int[n];

			for(int i=0;i < n;i++)
				a[i] = scan.nextInt();

			HashMap<Integer, ArrayList<Integer>> h = new HashMap<Integer, ArrayList<Integer>>();

			for(int mask=1;mask < (1 << n);mask++)
			{
				int sum = 0;
				for(int i=0;i < n;i++)
					if((mask & (1 << i)) > 0) sum += a[i];

				ArrayList<Integer> al = h.get(sum);
				if(al == null)
				{
					al = new ArrayList<Integer>();
					h.put(sum, al);
				}

				al.add(mask);
			}

			Iterator<Integer> it = h.keySet().iterator();

			int mask1 = -1;
			int mask2 = -1;

			out:
			while(it.hasNext())
			{
				ArrayList<Integer> al = h.get(it.next());
				for(int i=0;i < al.size();i++)
				for(int j=i+1;j < al.size();j++)
				{
					int r1 = al.get(i) | al.get(j);
					int r2 = al.get(i) + al.get(j);

					if(r1 == r2)
					{
						mask1 = al.get(i);
						mask2 = al.get(j);
						break out;
					}
				}
			}

			System.out.println("Case #" + ca + ":");

			if(mask1 == -1) System.out.println("Impossible");
			else
			{
				boolean first = true;
				for(int i=0;i < n;i++)
				{
					if((mask1 & (1 << i)) == 0) continue;
					if(first) System.out.print(a[i]);
					else System.out.print(" " + a[i]);
					first = false;
				}
				System.out.println();

				first = true;
				for(int i=0;i < n;i++)
				{
					if((mask2 & (1 << i)) == 0) continue;
					if(first) System.out.print(a[i]);
					else System.out.print(" " + a[i]);
					first = false;
				}
				System.out.println();
			}
		}
	}
}