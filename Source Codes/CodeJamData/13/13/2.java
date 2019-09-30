import java.math.BigInteger;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		
		
		for (int t = 1; t <= T; t++) {
			int R = in.nextInt();
			int N = in.nextInt();
			int M = in.nextInt();
			int K = in.nextInt();
			
			HashMap<String, HashSet<Integer>> hm = new HashMap<String, HashSet<Integer>>();
			for (int a = 2; a <= 5; a++) {
				for (int b = 2; b <= 5; b++) {
					for (int c = 2; c <= 5; c++) {
						String name = a+""+b+""+c+"";
						HashSet<Integer> subs = new HashSet<Integer>();
						subs.add(1);
						subs.add(a);
						subs.add(b);
						subs.add(c);
						subs.add(a*b);
						subs.add(a*c);
						subs.add(b*c);
						subs.add(a*b*c);
						hm.put(name, subs);
					}
				}
			}
			
			System.out.format("Case #%d:\n", t);
			for (int r = 0; r < R; r++) {
				int[] P = new int[K];
				for (int k = 0; k < K; k++)
					P[k] = in.nextInt();
				
				boolean printed = false;
				for (String key : hm.keySet()) {
					HashSet<Integer> all = hm.get(key);
					boolean legal = true;
					for (int p:P)
						if (!all.contains(p))
							legal = false;
					if (legal) {
						System.out.println(key);
						printed = true;
						break;
					}
				}
				if (!printed) {
					System.out.println("222");
				}
			}
		}
	}
}
