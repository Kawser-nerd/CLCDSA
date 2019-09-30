import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	boolean TIME = true;
	Scanner sc;
	
	int M = 10007;
	
	void solve() {
		int n = sc.nextInt(), m = sc.nextInt();
		char[][] cs = new char[n][m];
		for (int i = 0; i < n; i++) {
			cs[i] = sc.next().toCharArray();
		}
		Map<String, Integer> crt = new HashMap<String, Integer>();
		String s = "";
		for (int i = 0; i < m; i++) s += "a";
		crt.put(s, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				Map<String, Integer> next = new HashMap<String, Integer>();
				for (Map.Entry<String, Integer> e : crt.entrySet()) {
					s = e.getKey();
					char[] ch = s.toCharArray();
					if (cs[i][j] == '.') {
						for (char c = j == 0 ? ch[j] : (char)max(ch[j], ch[j - 1]); c <= 'z'; c++) {
							ch[j] = c;
							add(next, String.valueOf(ch), e.getValue());
						}
					} else {
						if (cs[i][j] >= ch[j] && (j == 0 || cs[i][j] >= ch[j - 1])) {
							ch[j] = cs[i][j];
							add(next, String.valueOf(ch), e.getValue());
						}
					}
				}
				crt = next;
//				debug(crt);
			}
		}
		int res = 0;
		for (int i : crt.values()) res = (res + i) % M;
		System.out.println(res);
	}
	
	void add(Map<String, Integer> map, String s, int v) {
		Integer u = map.get(s);
		if (u == null) map.put(s, v);
		else map.put(s, (u + v) % M);
	}
	
	long comb(long n, long r) {
		if (n < r * 2) r = n - r;
		long res = 1;
		for (long i = 1; i <= r; i++) {
			res = res * (n - r + i) / i;
		}
		return res;
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (TIME) System.err.printf("%03d/%03d %.3f/%.3f%n", o, on, t, t / (o - 1) * on);
			System.out.printf("Case #%d: ", o);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
