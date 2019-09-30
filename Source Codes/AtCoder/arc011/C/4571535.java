import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Collection;
import java.util.Set;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String start = in.next();
            String end = in.next();
            if (start.equals(end)) {
                out.println(0);
                out.println(start);
                out.println(end);
                return;
            }

            int n = in.nextInt();
            String[] strings = new String[n + 2];
            for (int i = 0; i < n; i++)
                strings[i] = in.next();
            strings[n] = start;
            strings[n + 1] = end;

            Map<String, Vertex> stringToVertex = new HashMap<>();
            Map<Vertex, String> vertexToString = new HashMap<>();
            for (String s : strings) {
                Vertex v = new Vertex();
                for (String cs : stringToVertex.keySet()) {
                    int count = 0;
                    for (int i = 0; i < s.length(); i++) {
                        if (cs.charAt(i) == s.charAt(i))
                            count++;
                    }
                    if (count == s.length() - 1) {
                        Vertex cv = stringToVertex.get(cs);
                        v.setEdge(cv, 1);
                        cv.setEdge(v, 1);
                    }
                }
                stringToVertex.put(s, v);
                vertexToString.put(v, s);
            }

            Vertex sv = stringToVertex.get(start);
            Vertex ev = stringToVertex.get(end);
            Dijkstra d = new Dijkstra(sv);

            if (!d.isReachable(ev)) {
                out.println(-1);
            } else {
                d.getPath(ev);
                Vertex[] path = d.getPath(ev);
                out.println(path.length - 2);
                for (Vertex cv : path) {
                    out.println(vertexToString.get(cv));
                }
            }
        }

    }

    static class Edge {
        private Vertex from;
        private Vertex to;
        private long cost;

        public Edge() {
        }

        public Edge(Vertex to) {
            this.to = to;
        }

        public Edge(Vertex to, long c) {
            this.to = to;
            this.cost = c;
        }

        public Edge(Vertex from, Vertex to, long c) {
            this.from = from;
            this.to = to;
            this.cost = c;
            from.setEdge(this);
        }

        public Vertex getTo() {
            return this.to;
        }

        public long getCost() {
            return this.cost;
        }

    }

    static class Pair<A, B> {
        private A first;
        private B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair<?, ?> pair = (Pair<?, ?>) o;

            if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
            return second != null ? second.equals(pair.second) : pair.second == null;
        }

        public int hashCode() {
            int firstH = (first != null) ? first.hashCode() : 0;
            int secondH = (second != null) ? second.hashCode() : 0;
            return (31 * firstH) + secondH;
        }

        public A getFirst() {
            return first;
        }

        public B getSecond() {
            return second;
        }

    }

    static class FastScanner {
        private InputStream in;
        private byte[] buffer = new byte[1024];
        private int bufPointer;
        private int bufLength;

        public FastScanner(InputStream in) {
            this.in = in;
            this.bufPointer = 0;
            this.bufLength = 0;
        }

        private int readByte() {
            if (bufPointer >= bufLength) {
                if (bufLength == -1)
                    throw new InputMismatchException();

                bufPointer = 0;
                try {
                    bufLength = in.read(buffer);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (bufLength <= 0)
                    return -1;
            }
            return buffer[bufPointer++];
        }

        private static boolean isPrintableChar(int c) {
            return c >= 33 && c <= 126;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            StringBuilder sb = new StringBuilder();

            int b = readByte();
            while (!isPrintableChar(b))
                b = readByte();

            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }

            return sb.toString();
        }

        public int nextInt() {
            int n = 0;

            int b = readByte();
            while (isSpaceChar(b))
                b = readByte();

            boolean minus = (b == '-');
            if (minus)
                b = readByte();

            while (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
                b = readByte();
            }

            if (!isSpaceChar(b))
                throw new NumberFormatException();

            return minus ? -n : n;
        }

    }

    static class Vertex {
        private long value;
        private List<Edge> edges = new ArrayList<>();

        public Vertex() {
        }

        public Vertex(long v) {
            this.value = v;
        }

        public void setEdge(Vertex v, long cost) {
            this.edges.add(new Edge(v, cost));
        }

        public void setEdge(Edge e) {
            this.edges.add(e);
        }

        public long getDegree() {
            return this.edges.size();
        }

        public Edge getEdge(int index) {
            return this.edges.get(index);
        }

    }

    static class Dijkstra {
        private Map<Vertex, Long> minCost = new HashMap<>();
        private Map<Vertex, Vertex> prevVertex = new HashMap<>();
        private Vertex start;

        public Dijkstra(Vertex start) {
            minCost.put(start, (long) 1);
            this.start = start;
            findPath();
        }

        private void findPath() {
            // queue for vertex and cost pair. ordered by cost
            Queue<Pair<Vertex, Long>> q = new PriorityQueue<>(Comparator.comparing(Pair::getSecond));
            q.add(new Pair<>(start, (long) 1));

            Set<Vertex> visited = new HashSet<>();
            // find path
            while (q.size() > 0) {
                // if it is not the shortest path, ignore it
                Pair<Vertex, Long> pairVertexCost = q.poll();
                Vertex cv = pairVertexCost.getFirst();
                long cvCost = pairVertexCost.getSecond();
                if (cvCost > minCost.get(cv)) continue;

                visited.add(cv);

                // see each connected edges
                for (int i = 0; i < cv.getDegree(); i++) {
                    Vertex nextV = cv.getEdge(i).getTo();
                    if (visited.contains(nextV)) continue;

                    long cost = cvCost + cv.getEdge(i).getCost();
                    // if new cost is smaller, add new vertex
                    if (cost < minCost.getOrDefault(nextV, Long.MAX_VALUE)) {
                        minCost.put(nextV, cost);
                        prevVertex.put(nextV, cv);
                        q.add(new Pair<>(nextV, cost));
                    }
                }
            }
        }

        public Vertex[] getPath(Vertex goal) {
            Vertex cv = goal;
            Deque<Vertex> vertexDeque = new ArrayDeque<>(); // reverse order
            while (cv != start) {
                vertexDeque.addFirst(cv);
                cv = prevVertex.get(cv);
            }
            vertexDeque.addFirst(start);
            Vertex[] path = new Vertex[vertexDeque.size()];
            for (int i = 0; i < path.length; i++) path[i] = vertexDeque.poll();
            return path;
        }

        public boolean isReachable(Vertex v) {
            return minCost.containsKey(v);
        }

    }
}