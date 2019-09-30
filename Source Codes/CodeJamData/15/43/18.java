import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            sc.nextLine();
            Map<String, Set<Integer>> appearances = new HashMap<String, Set<Integer>>();
            for (int i = 0; i < N; i++) {
                String line = sc.nextLine();
                for (String word : line.split("\\s+")) {
                    if (!appearances.containsKey(word)) {
                        appearances.put(word, new HashSet<Integer>());
                    }
                    appearances.get(word).add(i);
                }
            }
            int numWords = appearances.size();
            PushRelabel pushRelabel = new PushRelabel(N + numWords * 2);
            int wordIndex = N;
            for (Map.Entry<String, Set<Integer>> entry : appearances.entrySet()) {
                pushRelabel.AddEdge(wordIndex, wordIndex + numWords, 1);
                for (Integer sentence : entry.getValue()) {
                    pushRelabel.AddEdge(sentence, wordIndex, 1);
                    pushRelabel.AddEdge(wordIndex + numWords, sentence, 1);
                }
                wordIndex++;
            }
            System.out.println("Case #" + caseNum + ": " + pushRelabel.GetMaxFlow(0, 1));
        }
    }

    private static class Edge {
        int from, to, cap, flow, index;

        public Edge(int from, int to, int cap, int flow, int index) {
            this.from = from;
            this.to = to;
            this.cap = cap;
            this.flow = flow;
            this.index = index;
        }
    }

    private static class PushRelabel {
        int N;
        List<Edge>[] G;
        long[] excess;
        boolean[] active;
        int[] dist, count;
        Queue<Integer> Q;

        PushRelabel(int N) {
            this.N = N;
            G = new List[N];
            for (int i = 0; i < N; i++) {
                G[i] = new ArrayList<Edge>();
            }
            excess = new long[N];
            dist = new int[N];
            active = new boolean[N];
            count = new int[2 * N];
            Q = new ArrayDeque<Integer>();
        }

        void AddEdge(int from, int to, int cap) {
            G[from].add(new Edge(from, to, cap, 0, G[to].size()));
            if (from == to) {
                G[from].get(G[from].size() - 1).index++;
            }
            G[to].add(new Edge(to, from, 0, 0, G[from].size() - 1));
        }

        void Enqueue(int v) {
            if (!active[v] && excess[v] > 0) {
                active[v] = true;
                Q.offer(v);
            }
        }

        void Push(Edge e) {
            int amt = (int) Math.min(excess[e.from], e.cap - e.flow);
            if (dist[e.from] <= dist[e.to] || amt == 0) {
                return;
            }
            e.flow += amt;
            G[e.to].get(e.index).flow -= amt;
            excess[e.to] += amt;
            excess[e.from] -= amt;
            Enqueue(e.to);
        }

        void Gap(int k) {
            for (int v = 0; v < N; v++) {
                if (dist[v] < k) {
                    continue;
                }
                count[dist[v]]--;
                dist[v] = Math.max(dist[v], N + 1);
                count[dist[v]]++;
                Enqueue(v);
            }
        }

        void Relabel(int v) {
            count[dist[v]]--;
            dist[v] = 2 * N;
            for (int i = 0; i < G[v].size(); i++) {
                if (G[v].get(i).cap - G[v].get(i).flow > 0) {
                    dist[v] = Math.min(dist[v], dist[G[v].get(i).to] + 1);
                }
            }
            count[dist[v]]++;
            Enqueue(v);
        }

        void Discharge(int v) {
            for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) {
                Push(G[v].get(i));
            }
            if (excess[v] > 0) {
                if (count[dist[v]] == 1) {
                    Gap(dist[v]);
                } else {
                    Relabel(v);
                }
            }
        }

        long GetMaxFlow(int s, int t) {
            count[0] = N - 1;
            count[N] = 1;
            dist[s] = N;
            active[s] = active[t] = true;
            for (int i = 0; i < G[s].size(); i++) {
                excess[s] += G[s].get(i).cap;
                Push(G[s].get(i));
            }

            while (!Q.isEmpty()) {
                int v = Q.poll();
                active[v] = false;
                Discharge(v);
            }

            long totflow = 0;
            for (int i = 0; i < G[s].size(); i++) {
                totflow += G[s].get(i).flow;
            }
            return totflow;
        }
    };
}
