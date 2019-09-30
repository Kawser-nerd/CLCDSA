package round3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class P1 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("round3/p1.in"));
		
		FileWriter out = new FileWriter("p1.out");
		
		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			
			int res = solveOne(br);
			System.out.println("Case #" + i + ": " + res);
			out.write("Case #" + i + ": " + res + "\n");
		}
		br.close();
		out.close();
	}

	private static int solveOne(BufferedReader br) throws Exception {
		int np = Integer.parseInt(br.readLine());
		String path = "";
		while (np>0) {
			String pp[] = br.readLine().split("\\s+");
			for (int i=0; i<pp.length; i+=2) {
				int n = Integer.parseInt(pp[i+1]);
				String x = pp[i];
				for (int j=0; j<n; j++)
					path += x;
				np--;
			}
		}
		int x=0, y=0, dx=0, dy=1;
		Map<Integer, Set<Integer>> cutX = new HashMap<Integer, Set<Integer>>();
		Map<Integer, Set<Integer>> cutY = new HashMap<Integer, Set<Integer>>();
		Set<Integer> points = new HashSet<Integer>();
		for (int i=0; i<path.length(); i++) {
			char c = path.charAt(i);
			if (c=='F') {
				if (dx==0) {
					addCut(cutX, y, x, dy);
				} else {
					addCut(cutY, x, y, dx);
				}
				x += dx;
				y += dy;
			} else if (c=='R') {
				int tmp = dy;
				dy = -dx;
				dx = tmp;
			} else {
				int tmp = dy;
				dy = dx;
				dx = -tmp;				
			}
		}
//		System.out.println(path);
		int KK = 10000;
		addPoints(points, 1, KK, cutX);
//		System.out.println(points);
		addPoints(points, KK, 1, cutY);
//		System.out.println(points);
		return points.size();
	}

	private static void addPoints(Set<Integer> points, int kx, int ky, Map<Integer, Set<Integer>> cutY) {
		for (Map.Entry<Integer, Set<Integer> > me : cutY.entrySet()) {
			int x = me.getKey();
//			System.out.println(x + " --> " + me.getValue());
			boolean in = false;
			Integer prev = null;
			for (Integer ix : me.getValue()) {
				in = !in;
				if (in==true && prev!=null) {
					for (int y = prev; y<ix; y++)
						points.add(kx*x + ky*y);
				}
				prev = ix;
			}
		}
	}

	private static void addCut(Map<Integer, Set<Integer>> cutX, int y, int x, int dy) {
		int y0 = y - ((dy==-1)?1:0);
		if (!cutX.containsKey(y0))
			cutX.put(y0, new TreeSet<Integer>());
		cutX.get(y0).add(x);
	}

}
