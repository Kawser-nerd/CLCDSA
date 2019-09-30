import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class C {
    char[][] a;

    class State {
	int x, y;
	State prev;
	String add;
	int res;
	int len;

	public State(int x, int y, State prev, String add, int res) {
	    this.x = x;
	    this.y = y;
	    this.prev = prev;
	    this.add = add;
	    this.res = res;
	    if (prev == null) {
		len = add.length();
	    } else {
		len = prev.len + add.length();
	    }
	}

	@Override
	public String toString() {
	    return add + (prev != null ? prev : "");
	}
    }

    int[] DX = { -1, 1, 0, 0 };
    int[] DY = { 0, 0, -1, 1, };

    boolean in(int x, int y) {
	return (0 <= x && x < a.length && 0 <= y && y < a[0].length);
    }

    HashMap<Integer, State>[][] m;

    @SuppressWarnings("unchecked")
    void calc() {
	Queue<State> q = new LinkedList<State>();
	for (int i = 0; i < a.length; i++) {
	    for (int j = 0; j < a.length; j++) {
		if (!Character.isDigit(a[i][j])) {
		    q.add(new State(i, j, null, "", 0));
		}
	    }
	}
	m = new HashMap[a.length][a.length];
	for (int i = 0; i < m.length; i++) {
	    for (int j = 0; j < m.length; j++) {
		m[i][j] = new HashMap<Integer, State>();
	    }
	}
	int bestlen = 500;// TODO
	int cnt = 0;
	while (!q.isEmpty()) {
	    State s = q.poll();
	    cnt++;
	    for (int d1 = 0; d1 < DX.length; d1++) {
		if (!in(s.x + DX[d1], s.y + DY[d1])) {
		    continue;
		}
		int cur = a[s.x + DX[d1]][s.y + DY[d1]] - '0' + s.res;
		if (cur > 0 && cur <= 250 && qr[cur]) {
		    qr[cur] = false;
		    qrc--;
		}
		if (cur > 0 && cur <= 250 && qr2[cur]) {
		    State ns = new State(s.x + DX[d1], s.y + DY[d1], s, ""
			    + a[s.x + DX[d1]][s.y + DY[d1]], cur);
		    if (better(ns, m[s.x + DX[d1]][s.y + DY[d1]].get(cur))) {
			m[s.x + DX[d1]][s.y + DY[d1]].put(cur, ns);
		    }
		}
	    }
	    if (qrc <= 0) {
		bestlen = Math.min(bestlen, s.len + 1);
		continue;
	    }
	    if (s.len > bestlen) {
		break;
	    }
	    // System.err.println(s);

	    for (int d1 = 0; d1 < DX.length; d1++) {
		if (!in(s.x + DX[d1], s.y + DY[d1])) {
		    continue;
		}

		char a1 = a[s.x + DX[d1]][s.y + DY[d1]];
		for (int d2 = 0; d2 < DX.length; d2++) {
		    if (!in(s.x + DX[d1] + DX[d2], s.y + DY[d1] + DY[d2])) {
			continue;
		    }
		    int nx = s.x + DX[d1] + DX[d2];
		    int ny = s.y + DY[d1] + DY[d2];
		    char a2 = a[s.x + DX[d1] + DX[d2]][s.y + DY[d1] + DY[d2]];
		    int nres = ((a2 == '+') ? 1 : -1) * (a1 - '0') + s.res;
		    // System.err.println(nres + " = " + a2 + " " + a1 + " "
		    // + s.res);
		    State n = new State(nx, ny, s, "" + a2 + a1, nres);
		    if (!m[nx][ny].containsKey(nres)
			    || better(n, m[nx][ny].get(nres))) {
			m[nx][ny].put(nres, n);
			q.add(n);
		    }
		}
	    }
	}
	System.err.println("cnt = " + cnt);
    }

    boolean better(State s1, State s2) {
	if (s2 == null)
	    return true;
	if (s1.len < s2.len) {
	    return true;
	}
	if (s1.len > s2.len) {
	    return false;
	}
	int r = s1.add.compareTo(s2.add);
	if (r < 0)
	    return true;
	if (r > 0)
	    return false;
	if (s1.prev == null)
	    return false;
	return better(s1.prev, s2.prev);
    }

    boolean[] qr;
    boolean[] qr2;
    int qrc;

    void test() throws IOException {
	int w = nextInt();
	int qq = nextInt();
	a = new char[w][];
	for (int i = 0; i < w; i++) {
	    a[i] = br.readLine().toCharArray();
	}
	int[] t = new int[qq];
	qr = new boolean[300];
	qr2 = new boolean[300];
	for (int i = 0; i < qq; i++) {
	    t[i] = nextInt();
	    qr[t[i]] = true;
	    qr2[t[i]] = true;
	}
	qrc = 0;
	for (int i = 0; i < qr.length; i++) {
	    if (qr[i])
		qrc++;
	}
	calc();
	for (int itt = 0; itt < t.length; itt++) {
	    State ans = null;
	    for (int i = 0; i < a.length; i++) {
		for (int j = 0; j < a.length; j++) {
		    if (!Character.isDigit(a[i][j]))
			continue;
		    // System.err.println(m[i][j]);
		    if (m[i][j].containsKey(t[itt])) {
			if (ans == null || better(m[i][j].get(t[itt]), ans)) {
			    ans = m[i][j].get(t[itt]);
			}
		    }
		}
	    }
	    out.println(ans);

	}

    }

    long time;

    private void solve() throws IOException {
	time = System.currentTimeMillis();
	int n = nextInt();
	for (int i = 0; i < n; i++) {
	    out.println("Case #" + (i + 1) + ":");
	    System.err.println("Case #" + (i + 1) + ":");
	    test();
	    System.err.println(System.currentTimeMillis() - time);
	}
    }

    PrintWriter out;
    BufferedReader br;
    StringTokenizer st;

    private void run() {
	try {
	    // br = new BufferedReader(new FileReader("C-small-attempt1.in"));
	    // out = new PrintWriter("C-small-attempt1.out");
	    br = new BufferedReader(new FileReader("C-large.in"));
	    out = new PrintWriter("C-large.out");
	    solve();
	    out.close();
	} catch (IOException e) {
	    e.printStackTrace();
	    System.exit(1);
	}
    }

    String nextToken() {
	try {
	    while (st == null || !st.hasMoreTokens()) {
		st = new StringTokenizer(br.readLine());
	    }
	    return st.nextToken();
	} catch (IOException e) {
	    return "";
	}
    }

    int nextInt() {
	return Integer.parseInt(nextToken());
    }

    public static void main(String[] args) {
	new C().run();
    }
}
