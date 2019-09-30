import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;


public class GCJ_2013_C3 {

	public static class Attack {
		long day;
		long beg;
		long end;
		long strength;
	}
	
	public static int simday(TreeMap<Long,Long> wall, Set<Attack> attacks) {
	
		int attackSuccess = 0;
		HashSet<Attack> succ = new HashSet<Attack>();
		
		
		for (Attack a : attacks)
		{

			long ib = a.beg;
			long ie = a.end;
			boolean broke = false;
			while (ib < ie)
			{
				long jb = wall.floorKey(ib);
				long wh = wall.get(jb);
				if (wh < a.strength)
					broke = true;
				ib = wall.higherKey(ib);
			}
			if (broke)
			{
				attackSuccess ++;
				succ.add(a);
			}
		}
		
		for (Attack a : succ)
			{

				long ib = a.beg;
				long ie = a.end;

				while (ib<ie)
				{
					long ivs = wall.floorKey(ib);
					if (ivs != ib)
						wall.put(ib, wall.get(ivs));
					else if (wall.higherKey(ivs) > ie)
					{
						wall.put(ie, wall.get(ivs));
					}
					else
					{
						if (wall.get(ivs) < a.strength)
						{
							wall.put(ivs, a.strength);
							if (wall.get(wall.lowerKey(ivs)) == a.strength)
							{
								wall.remove(ivs);
							}
							if (wall.get(wall.higherKey(ivs)) == a.strength)
								wall.remove(wall.higherKey(ivs));
						}
						ib = wall.higherKey(ib);
					}
				}
/*				for(Entry<Long, Long> entry : wall.entrySet()) {
					  System.out.printf(" %d:%d ",entry.getKey(),entry.getValue());
				}
				System.out.println();*/
		}
		
		return attackSuccess;
	}
	
	public static void main(String[] args) throws Exception {
//		String fname = "C_example";
//		String fname = "C_small";
		String fname = "C_large";
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
	
	
		int T = scanner.nextInt();
			
		for (int i=1;i<=T;i++)
		{
			System.out.printf(" *** %d\n",i);
			TreeMap<Long, HashSet<Attack> > attacks = new TreeMap<Long, HashSet<Attack> >();
			
			int tribeNum = scanner.nextInt();
			
			for (int j=0;j<tribeNum;j++)
			{
				int d0 = scanner.nextInt();
				int n = scanner.nextInt();
				long beg0 = scanner.nextLong();
				long end0 = scanner.nextLong();
				long s0 = scanner.nextLong();
				long dd = scanner.nextLong();
				long dp = scanner.nextLong();
				long ds = scanner.nextLong();
				for (int k=0;k<n;k++)
				{
					Attack a = new Attack();
					a.beg = beg0 + k*dp;
					a.end = end0 + k*dp;
					a.strength = s0 + k*ds;
					long d = d0 + k*dd;
					HashSet<Attack> aset = attacks.get(d);
					if (aset == null)
					{
						attacks.put(d, new HashSet<Attack>());
						aset = attacks.get(d);
					}
					aset.add(a);
				}
			}
			
			long res = 0;
			
			TreeMap<Long,Long> wall = new TreeMap<Long,Long>();
			wall.put(-99999999999999999l, 0l);
			wall.put(99999999999999999l, 0l);
			
			long d = attacks.firstKey();
			while (attacks.containsKey(d))
			{
//				System.out.printf("simday: %d\n",d);
				res += simday(wall, attacks.get(d));
				if (attacks.higherKey(d) != null)
					d = attacks.higherKey(d);
				else
					d = d+1;
			}
			
			outp.printf("Case #%d: %s\n",i,res);
		}
		
		outp.close();

	}

}