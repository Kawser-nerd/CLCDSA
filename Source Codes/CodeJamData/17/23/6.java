import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

import static java.lang.System.currentTimeMillis;
import static java.lang.System.out;

public class Round1BC {

    Kattio io;

    public void go() {
        try {
            io = new Kattio(System.in, new FileOutputStream(new File("Round1BC.out")));
            int zzz = io.nextInt();
            for (int zz = 0; zz < zzz; zz++) {
                int numCities = io.nextInt();
                int numRoutes = io.nextInt();
                int[][] horses = new int[numCities][2];
                long[][] distances = new long[numCities][numCities];
                for (int i = 0; i < numCities; i++) {
                    horses[i][0] = io.nextInt();
                    horses[i][1] = io.nextInt();
                }
                for (int i = 0; i < numCities; i++) {
                    for (int e = 0; e < numCities; e++) {
                        distances[i][e] = io.nextLong();
                    }
                }
                double[][] times = new double[numCities][numCities];
                for (int i = 0; i <  numCities; i++) {
                    Arrays.fill(times[i], Double.POSITIVE_INFINITY);
                }
                for (int i = 0; i < numCities; i++) {
                    Vertex start = new Vertex(i, 0, 0);
                    PriorityQueue<Vertex> queue = new PriorityQueue<>();
                    queue.add(start);
                    while (!queue.isEmpty()) {
                        Vertex curr = queue.remove();
                        if (curr.distance > horses[i][0] || curr.time > times[i][curr.index]) {
                            continue;
                        }
                        times[i][curr.index] = curr.time;
                        for (int e = 0; e < numCities; e++) {
                            if (distances[curr.index][e] != -1) {
                                queue.add(new Vertex(e, curr.time+(double)distances[curr.index][e]/horses[i][1], curr.distance+distances[curr.index][e]));
                            }
                        }
                    }
                }
                io.printf("Case #%d:", zz+1);
                for (int i = 0; i < numRoutes; i++) {
                    boolean[] visited = new boolean[numCities];
                    Vertex start = new Vertex(io.nextInt()-1, 0, 0);
                    int endIndex = io.nextInt()-1;
                    PriorityQueue<Vertex> queue = new PriorityQueue<>();
                    queue.add(start);
                    double min = Double.POSITIVE_INFINITY;
                    while (!queue.isEmpty()) {
                        Vertex curr = queue.remove();
                        if (visited[curr.index]) {
                            continue;
                        }
                        visited[curr.index] = true;
                        if (curr.index == endIndex) {
                            min = Math.min(curr.time, min);
                            continue;
                        }
                        for (int e = 0; e < numCities; e++) {
                            queue.add(new Vertex(e, curr.time + times[curr.index][e], 0));
                        }
                    }
                    io.print(" " + min);
                }
                io.println();
            }

            io.flush();
            io.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Round1BC().go();
    }

    private class Vertex implements Comparable<Vertex> {

        int index;
        double time, distance;

        public Vertex(int i, double t, double d) {
            index = i;
            time = t;
            distance = d;
        }

        public int compareTo(Vertex other) {
            if (time > other.time) {
                return 1;
            } else if (time < other.time){
                return -1;
            }
            return 0;
        }

        public String toString() {
            return String.format("%d %.5f %.5f", index, time, distance);
        }
    }

    private class Kattio extends PrintWriter {

        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasNext() {
            return peekToken() != null;
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

        public String next() {
            return nextToken();
        }

        public String nextLine() {
            token = null;
            st = null;
            try {
                return r.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        private String peekToken() {
            if (token == null)
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {
                }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }
}
