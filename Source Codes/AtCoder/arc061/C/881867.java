import java.io.IOException;
import java.io.InputStream;
import java.util.*;

public class Main {

    private static final int INF = (int) 1e+9 + 7;
    private static Map<Long, Integer> idMap = new HashMap<>();
    private static GraphL g = new GraphL();

    static long iToL(int fst, int snd) {
        return ((long) (fst) << 32) | (long) snd & 0xffffffffL;
    }
    static int getFst(long intPair) {
        return (int) (intPair >> 32);
    }
    static int getSnd(long intPair) {
        return (int) (intPair & 0xffffffffL);
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            int p = sc.nextInt();
            int q = sc.nextInt();
            int c = sc.nextInt();
            int p0Id = toId(p, 0);
            int q0Id = toId(q, 0);
            int pcId = toId(p, c);
            int qcId = toId(q, c);
            List<Long> p0 = g.getNext(p0Id);
            List<Long> q0 = g.getNext(q0Id);
            List<Long> pc = g.getNext(pcId);
            List<Long> qc = g.getNext(qcId);
            if (pc.isEmpty()) {
                p0.add(iToL(pcId, 1));
                pc.add(iToL(p0Id, 0));
            }
            pc.add(iToL(qcId, 0));
            if (qc.isEmpty()) {
                q0.add(iToL(qcId, 1));
                qc.add(iToL(q0Id, 0));
            }
            qc.add(iToL(pcId, 0));
//            g.addEdge(toId(p, c), toId(q, c), 0);
//            g.addEdge(toId(p, c), toId(p, 0), 0);
//            g.addEdge(toId(p, 0), toId(p, c), 1);
//            g.addEdge(toId(q, c), toId(q, 0), 0);
//            g.addEdge(toId(q, 0), toId(q, c), 1);
        }
        long ans = dijkstra(toId(1, 0), toId(n, 0));
        System.out.println(ans);
    }

    private static int toId(int fst, int snd) {
        long lid = iToL(fst, snd);
        Integer id = idMap.get(lid);
        if (id == null) {
            idMap.put(lid, id = idMap.size());
            g.assoc.add(new ArrayList<>());
        }
        return id;
    }

    private static long dijkstra(int s, int t) {
        // O(E*logV)
        int[] d = new int[idMap.size()];
        Arrays.fill(d, INF);
        d[s] = 0;
        Deque<Integer> q = new ArrayDeque<>();
        q.add(s);
        while (!q.isEmpty()) {
            int from = q.pollFirst();
            if (from == t) return d[t];
            for (long e : g.getNext(from)) {
                int to = getFst(e);
                int w = getSnd(e);
                if (d[to] > d[from] + w) {
                    d[to] = d[from] + w;
                    if (w == 0) q.addFirst(to);
                    else q.addLast(to);
                }
            }
        }
        return -1;
    }
}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int bufLen = 0;

    private boolean hasNextByte() {
        if (ptr < bufLen) {
            return true;
        } else {
            ptr = 0;
            try {
                bufLen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (bufLen <= 0) {
                return false;
            }
        }
        return true;
    }

    private int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    private boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    private String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    private long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}

class GraphL {
    List<List<Long>> assoc = new ArrayList<>();
    List<Long> getNext(int s) {
        return assoc.get(s);
    }
    void addEdge(int s, int t, int w) {
        assoc.get(s).add(Main.iToL(t, w));
    }
}