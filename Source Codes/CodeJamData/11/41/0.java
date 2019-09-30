import java.util.*;
import java.io.*;

public class Solution {
	class Road implements Comparable<Road> {
		int add;
		int len;
		public Road(int len, int add) {
			this.len = len;
			this.add = add;
		}
		public int compareTo(Road other) {
			return this.add - other.add;
		}
	}
	public void go() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			int X = sc.nextInt();
			int S = sc.nextInt();
			int R = sc.nextInt();
			double t = sc.nextInt();
			int N = sc.nextInt();
			Road[] r = new Road[N+1];
			for (int i=0; i < N; i++) {
				int B = sc.nextInt();
				int E = sc.nextInt();
				int w = sc.nextInt();
				r[i] = new Road(E - B, w);
				X -= r[i].len;
			}
			r[N] = new Road(X, 0);
			Arrays.sort(r);
			
			double res = 0.0;
			for (int i=0; i < r.length; i++) {
				double need = r[i].len / (double)(R + r[i].add);
				if (need < t) {
					t -= need;
					res += need;
				} else {
					double dist = r[i].len - (R + r[i].add) * t;
					res += t;
					t = 0;
					res += dist / (double)(S + r[i].add);
				}
			}
			
			pw.println("Case #" + caseNum + ": " + res);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}
