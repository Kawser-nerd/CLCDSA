import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    Random rnd = new Random(123);

    class Road {
        int fr, to;
        int id;
        int ai, bi;
        boolean used;
        long difined;

        public Road(int fr, int to, int id, int ai, int bi) {
            super();
            this.fr = fr;
            this.to = to;
            this.id = id;
            this.ai = ai;
            this.bi = bi;
        }

        long getCost() {
            return used ? ai : bi;
        }

    }

    class Road2 implements Comparable<Road2> {
        int to;
        long cost;
        int type;

        public Road2(int to, long cost) {
            super();
            this.to = to;
            this.cost = cost;
        }

        public Road2(int to, long cost, int type) {
            super();
            this.to = to;
            this.cost = cost;
            this.type = type;
        }

        @Override
        public int compareTo(Road2 o) {
            if (cost == o.cost)
                return -Integer.compare(type, o.type);
            return Long.compare(cost, o.cost);
        }

    }

    ArrayList<Road>[] g;

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();
        ArrayList<Road> roads = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            roads.add(new Road(in.nextInt() - 1, in.nextInt() - 1, i, in
                    .nextInt(), in.nextInt()));
        }
        ArrayList<Integer> myRoad = new ArrayList<>();
        long length = 0;
        for (int i = 0; i < p; i++) {
            myRoad.add(in.nextInt() - 1);
            roads.get(myRoad.get(i)).used = true;
            length += roads.get(myRoad.get(i)).ai;
        }
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            Road r = roads.get(i);
            g[r.fr].add(r);
        }
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<Road2> pq = new PriorityQueue<>();
        pq.add(new Road2(0, 0));
        while (pq.size() != 0) {
            Road2 r = pq.remove();
            if (dist[r.to] != r.cost) {
                continue;
            }
            for (Road ro : g[r.to]) {
                long newCost = dist[r.to] + ro.getCost();
                if (dist[ro.to] > newCost) {
                    dist[ro.to] = newCost;
                    pq.add(new Road2(ro.to, newCost));
                }
            }
        }
        if (dist[1] > length) {
            throw new AssertionError();
        }
        if (dist[1] == length) {
            out.println("Looks Good To Me");
        } else {
            for (int i = 0; i < myRoad.size(); i++) {
                int curCity = roads.get(myRoad.get(i)).to;
                for (int j = 0; j < roads.size(); j++) {
                    roads.get(j).difined = -1;
                }
                long curCost = 0;
                for (int j = 0; j <= i; j++) {
                    roads.get(myRoad.get(j)).difined = roads.get(myRoad.get(j)).ai;
                    curCost += roads.get(myRoad.get(j)).difined;
                }
                long[] dist0 = new long[n];
                long[] dist1 = new long[n];
                Arrays.fill(dist0, Long.MAX_VALUE);
                Arrays.fill(dist1, Long.MAX_VALUE);
                dist0[0] = 0;
                dist1[curCity] = curCost;
                PriorityQueue<Road2> pq2 = new PriorityQueue<>();
                pq2.add(new Road2(0, 0, 0));
                pq2.add(new Road2(curCity, curCost, 1));
                while (pq2.size() != 0) {
                    Road2 r = pq2.remove();
                    if (r.type == 0) {
                        if (dist0[r.to] != r.cost)
                            continue;
                        for (Road rr : g[r.to]) {
                            if (rr.difined == -1) {
                                rr.difined = rr.bi;
                            }
                            if (dist0[rr.to] > dist0[r.to] + rr.difined) {
                                dist0[rr.to] = dist0[r.to] + rr.difined;
                                pq2.add(new Road2(rr.to, dist0[rr.to], 0));
                            }
                        }
                    } else {
                        if (dist1[r.to] != r.cost)
                            continue;
                        for (Road rr : g[r.to]) {
                            if (rr.difined == -1) {
                                rr.difined = rr.ai;
                            }
                            if (dist1[rr.to] > dist1[r.to] + rr.difined) {
                                dist1[rr.to] = dist1[r.to] + rr.difined;
                                pq2.add(new Road2(rr.to, dist1[rr.to], 1));
                            }
                        }
                    }
                }
                if (dist1[1] > dist0[1]) {
                    out.println(roads.get(myRoad.get(i)).id + 1);
                    break;
                }
            }
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            int testNumber = in.nextInt();
            for (int test = 1; test <= testNumber; test++) {
                out.print("Case #" + (test) + ": ");
                solve();
                System.out.println(test);
            }

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        try {
            solve();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}