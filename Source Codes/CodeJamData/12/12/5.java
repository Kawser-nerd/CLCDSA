import java.util.*;
import static java.lang.Math.*;

public class B {
	static void p(Object ...o) { System.out.println(Arrays.deepToString(o));}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			int N = in.nextInt();
			int[] A = new int[N];
			int[] B = new int[N];
			
			for (int i = 0; i < N; i++) {
				A[i] = in.nextInt();
				B[i] = in.nextInt();
			}
			
			int[] have = new int[N];
			int stars = 0;
			int ans = 0;
			next:
			while (stars < 2*N) {
				int best = -1;
				for (int i = 0; i < N; i++) {
					if (have[i] == 2)
						continue;
					if (stars >= B[i]) {
						stars += 2-have[i];
						have[i] = 2;
						ans++;
						continue next;
					}
					if (have[i] == 1)
						continue;
					if (stars < A[i])
						continue;
					if (best == -1 || B[i] > B[best]) {
						best = i;
					}
				}
				if (best == -1)
					break;
				have[best] = 1;
				ans++;
				stars++;
			}
			
			if (stars == 2*N)
				System.out.format("Case #%d: %d\n", zz, ans);
			else
				System.out.format("Case #%d: Too Bad\n", zz, ans);
		}
	}
}
