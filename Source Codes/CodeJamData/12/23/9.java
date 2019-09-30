import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;


public class C {

	static Scanner in = new Scanner(System.in);

	int N = in.nextInt();
	long[] x = new long[N];
	
	Map<Long, Long> map = new HashMap<Long, Long>();

	long eval(long b) {
		long ans = 0;
		int i=0;
		while (b > 0) {
			if ((b&1) != 0) {
				ans += x[i];
			}
			++i;
			b/=2;
			if (i>=N) break;
		}
		return ans;
	}
	
	Set<Long> build(long b) {
		Set<Long> ans = new HashSet<Long>();
		int i=0;
		while (b > 0) {
			if ((b&1) != 0) {
				ans.add(x[i]);
			}
			++i;
			b/=2;
			if (i>=N) break;
		}
		return ans;
	}
	
	void print(Collection<Long> as) {
		boolean first = true;
		for (long i:as) {
			if (first) {
				first = false;
			} else {
				System.out.print(" ");
			}
			System.out.print(i);
		}
		System.out.println();
	}
	
	void solve() {
		int S = 0;
		for (int i=0; i<N; ++i) {
			x[i] = in.nextLong();
			S += x[i];
		}
		Random rand = new Random(123);
		int tries = 0;
		while (true) {
			long v = rand.nextLong();
			v &= 0xFFFFFFFFFFFFL;
			if (v < 0) continue;
			long e = eval(v);
			if (e == 0) continue;
			++tries;
			if ((tries%1000000) == 0) {
				System.err.println("Tried " + tries + " times");
			}
			if (map.containsKey(e)) {
				long w = map.get(e);
				if (w == v) continue;
				System.err.println("Got hit on " + v + " with sum " + e);
//				System.out.println(v+ " "+e+" "+w);
				Set<Long> A = build(v);
				Set<Long> B = build(w);
				A.removeAll(B);
				B.removeAll(build(v));
				print(A);
				print(B);
				return;
			} else {
				map.put(e, v);
			}
		}
	}
	
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (int i=1; i<=T; ++i) {
			System.out.println("Case #" + i + ":");
			new C().solve();
		}

	}

}
