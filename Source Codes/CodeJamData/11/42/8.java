import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz=1; zz <= T; zz++){
			R = in.nextInt();
			C = in.nextInt();
			int D = in.nextInt();
			long[][] B = new long[R][C];
			for(int r = 0; r < R;r++){
				String S = in.next();
				for(int c = 0; c < C;c++){
					B[r][c] = (S.charAt(c)-'0')*2;
				}
			}
			long[][] sum = new long[R][C];
			long[][] sumrdot = new long[R][C];
			long[][] sumcdot = new long[R][C];
			long[][] rdot = new long[R][C];
			long[][] cdot = new long[R][C];
			for(int r = 0; r < R; r++){
				for(int c = 0; c < C;c++){
					sum[r][c] = B[r][c] + v(sum, r-1, c)+v(sum, r, c-1)-v(sum, r-1, c-1);
					sumrdot[r][c] = B[r][c]*r + v(sumrdot, r-1, c) + v(sumrdot, r, c-1)-v(sumrdot, r-1, c-1);
					rdot[r][c] = B[r][c]*r;
					sumcdot[r][c] = B[r][c]*c + v(sumcdot, r-1, c) + v(sumcdot, r, c-1)-v(sumcdot, r-1, c-1);
					cdot[r][c] = B[r][c]*c;
				}
			}
			int ans = 0;
			for(int cr = 0; cr < R;cr++){
				for(int cc = 0; cc < C;cc++){
					for(int k = 3; ; k += 2){
						int r0 = cr - k/2;
						int c0 = cc - k/2;
						int r1 = cr + k/2;
						int c1 = cc + k/2;
						if(!v(r0, c0) || !v(r1, c1))
							break;
						long s = v(sum, B, r0, c0, r1, c1);
						long r = v(sumrdot, rdot, r0, c0, r1, c1) - s*cr;
						long c = v(sumcdot, cdot, r0, c0, r1, c1) - s*cc;
						if(r == 0 && c == 0){
							ans = max(ans, k);
						}
					}
				}
			}
			for(int cr = 0; cr < R-1;cr++){
				for(int cc = 0; cc < C-1;cc++){
					for(int k = 4; ; k += 2){
						int r0 = cr - k/2+1;
						int c0 = cc - k/2+1;
						int r1 = cr + k/2;
						int c1 = cc + k/2;
						if(!v(r0, c0) || !v(r1, c1))
							break;
						long s = v(sum, B, r0, c0, r1, c1);
						long r = v(sumrdot, rdot, r0, c0, r1, c1) - (s*cr + s/2);
						long c = v(sumcdot, cdot, r0, c0, r1, c1) - (s*cc + s/2);
						if(r == 0 && c == 0){
							ans = max(ans, k);
						}
					}
				}
			}
			String anss;
			if(ans >= 3)
				anss = ans+"";
			else
				anss = "IMPOSSIBLE";
			System.out.format("Case #%d: %s\n", zz, anss);
		}
	}
	private static long v(long[][] t, long[][] s, int r0, int c0, int r1, int c1) {
		long ans = v(t, r1, c1) - v(t, r0-1, c1) - v(t, r1, c0-1) + v(t, r0-1, c0-1);
		ans -= s[r1][c1];
		ans -= s[r1][c0];
		ans -= s[r0][c1];
		ans -= s[r0][c0];
		return ans;
	}
	private static boolean v(int r, int c) {
		return !(r < 0 || r >= R || c < 0 || c >= C);
	}
	static int R, C;
	private static long v(long[][] xsum, int r, int c) {
		if(r < 0 || r >= R || c < 0 || c >= C)
			return 0;
		return xsum[r][c];
	}
}
