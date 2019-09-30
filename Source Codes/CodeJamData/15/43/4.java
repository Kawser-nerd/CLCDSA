import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.io.IOException;
import java.io.Reader;
import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Random;
import java.io.BufferedReader;
import java.util.Map;
import java.io.PrintStream;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		Bilingual solver = new Bilingual();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Bilingual {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println(testNumber);
        String line = in.readLine();
        while (line.isEmpty()) line = in.readLine();
        int n = Integer.parseInt(line);
        Map<String, Integer> q = new HashMap<>();
        int[][] f = new int[n][];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            List<Integer> z = new ArrayList<>();
            while (st.hasMoreTokens()) {
                String word = st.nextToken();
                Integer got = q.get(word);
                if (got == null) got = q.size();
                q.put(word, got);
                z.add(got);
            }
            f[i] = ArrayUtils.toPrimitiveArrayInteger(z);
        }
        int words = q.size();
        DinicGraph g = new DinicGraph(words * 2 + 2);
        int src = words * 2;
        int tar = src + 1;
        for (int i = 0; i < words; i++) g.addEdge(i, i + words, 1);
        final int INF = 300;
        for (int i : f[0]) {
            g.addEdge(src, i, INF);
        }
        for (int i : f[1]) {
            g.addEdge(i + words, tar, INF);
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < f[i].length; j++) {
                for (int k = j + 1; k < f[i].length; k++) {
                    g.addEdge(f[i][j] + words, f[i][k], INF);
                    g.addEdge(f[i][k] + words, f[i][j], INF);
                }
            }
        }
        out.println("Case #" + testNumber + ": " + g.getMaxFlow(src, tar));
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

}

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }


}

class ArrayUtils {


    static public int[] toPrimitiveArrayInteger(List<Integer> list) {
        int[] ret = new int[list.size()];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }


}

class DinicGraph {

    public static class Edge {
        public int from;
        public int to;
        public int flow;
        public int cap;
        public Edge rev;

        public Edge(int from, int to, int flow, int cap) {
            super();
            this.from = from;
            this.to = to;
            this.flow = flow;
            this.cap = cap;
        }

    }

    public ArrayList<Edge>[] edges;
    int[] cur;
    int[] q;
    public int[] d;
    int n;

    public DinicGraph(int n) {
        edges = new ArrayList[n];
        this.n = n;
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new ArrayList<Edge>();
        }
        q = new int[n];
        d = new int[n];
        cur = new int[n];
    }

    public Edge addEdge(int from, int to, int cap) {
        Edge e1 = new Edge(from, to, 0, cap);
        Edge e2 = new Edge(to, from, 0, 0);
        e1.rev = e2;
        e2.rev = e1;
        edges[from].add(e1);
        edges[to].add(e2);
        return e1;
    }

    boolean bfs(int source, int target) {
        int head = 0;
        int tail = 1;
        Arrays.fill(d, Integer.MAX_VALUE);
        d[source] = 0;
        q[0] = source;
        while (head < tail) {
            int x = q[head++];
            for (int i = 0; i < edges[x].size(); i++) {
                Edge e = edges[x].get(i);
                if (e.cap - e.flow > 0 && d[e.to] == Integer.MAX_VALUE) {
                    d[e.to] = d[x] + 1;
                    q[tail++] = e.to;
                    if (e.to == target) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public int dfs(int x, int target, int cMin) {
        if (x == target) {
            return cMin;
        }
        for (int i = cur[x]; i < edges[x].size(); cur[x] = ++i) {
            Edge e = edges[x].get(i);
            if (d[e.to] != d[x] + 1 || e.cap - e.flow == 0) {
                continue;
            }
            int add = dfs(e.to, target, Math.min(cMin, e.cap - e.flow));
            if (add == 0) {
                continue;
            }
            e.flow += add;
            e.rev.flow -= add;
            return add;
        }
        return 0;
    }

    public long getMaxFlow(int source, int target) {
        long flow = 0;
        while (bfs(source, target)) {
            Arrays.fill(cur, 0);
            while (true) {
                int add = dfs(source, target, Integer.MAX_VALUE);
                if (add == 0) {
                    break;
                }
                flow += add;
            }
        }
        return flow;
    }


}

