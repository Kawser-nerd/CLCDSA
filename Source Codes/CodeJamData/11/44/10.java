
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class d {
    public static void main(String[] args) {
        Scanner s = new Scanner(new BufferedInputStream(System.in));

        int T = s.nextInt();
        for (int casenumber = 1; casenumber <= T; ++casenumber) {

            p = s.nextInt();
            int w = s.nextInt();

            adj = new boolean[p][p];

            // ArrayList[] edges1 = new ArrayList[p];

            // for (int i = 0; i < p; ++i)
                // edges[1] = new ArrayList<Integer>();

            for (int i = 0; i < w; ++i) {
                String str = s.next();
                String[] strs = str.split(",");
                int a = Integer.parseInt(strs[0]);
                int b = Integer.parseInt(strs[1]);
                adj[a][b] = true;
                adj[b][a] = true;

                // ((ArrayList<Integer>) edges[a]).add(b);
                // ((ArrayList<Integer>) edges[b]).add(a);
            }

            co = new int[p][p];

            for (int i = 0; i < p; ++i) {
                for (int j = i + 1; j < p; ++j) {
                    int count = 0;
                    for (int k = 0; k < p; ++k) {
                        if (k == i || k == j) continue;
                        if (adj[i][k] || adj[j][k]) ++count;
                    }
                    co[i][j] = co[j][i] = count;
                }
            }

            /*
            

            edges = new int[p][];

            for (int i = 0; i < p; ++i) {
                edges[i] = new int[edges1[i].size()];
                for (int j = 0; j < edges[i].length; ++j)
                    edges[i][j] = edges1[i].get(j);
            }
            */

            distance0 = new int[p];
            distance1 = new int[p];

            Arrays.fill(distance0, p + 1000);
            Arrays.fill(distance1, p + 1000);

            boolean[] visited = new boolean[p];
            distance0[0] = 0;
            visited[0] = true;

            LinkedList<Integer> queue = new LinkedList<Integer>();
            queue.addLast(0);

            while (!queue.isEmpty()) {
                int next = queue.removeFirst();
                // System.out.println(next);

                for (int i = 0; i < p; ++i) {
                    // System.out.println("              " + i + " " + next);
                    if (adj[i][next] && !visited[i]) {
                        // System.out.println("yeah");
                        visited[i] = true;
                        queue.addLast(i);
                        distance0[i] = distance0[next] + 1;
                    }
                }

                /*
                for (int i = 0; i < edges[next].length; ++i) {
                    if (!visited[edges[next][i]]) {
                        visited[edges[next][i]] = true;
                        queue.addLast(edges[next][i]);
                        distance0[edges[next][i]] = distance0[next] + 1;
                    }
                }
                */
            }

            Arrays.fill(visited, false);

            distance1[1] = 0;
            visited[1] = true;

            queue = new LinkedList<Integer>();
            queue.addLast(1);

            while (!queue.isEmpty()) {
                int next = queue.removeFirst();


                for (int i = 0; i < p; ++i) {
                    if (adj[i][next] && !visited[i]) {
                        visited[i] = true;
                        queue.addLast(i);
                        distance1[i] = distance1[next] + 1;
                    }
                }
                /*
                for (int i = 0; i < edges[next].length; ++i) {
                    if (!visited[edges[next][i]]) {
                        visited[edges[next][i]] = true;
                        queue.addLast(edges[next][i]);
                        distance1[edges[next][i]] = distance1[next] + 1;
                    }
                }
                */
            }

            d = distance0[1];

            best = new int[p][p];

            for (int i = 0; i < p; ++i) {
                for (int j = 0; j < p; ++j) {
                    best[i][j] = -1;
                }
            }

            if (d > 1) {

                for (int i = 0; i < p; ++i) {
                    for (int j = 0; j < p; ++j) {
                        compute_best(i, j);
                    }
                }

                int b = -3;
                for (int i = 0; i < p; ++i) {
                    if (distance1[i] != 1) continue;
                    for (int j = 0; j < p; ++j) {
                        if (best[i][j] >= 0 && best[i][j] > b)
                            b = best[i][j];
                    }
                }

                System.out.format("Case #%d: %d %d%n", casenumber, d - 1, b);
            } else {
                int count = 0;
                for (int i = 1; i < p; ++i) {
                    if (adj[i][0]) ++count;
                }

                System.out.format("Case #%d: 0 %d%n", casenumber, count);
            }
        }
    }

    private static int p;
    private static int[][] best;
    private static int d;
    private static int[] distance0;
    private static int[] distance1;
    private static boolean[][] adj;
    // private static int[][] edges;
    private static int[][] co;

    private static void compute_best(int a, int b) {
        if (!adj[a][b]) return;
        if (distance0[a] + distance1[a] != d) return;
        if (distance0[b] + distance1[b] != d) return;
        if (distance0[a] != distance0[b] + 1) return;
        if (distance1[a] == 0) return;
        if (best[a][b] >= 0) return;

        if (distance0[b] == 0) {
            // base case

            best[a][b] = co[a][b];
        } else {
            int best_so_far = -2;
            for (int c = 0; c < p; ++c) {
                if (c == a || c == b) continue;
                if (!adj[b][c]) continue;
                compute_best(b, c);
                if (best[b][c] < 0) continue;

                int count = 0;
                for (int i = 0; i < p; ++i) {
                    if (i == a || i == b || i == c) continue;
                    if (adj[i][a] && !adj[i][b] && !adj[i][c]) ++count;
                }

                if (count + best[b][c] - 1 > best_so_far)
                    best_so_far = count + best[b][c] - 1;
            }

            best[a][b] = best_so_far;
        }
    }
}
