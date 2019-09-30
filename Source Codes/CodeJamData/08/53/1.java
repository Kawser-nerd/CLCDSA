import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	static final int[] di = {-1, 0, 0, -1}, dj = {-1, -1, 1, 1};
	void run() {
		Scanner sc = new Scanner(System.in);
		int on = sc.nextInt();
		for (int o = 1; o <= on; o++) {
			System.out.printf("Case #%d: ", o);
			int n = sc.nextInt(), m = sc.nextInt();
			char[][] cs = new char[n][];
			for (int i = 0; i < n; i++) cs[i] = sc.next().toCharArray();
			int num = 0;
			Vertex[] vs = new Vertex[n * m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					vs[i * m + j] = new Vertex();
					if (cs[i][j] == '.') {
						num++;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) if (cs[i][j] == '.') {
					for (int k = 0; k < 4; k++) {
						int ii = i + di[k], jj = j + dj[k];
						if (0 <= ii && ii < n && 0 <= jj && jj < m && cs[ii][jj] == '.') vs[i * m + j].connect(vs[ii * m + jj]);
					}
				}
			}
			System.out.println(num - hopcroftKarp(vs));
		}
	}
	int hopcroftKarp(Vertex[] vs) {
		for (int match = 0;;) {
			Queue<Vertex> que = new LinkedList<Vertex>();
			for (Vertex v : vs) v.level = -1;
			for (Vertex v : vs) if (v.pair == null) {
				v.level = 0;
				que.offer(v);
			}
			while (!que.isEmpty()) {
				Vertex v = que.poll();
				for (Vertex u : v.es) {
					Vertex w = u.pair;
					if (w != null && w.level < 0) {
    					w.level = v.level + 1;
    					que.offer(w);
					}
				}
			}
			for (Vertex v : vs) v.used = false;
			int d = 0;
			for (Vertex v : vs) if (v.pair == null && dfs(v)) d++;
			if (d == 0) return match;
			match += d;
		}
	}
	boolean dfs(Vertex v) {
		v.used = true;
		for (Vertex u : v.es) {
			Vertex w = u.pair;
			if (w == null || !w.used && v.level < w.level && dfs(w)) {
				v.pair = u;
				u.pair = v;
				return true;
			}
		}
		return false;
	}
	class Vertex {
		ArrayList<Vertex> es = new ArrayList<Vertex>();
		Vertex pair;
		int level;
		boolean used;
		void connect(Vertex v) {
			es.add(v);
			v.es.add(this);
		}
	}
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
}
