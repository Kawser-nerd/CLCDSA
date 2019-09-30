import java.util.*;
import java.io.*;

public class Main {
    private static IO io = new IO();

    public static void main(String[] args) {
        int n = io.nextInt();
        int g = io.nextInt();
        int e = io.nextInt();
        Dinic dinic = new Dinic(n+1);
        for (int i = 0; i < g; i++) {
            int girl = io.nextInt();
            dinic.addg(girl, n, 1);
        }
        for (int i = 0; i < e; i++) {
            int from = io.nextInt();
            int to = io.nextInt();
            dinic.add(from, to, 1);
        }

        dinic.calcFlow(0, n);
        System.out.println(dinic.getAns());
    }

    private static class Dinic {

        private List<ArrayList<int[]>> e = new ArrayList<>();
        private int iter[];
        private int level[];
        private int flow = 0;

        private Dinic(int v) {
            for (int i = 0; i < v; i++) e.add(new ArrayList<>());
            iter = new int[v];
            level = new int[v];
        }

        private void add(int from, int to, int cap) {
            e.get(from).add(new int[]{to, cap, e.get(to).size()});
            e.get(to).add(new int[]{from, cap, e.get(from).size() - 1});
        }

        private void addg(int from, int to, int cap) {
            e.get(from).add(new int[]{to, cap, e.get(to).size()});
            e.get(to).add(new int[]{from, 0, e.get(from).size() - 1});
        }

        private void bfs(int s) {
            Arrays.fill(level, -1);
            level[s] = 0;
            Deque<Integer> que = new ArrayDeque<>();
            que.offer(s);

            while (!que.isEmpty()) {
                int v = que.poll();
                int ways = e.get(v).size();
                for (int i = 0; i < ways; i++) {
                    int p[] = e.get(v).get(i);
                    int to = p[0];
                    int cap = p[1];
                    if (cap>0 && level[to]<0) {
                        level[to] = level[v] + 1;
                        que.offer(to);
                    }
                }
            }
        }

        private int dfs(int v, int t, int f) {
            if (v==t) return f;
            int ways = e.get(v).size();
            for (int i = iter[v]; i < ways; i++, iter[v]++) {
                int p[] = e.get(v).get(i);
                int to = p[0];
                int cap = p[1];
                int rev = p[2];
                if (cap>0 && level[v]<level[to]) {
                    int d = dfs(to, t, Math.min(f, cap));
                    if (d>0) {
                        e.get(v).get(i)[1] -= d;
                        e.get(to).get(rev)[1] += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        private void calcFlow(int s, int t) {
            int INF = 1145141919;
            while (true) {
                bfs(s);
                if (level[t]<0) return;
                Arrays.fill(iter, 0);
                int f;
                while ((f = dfs(s, t, INF)) > 0) flow += f;
            }
        }

        private int getAns() {
            return flow;
        }

    }
    
    private static class IO extends PrintWriter {
        private final InputStream in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        IO() {
            this(System.in);
        }

        IO(InputStream source) {
            super(System.out);
            this.in = source;
        }

        boolean hasNextByte() {
            if (ptr < buflen) return true;
            else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) return false;
            }
            return true;
        }
        int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }
        boolean isPrintableChar(int c) {return 33<=c &&c <=126;}
        void skipUnprintable() {while(hasNextByte() && !isPrintableChar(buffer[ptr]))ptr++;}
        boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) throw new NumberFormatException();
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) return minus ? -n : n;
                else throw new NumberFormatException();
                b = readByte();
            }
        }

        int nextInt() {
            long nl = nextLong();
            if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
            return (int) nl;
        }

        public void close() {
            super.close();
            try {
                in.close();
            } catch (IOException ignored) {
            }
        }
    }
}