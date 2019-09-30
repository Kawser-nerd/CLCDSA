package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;
import static java.lang.Integer.*;


public class Noisy {
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
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader(new File("src/codejam2015/b.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/b.out")));
		
		int T = nextInt();
		for (int t = 0; t < T; t++) {
			
			int R = nextInt(), C = nextInt(), N = nextInt();
			
			int ans = 0;
			boolean odd = (R*C)%2 == 1;
			if (N <= (R*C+1)/2) {
				ans = 0;
			} else if (R == 1 || C == 1) {
				int diff = N - (R*C+1)/2;
				if (odd) ans++;
				ans++;
				diff--;
				while (diff > 0) {
					ans += 2;
					diff--;
				}
			} else if (N == (R*C+3)/2) {
				ans = odd ? 3 : 2;
			} else if (N == (R*C+5)/2) {
				ans = odd ? 6 : 4;
			} else {
				int walls = (R*C * 4 - 2*R - 2*C)/2;
				int diff = R*C - N;
				int inner = R*C - 2*R - 2*C + 4;
				if (diff <= (inner+1)/2) ans = walls - diff*4;
				else {
					ans = walls - (inner+1)/2*4;
					diff -= (inner+1)/2;
					if (!odd) {
						ans -= diff*3;
					} else {
						int outer = 2*R + 2*C - 4;
						if (diff <= outer/2-4) ans -= diff*3;
						else {
							ans -= (outer/2-4)*3;
							diff -= (outer/2-4);
							ans -= diff*2;
						}
					}
				}
			}
			
			out.printf("Case #%d: %s\n", t+1, ans);
		}
		
		in.close();
		out.close();
	}
}
