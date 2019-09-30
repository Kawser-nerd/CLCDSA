import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Wolfgang Beyer
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        SquaredGraph solver = new SquaredGraph();
        solver.solve(1, in, out);
        out.close();
    }

    static class SquaredGraph {
        Graph g;
        int[] color;
        boolean isBipartite;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            g = new Graph(n);
            for (int i = 0; i < m; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                g.addEdge(u, v);
            }

            long unconnectedNodes = 0;
            long bipartiteComponents = 0;
            long nonBipartiteComponents = 0;
            // boolean[] visited = new boolean[n];
            color = new int[n];

            for (int i = 0; i < n; i++) {
                if (color[i] == 0) {
                    if (g.adjList[i].size() == 0) {
                        unconnectedNodes++;
                    } else {
                        isBipartite = true;
                        bipartiteDFS(i, 1);
                        if (isBipartite) {
                            bipartiteComponents++;
                        } else {
                            nonBipartiteComponents++;
                        }
                    
                    /*if (bipartiteDFS(i, color, 1)) {
                        bipartiteComponents++;
                    } else {
                        nonBipartiteComponents++;
                    }*/
                    }
                }
            }

            long result = 2L * (long) n * unconnectedNodes - unconnectedNodes * unconnectedNodes;
            result += nonBipartiteComponents * (bipartiteComponents + nonBipartiteComponents);
            result += bipartiteComponents * (nonBipartiteComponents + 2L * bipartiteComponents);
            out.println(result);
        }

        void bipartiteDFS(int idx, int currentColor) {
            if (color[idx] != 0) {
                if (color[idx] != currentColor) isBipartite = false;
                return;
            }
            // visited[idx] = true;
            color[idx] = currentColor;
            //currentColor = !currentColor;
            for (int childIdx[] : g.adjList[idx]) {
                //result = (result && bipartiteDFS(childIdx[0], color, -currentColor));
                bipartiteDFS(childIdx[0], -currentColor);
            }
            return;
        }

    }

    static class Graph {
        int numberOfVertices;
        public int numberOfEdges;
        public List<int[]>[] adjList;

        public Graph(int vertices) {
            numberOfVertices = vertices;
            numberOfEdges = 0;
            adjList = new ArrayList[numberOfVertices];
            for (int i = 0; i < numberOfVertices; i++) {
                adjList[i] = new ArrayList<int[]>();
            }
        }

        public void addEdge(int u, int v) {
            adjList[u].add(new int[]{v, numberOfEdges});
            adjList[v].add(new int[]{u, numberOfEdges});
            numberOfEdges++;
        }

    }

    static class InputReader {
        private static BufferedReader in;
        private static StringTokenizer tok;

        public InputReader(InputStream in) {
            this.in = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            try {
                while (tok == null || !tok.hasMoreTokens()) {
                    tok = new StringTokenizer(in.readLine());
                }
            } catch (IOException ex) {
                System.err.println("An IOException was caught :" + ex.getMessage());
            }
            return tok.nextToken();
        }

    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.