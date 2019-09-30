package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;


public class Deer {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;
	
	static Integer nextInt() throws Exception {
		if (st == null || !st.hasMoreElements()) {
			String s = in.readLine();
			if (s == null) return null;
			st = new StringTokenizer(s);
		}
		return parseInt(st.nextToken());
	}
	
	static class Line implements Comparable<Line> {
		int y; long time; long fin;
		
		Line(int y, long time) {
			this.y = y;
			this.time = time;
			fin = time * (360-y);
		}
		
		public int compareTo(Line o) {
			if (o.y == y) {
				if (time - o.time > 0) return -1;
				return 1;
			}
			return y - o.y;
		}
		
		public String toString() {
			return String.format("(%d, %d, %d)", y, time, fin);
		}
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader(new File("src/codejam2015/c.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/c.out")));
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int N = nextInt();
			TreeSet<Line> hikers = new TreeSet<Line>();
			for (int i = 0; i < N; i++) {
				int D = nextInt(), H = nextInt(), M = nextInt();
				for (long j = 0; j < H; j++) {
					hikers.add(new Line(D, (long) M+j));
				}
			}
			
			int ans = hikers.size();
			int passedcnt = 0;
			TreeSet<Long> passed = new TreeSet<>();
			for (Line x : hikers) {
				long finish = 1000000*x.fin;
				int res = passedcnt - 2*passed.headSet(finish).size();
				for (Line y : hikers) {
					if (res >= ans) break;
					if (x == y) continue;
					if (y.fin == x.fin) {
						if (y.time < x.time) res++;
					} else if (y.fin > x.fin) {
						if (y.y > x.y) res++;
					} else {
						if (y.y < x.y) res++;
						long i = y.fin + y.time*360;
						while (i <= x.fin) {
							res++;
							if (res >= ans) break;
							i += y.time*360;
						}
					}
				}
				ans = Math.min(ans, res);
				int i = 1;
				while (!passed.add(finish-i)) i++;
				passedcnt++;
			}
			
			//System.out.println(passed);
			//System.out.println(hikers);
			
			out.printf("Case #%d: %s\n", t+1, ans);
		}
		
		in.close();
		out.close();
	}
}
