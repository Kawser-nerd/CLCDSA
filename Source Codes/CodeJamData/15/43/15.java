import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static Map<String, Integer> wordDict;
    static List<Set<Integer>> sentences;
    static int[][] words;
    static long BOUND = (long) 1e9;

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            N = scan.nextInt();
            sentences = new ArrayList<>();
            wordDict = new HashMap<>();
            for (int i = 0; i < N; ++i) {
                Set<Integer> words = new HashSet<>();
                sentences.add(words);
                String[] temp = scan.next().split(" ");
                for (String s : temp) {
                    Integer index = wordDict.get(s);
                    if (index == null) {
                        index = wordDict.size();
                        wordDict.put(s, index);
                    }
                    words.add(index);
                }
            }
            int nw = wordDict.size();
            MaximumFlow mf = new MaximumFlow(0, 1, N + 2 * nw);
            for (int i = 0; i < nw; ++i) {
                mf.addEdge(N + i, N + i + nw, 1);
            }
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (i == j) {
                        continue;
                    }
                    Set<Integer> wi = sentences.get(i);
                    Set<Integer> wj = sentences.get(j);
                    for (Integer index : wj) {
                        if (wi.contains(index)) {
                            mf.addEdge(i, N + index, BOUND);
                            mf.addEdge(N + nw + index, j, BOUND);
                        }
                    }
                }
            }
            mf.execute();
            long res = mf.maxFlow;
            System.out.println(String.format("Case #%d: %d", taskIndex, res));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}

class MaximumFlow {
    static class Edge {
        public int from;
        public int to;
        public long capacity;
        public int next;

        public Edge(int from, int to, long capacity, int next) {
            this.from = from;
            this.to = to;
            this.capacity = capacity;
            this.next = next;
        }
    }

    public long maxFlow;

    public static long INF = (long) 1e16;

    private int s;
    private int t;
    private int N;
    private ArrayList<Edge> edges;
    private int edgeCount;
    private int[] next;
    private int[] queue;
    private long[] distance;
    private int[] pre;
    private boolean[] visited;

    public MaximumFlow(int s, int t, int N) {
        this.s = s;
        this.t = t;
        this.N = N;
        this.edges = new ArrayList<Edge>(N);
        this.next = new int[N];
        this.queue = new int[N];
        this.distance = new long[N];
        this.pre = new int[N];
        this.visited = new boolean[N];

        Arrays.fill(next, -1);
    }

    public void execute() {
        while (spfa()) {
            increase();
        }
    }

    public void addEdge(int from, int to, long capacity) {
        // System.out.println(from + " " + to + " " + capacity);
        add(from, to, capacity);
        add(to, from, 0);
    }

    private void add(int from, int to, long capacity) {
        edges.add(new Edge(from, to, capacity, next[from]));
        next[from] = edgeCount;
        edgeCount++;
    }

    private boolean spfa() {
        Arrays.fill(visited, false);
        Arrays.fill(distance, INF);
        Arrays.fill(pre, -1);

        int head = 0;
        int tail = 1;
        queue[head] = s;
        distance[s] = 0;
        visited[s] = true;

        while (head != tail) {
            int u = queue[head];
            for (int i = next[u]; i != -1; i = edges.get(i).next) {
                int v = edges.get(i).to;
                if (edges.get(i).capacity > 0 && distance[u] + 1 < distance[v]) {
                    distance[v] = distance[u] + 1;
                    pre[v] = i;
                    if (!visited[v]) {
                        visited[v] = true;
                        queue[tail++] = v;
                        if (tail == N) {
                            tail = 0;
                        }
                    }
                }
            }
            visited[u] = false;
            head++;
            if (head == N) {
                head = 0;
            }
        }
        return distance[t] != INF;
    }

    private void increase() {
        long delta = Long.MAX_VALUE;
        for (int i = pre[t]; i != -1; i = pre[edges.get(i).from]) {
            delta = Math.min(delta, edges.get(i).capacity);
        }
        maxFlow += delta;
        for (int i = pre[t]; i != -1; i = pre[edges.get(i).from]) {
            edges.get(i).capacity -= delta;
            edges.get(i ^ 1).capacity += delta;
        }
    }
}