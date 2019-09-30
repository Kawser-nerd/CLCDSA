package round3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class P4 {
		public static void main(String[] args) throws Exception {
			BufferedReader br = new BufferedReader(new FileReader("round3/p4.in"));
			
			FileWriter out = new FileWriter("p4.out");
			
			int n = Integer.parseInt(br.readLine());
			for (int i=1; i<=n; i++) {
				
				int res = solveOne(br);
				System.out.println("Case #" + i + ": " + res);
				out.write("Case #" + i + ": " + res + "\n");
			}
			br.close();
			out.close();
		}

		private static final int KY = 1000;
		private static int H, W;
		private static Set<Integer> rooks;
		private static Map<Integer, Integer> cache;
		
		private static int solveOne(BufferedReader br) throws Exception {
			String p[] = br.readLine().split("\\s+");
			H = Integer.parseInt(p[0]);
			W = Integer.parseInt(p[1]);
			int R = Integer.parseInt(p[2]);
			rooks = new HashSet<Integer>();
			for (int i=0; i<R; i++) {
				String p2[] = br.readLine().split("\\s+");
				rooks.add((Integer.parseInt(p2[0])-1) * KY + (Integer.parseInt(p2[1])-1));				
			}
			cache = new HashMap<Integer, Integer>();
			return doIt(0, 0);
		}

		private static int doIt(int x, int y) {
			int key = x+KY*y;
			if (cache.containsKey(key))
				return cache.get(key);
			if (x>=W || y>=H)
				return 0;
			if (x==W-1 && y==H-1)
				return 1;
			if (rooks.contains(key)) 
				return 0;
			
			int ret = (doIt(x+1, y+2) + doIt(x+2, y+1)) % 10007;
			
			
			
			cache.put(key, ret);
			return ret;
		}

}
