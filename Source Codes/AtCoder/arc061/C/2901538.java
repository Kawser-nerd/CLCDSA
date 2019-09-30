import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int M;
    static Edge[] E;

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        E = new Edge[M];
        for (int i = 0; i < M; i++) {
            E[i] = new Edge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        }
        System.out.println(solve());
    }

    // company in station
    static class Company {
        int cost = INF;
        List<Edge> edges = new ArrayList<>();
    }

    static int INF = 1_000_000_007;

    static class Station {
        // int p;
        Map<Integer, Company> companies = new HashMap<>();

        int cost = INF;

        int cost(int c) {
            if( c == 0 ) {
                return cost;
            } else {
                return companies.get(c).cost;
            }
        }

        Company company(int c) {
            if( !companies.containsKey(c) ) {
                companies.put(c, new Company());
            }
            return companies.get(c);
        }
    }

    static class Edge {
        int p;
        int q;
        int c;

        public Edge(int p, int q, int c) {
            this.p = p;
            this.q = q;
            this.c = c;
        }

        int opposite(int x) {
            return x == p ? q : p;
        }
    }

    static class State {
        int station;
        int company;
        int cost;

        public State(int station, int company, int cost) {
            this.station = station;
            this.company = company;
            this.cost = cost;
        }
    }

    static int solve() {
        if( M == 0 ) return -1;

        Station[] stations = new Station[N];
        for (Edge edge : E) {
            if( stations[edge.p] == null ) {
                stations[edge.p] = new Station();
            }
            stations[edge.p].company(edge.c).edges.add(edge);

            if( stations[edge.q] == null ) {
                stations[edge.q] = new Station();
            }
            stations[edge.q].company(edge.c).edges.add(edge);
        }

        if( stations[0] == null ) return -1;

        // cost???????????queue?????
        ArrayDeque<State> q = new ArrayDeque<>();
        q.add( new State(0, 0, 0) );
        stations[0].cost = 0;

        while(!q.isEmpty()) {
            State s = q.poll();

            Station station = stations[s.station];
            if( station == null ) continue;
            if( station.cost(s.company) != s.cost ) continue;

            if( s.company != 0 ) {
                // ????edge???????????
                // cost?????
                for (Edge edge : station.company(s.company).edges) {
                    int nextStation = edge.opposite(s.station);

                    if( stations[nextStation].cost(s.company) > s.cost ) {
                        q.add(new State(nextStation, s.company, s.cost));
                        stations[nextStation].company(s.company).cost = s.cost;
                    }
                }

                // ?station?0???
                // cost?????
                if( station.cost > s.cost ) {
                    q.add(new State(s.station, 0, s.cost));
                    station.cost = s.cost;
                }

            } else {
                // ?station?0????????
                // ???+1(????)
                int nextCost = s.cost + 1;
                for (Integer c : station.companies.keySet()) {
                    if( station.company(c).cost > nextCost ) {
                        q.add(new State(s.station, c, nextCost));
                        station.company(c).cost = nextCost;
                    }
                }
            }
        }

        Station last = stations[N-1];
        if( last == null ) return -1;
        if( last.cost == INF ) return -1;
        return last.cost;
    }


    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}