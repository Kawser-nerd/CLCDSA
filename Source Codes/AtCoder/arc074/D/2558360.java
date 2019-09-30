import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int h, w;
    char[][] css;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        h = sc.nextInt();
        w = sc.nextInt();
        css = new char[h][w];
        int sx = -1;
        int sy = -1;
        int tx = -2;
        int ty = -2;

        Dinic d = new Dinic(2 + h + w);
        for (int i = 0; i < h; i++) {
            css[i] = sc.next().toCharArray();
            for (int j = 0; j < w; j++) {
                if (css[i][j] == 'o') {
                    d.addUndirectedEdge(2 + i, 2 + h + j, 1);
                } else if (css[i][j] == 'S') {
                    d.addEdge(0, 2 + i, Integer.MAX_VALUE);
                    d.addEdge(0, 2 + h + j, Integer.MAX_VALUE);
                    sx = j;
                    sy = i;
                } else if (css[i][j] == 'T') {
                    d.addEdge(2 + i, 1, Integer.MAX_VALUE);
                    d.addEdge(2 + h + j, 1, Integer.MAX_VALUE);
                    tx = j;
                    ty = i;
                }
            }
        }
        if (sx == tx || sy == ty) {
            System.out.println(-1);
            return;
        }
        System.out.println(d.maximumFlow(0, 1));
    }

    public class Dinic {
        ArrayList<ArrayList<DinicEdge>> graph;
        // distances from s
        int[] levels;
        int[] iters;

        Dinic(int n) {
            graph = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }
            levels = new int[n];
            iters = new int[n];
            // manually add edges by using addEdge
        }

        void bfs(int s) {
            Arrays.fill(levels, -1);
            Queue<Integer> queue = new LinkedList<>();
            levels[s] = 0;
            queue.offer(s);
            while (!queue.isEmpty()) {
                int v = queue.poll();
                for (DinicEdge e : graph.get(v)) {
                    if (e.capacity > 0 && levels[e.to] < 0) {
                        levels[e.to] = levels[v] + 1;
                        queue.offer(e.to);
                    }
                }
            }
        }

        long dfs(int v, int t, long f) {
            if (v == t) {
                return f;
            }
            for (int i = iters[v]; i < graph.get(v).size(); i++) {
                DinicEdge e = graph.get(v).get(i);
                if (e.capacity > 0 && levels[v] < levels[e.to]) {
                    long d = dfs(e.to, t, Math.min(f, e.capacity));
                    if (d > 0) {
                        e.capacity -= d;
                        graph.get(e.to).get(e.reverse).capacity += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        long maximumFlow(int s, int t) {
            long flow = 0;
            while (true) {
                bfs(s);
                if (levels[t] < 0) {
                    return flow;
                }
                Arrays.fill(iters, 0);
                long f;
                while ((f = dfs(s, t, Long.MAX_VALUE)) > 0) {
                    flow += f;
                }
            }
        }

        void addUndirectedEdge(int from, int to, int capacity) {
            graph.get(from).add(new DinicEdge(to, capacity, graph.get(to).size()));
            graph.get(to).add(new DinicEdge(from, capacity, graph.get(from).size() - 1));
        }

        void addEdge(int from, int to, int capacity) {
            graph.get(from).add(new DinicEdge(to, capacity, graph.get(to).size()));
            graph.get(to).add(new DinicEdge(from, 0, graph.get(from).size() - 1));
        }
    }

    class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode() {
            return x << 16 + y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Pair) {
                Pair p = (Pair)obj;
                return this.x == p.x && this.y == p.y;
            } else {
                return false;
            }
        }
    }

    class DinicEdge {
        int to;
        int capacity;
        int reverse;

        DinicEdge(int to, int capacity, int reverse) {
            this.to = to;
            this.capacity = capacity;
            this.reverse = reverse;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}