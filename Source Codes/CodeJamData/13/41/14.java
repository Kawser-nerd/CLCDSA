package r2_2013;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class A {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt(), m = in.nextInt();
			BigInteger shouldPay = BigInteger.ZERO;
			int[][] a = new int[m][];
			int[][] b = new int[m][];
			for (int i = 0; i < m; i++) {
				int e = in.nextInt(), o = in.nextInt(), p = in.nextInt();
				long cost = 1L*(n + n - (o - e - 1))*(o - e)/2;
				shouldPay = shouldPay.add(new BigInteger(cost+"").multiply(new BigInteger(p+"")));
				a[i] = new int[]{e, p};
				b[i] = new int[]{o, p};
			}
			Arrays.sort(a, new Comparator<int[]>(){
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			Arrays.sort(b, new Comparator<int[]>(){
				public int compare(int[] a, int[] b) {
					return a[0] - b[0];
				}
			});
			
			BigInteger pay = BigInteger.ZERO;
			SortedMap<Integer, Long> map = new TreeMap<Integer, Long>();
			int pa = 0, pb = 0;
			while (true) {
				//System.err.println(pa + " " + pb + " " + map);
				if (pa >= m && pb >= m) break;
				if (pa >= m || a[pa][0] > b[pb][0]) {
					int x = b[pb][1], r = b[pb][0];
					while (x > 0) {
						int q = map.lastKey();
						int cnt = (int)Math.min(x, map.get(q));
						long cost = 1L*(n + n - (r - q - 1))*(r - q)/2;
						pay = pay.add(new BigInteger(cost+"").multiply(new BigInteger(cnt+"")));
						x -= cnt;
						map.put(q, map.get(q) - cnt);
						if (map.get(q) == 0) map.remove(q);
					}
					pb++;
				}
				else {
					if (!map.containsKey(a[pa][0])) map.put(a[pa][0], 1L*a[pa][1]);
					else map.put(a[pa][0], map.get(a[pa][0]) + a[pa][1]);
					pa++;
				}
			}
			
			out.println(shouldPay.subtract(pay).mod(new BigInteger("1000002013")));
		}
		
		out.flush();
	}

}
