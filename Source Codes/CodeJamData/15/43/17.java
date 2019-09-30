package gcj2015.round2;

import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.ArrayBlockingQueue;

public class C2 {
    private static final int INF1 = 100000000;
    private static final int INF2 = 100000;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            int n = in.nextInt();
            in.nextLine();
            String[][] sen = new String[n][];
            for (int i = 0; i < n ; i++) {
                sen[i] = in.nextLine().split(" ");
            }
            out.println(String.format("Case #%d: %d", cs, solve(sen)));
        }

        out.flush();
    }

    private static int solve(String[][] sen) {
        int n = sen.length;

        Map<String,Integer> wordToInt = new HashMap<>();
        for (String[] s : sen) {
            for (String word : s) {
                if (!wordToInt.containsKey(word)) {
                    wordToInt.put(word, wordToInt.size());
                }
            }
        }

        int[][] words = new int[n][];
        Set<Integer>[] wset = new HashSet[n];
        for (int i = 0; i < n ; i++) {
            wset[i] = new HashSet<>();
            words[i] = new int[sen[i].length];
            for (int j = 0; j < words[i].length ; j++) {
                words[i][j] = wordToInt.get(sen[i][j]);
                wset[i].add(words[i][j]);
            }
        }


        MaxFlowDinic flow = new MaxFlowDinic();
        int wn = wordToInt.size();
        int source = n + wn * 2;
        int sink = source+1;

        flow.init(sink+1);
        for (int i = 0 ; i < n ; i++) {
            flow.edge(source, i, (i == 1) ? INF1 : INF2);
            flow.edge(i, sink, (i == 0) ? INF1 : INF2);
        }
        for (int i = 0 ; i < wn ; i++) {
            flow.edge(n + i * 2, n + i * 2 + 1, 1);
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = i+1 ; j < n ; j++) {
                for (int wi : wset[i]) {
                    if (wset[j].contains(wi)) {
                        flow.edge(i, n + wi * 2, INF1);
                        flow.edge(n + wi * 2 + 1, j, INF1);
                        flow.edge(j, n + wi * 2, INF1);
                        flow.edge(n + wi * 2 + 1, i, INF1);
                    }
                }
            }
        }
        return flow.max_flow(source, sink) - INF2 * n;
    }



    static class MaxFlowDinic {
        public class Edge {
            int to;
            int cap;
            int rev;
            public Edge(int _to, int _cap, int _rev) {
                to = _to;
                cap = _cap;
                rev = _rev;
            }
        }
        public Map<Integer, List<Edge>> graph = new HashMap<Integer, List<Edge>>();
        public int[] level;
        public int[] itr;
        public void init(int size) {
            for (int i = 0 ; i < size ; i++) {
                graph.put(i, new ArrayList<Edge>());
            }
            level = new int[size];
            itr = new int[size];
        }
        public void edge(int from, int to, int cap) {
            graph.get(from).add(new Edge(to, cap, graph.get(to).size()));
            graph.get(to).add(new Edge(from, 0, graph.get(from).size() - 1));
        }
        public int dfs(int v, int t, int f) {
            if (v == t) return f;
            for (int i = itr[v] ; i < graph.get(v).size() ; i++) {
                itr[v] = i;
                Edge e = graph.get(v).get(i);
                if (e.cap > 0 && level[v] < level[e.to]) {
                    int d = dfs(e.to, t, Math.min(f, e.cap));
                    if (d > 0) {
                        e.cap -= d;
                        graph.get(e.to).get(e.rev).cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        public void bfs(int s) {
            Arrays.fill(level, -1);
            Queue<Integer> q = new ArrayBlockingQueue<Integer>(graph.size()+10);
            level[s] = 0;
            q.add(s);
            while (q.size() >= 1) {
                int v = q.poll();
                for (int i = 0; i < graph.get(v).size() ; i++) {
                    Edge e = graph.get(v).get(i);
                    if (e.cap > 0 && level[e.to] < 0) {
                        level[e.to] = level[v] + 1;
                        q.add(e.to);
                    }
                }
            }
        }

        public int max_flow(int s, int t) {
            int flow = 0;
            while (true) {
                bfs(s);
                if (level[t] < 0) {
                    return flow;
                }
                Arrays.fill(itr, 0);
                while (true) {
                    int f = dfs(s, t, Integer.MAX_VALUE);
                    if (f <= 0) {
                        break;
                    }
                    flow += f;
                }
            }
        }
    }

    static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}



