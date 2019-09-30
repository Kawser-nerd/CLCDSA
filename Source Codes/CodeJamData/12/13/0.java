import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int N;
	int[] side;
	int[] speed;
	int[] pos;
	
	void read() {
		N = sc.nextInt();
		side = new int[N];
		speed = new int[N];
		pos = new int[N];
		for (int i = 0; i < N; i++) {
			side[i] = sc.next().equals("L") ? 0 : 1;
			speed[i] = sc.nextInt();
			pos[i] = sc.nextInt();
		}
	}
	
	double EPS = 1e-10;
	
	boolean ok(double[] ts, int n) {
		V[] vs = new V[N * n * 2];
		for (int i = 0; i < vs.length; i++) vs[i] = new V();
		for (int i = 0; i < N; i++) {
			if (side[i] == 0) {
				vs[i * 2 + 1].add(vs[i * 2]);
			} else {
				vs[i * 2].add(vs[i * 2 + 1]);
			}
		}
		double[] ps = new double[N];
		for (int i = 0; i + 1 < n; i++) {
			double t = ts[i];
			for (int j = 0; j < N; j++) ps[j] = pos[j] + speed[j] * t;
			for (int j = 0; j < N; j++) {
				boolean ok = true;
				for (int k = 0; k < N; k++) if (ps[j] + EPS < ps[k] + 5 && ps[k] + EPS < ps[j] + 5) {
					if (j != k) ok = false;
				}
				if (!ok) {
					vs[i * N * 2 + j * 2].add(vs[(i + 1) * N * 2 + j * 2]);
					vs[(i + 1) * N * 2 + j * 2].add(vs[i * N * 2 + j * 2]);
					vs[i * N * 2 + j * 2 + 1].add(vs[(i + 1) * N * 2 + j * 2 + 1]);
					vs[(i + 1) * N * 2 + j * 2 + 1].add(vs[i * N * 2 + j * 2 + 1]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			double t = ts[i];
			for (int j = 0; j < N; j++) ps[j] = pos[j] + speed[j] * t;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < j; k++) if (ps[j] + EPS < ps[k] + 5 && ps[k] + EPS < ps[j] + 5) {
					vs[i * N * 2 + j * 2].add(vs[i * N * 2 + k * 2 + 1]);
					vs[i * N * 2 + j * 2 + 1].add(vs[i * N * 2 + k * 2]);
					vs[i * N * 2 + k * 2].add(vs[i * N * 2 + j * 2 + 1]);
					vs[i * N * 2 + k * 2 + 1].add(vs[i * N * 2 + j * 2]);
				}
			}
		}
		scc(vs);
		for (int i = 0; i < n; i++) for (int j = 0; j < N; j++) {
			if (vs[i * N * 2 + j * 2].comp == vs[i * N * 2 + j * 2 + 1].comp) return false;
		}
		return true;
	}
	
	void solve() {
		TreeSet<Double> set = new TreeSet<Double>();
		set.add(0.0);
		set.add(1e10);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (speed[i] < speed[j]) {
				double t = (double)(pos[i] - pos[j] + 5) / (speed[j] - speed[i]);
				if (t >= 0) set.add(t);
				t = (double)(pos[i] - pos[j] - 5) / (speed[j] - speed[i]);
				if (t >= 0) set.add(t);
			}
		}
		Double[] ds = set.toArray(new Double[0]);
		double[] ts = new double[ds.length * 2 - 1];
		for (int i = 0; i < ds.length; i++) ts[i * 2] = ds[i];
		for (int i = 0; i < ds.length - 1; i++) ts[i * 2 + 1] = (ds[i] + ds[i + 1]) / 2;
		if (ok(ts, ts.length)) System.out.println("Possible");
		else {
			int left = 0, right = ts.length;
			while ((right - left) > 1) {
				int mid = (left + right) / 2;
				if (ok(ts, mid)) left = mid;
				else right = mid;
			}
			System.out.printf("%.10f%n", ts[max(0, left - 1)]);
		}
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	int n;
	V[] us;
	int scc(V[] vs) {
		n = vs.length;
		us = new V[n];
		for (V v : vs) if (!v.visit) dfs(v);
		for (V v : vs) v.visit = false;
		for (V u : us) if (!u.visit) dfsrev(u, n++);
		return n;
	}
	void dfs(V v) {
		v.visit = true;
		for (V u : v.fs) if (!u.visit) dfs(u);
		us[--n] = v;
	}
	void dfsrev(V v, int k) {
		v.visit = true;
		for (V u : v.rs) if (!u.visit) dfsrev(u, k);
		v.comp = k;
	}
	int sccNonRec(V[] vs) {
		int n = vs.length;
		V[] us = new V[n];
		for (V v : vs) if (!v.visit) {
			while (v != null) {
				v.visit = true;
				if (v.p < v.fs.size()) {
					V u = v.fs.get(v.p++);
					if (!u.visit) {
						u.prev = v;
						v = u;
					}
				} else {
					us[--n] = v;
					v = v.prev;
				}
			}
		}
		for (V v : vs) {
			v.visit = false;
			v.p = 0;
			v.prev = null;
		}
		for (V v : us) if (!v.visit) {
			while (v != null) {
				v.visit = true;
				if (v.p < v.rs.size()) {
					V u = v.rs.get(v.p++);
					if (!u.visit) {
						u.prev = v;
						v = u;
					}
				} else {
					v.comp = n;
					v = v.prev;
				}
			}
			n++;
		}
		return n;
	}
	class V {
		ArrayList<V> fs = new ArrayList<V>(), rs = new ArrayList<V>();
		int comp, p;
		boolean visit;
		V prev;
		void add(V to) {
			fs.add(to);
			to.rs.add(this);
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
