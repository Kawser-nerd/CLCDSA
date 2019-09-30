import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    int n;
    long[][] A;
    PriorityQueue<Edge> es;
    long[][] dp;
    final static long INF = 1000000007;

    public static void main(String[] args) {
        Main m = new Main();
        m.read();
        m.solve();
    }

    private void read() {
        es = new PriorityQueue<>((e1, e2) -> Long.compare(e1.cost, e2.cost));
        try (BufferedReader br = new BufferedReader(
                new InputStreamReader(System.in)
        )) {
            String line = br.readLine();
            String[] elems;
            n = Integer.parseInt(line);
            A = new long[n][n];
            for (int i = 0; i < n; i++) {
                elems = br.readLine().split(" ");
                for (int j = 0; j < n; j++) {
                    A[i][j] = Long.parseLong(elems[j]);
                    if (j < i)
                        es.add(new Edge(i, j, A[i][j]));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void solve() {
        dp = new long[n][n];
        for (int i = 0; i < n; i++)
            dp[i] = Arrays.copyOf(A[i], n);
        upd(dp);
        long ret = 0L;
        while (!es.isEmpty()) {
            Edge e = es.poll();
            if (e.cost > dp[e.a][e.b]) {
                es.add(e);
                break;
            }
            else {
                if (!check(e.a, e.b)) {
                    ret += dp[e.a][e.b];
                }
            }
        }
        if (!es.isEmpty()) {
            System.out.println(-1);
        }
        else {
            System.out.println(ret);
        }
    }

    private void upd(long[][] arr) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    arr[i][j] = Math.min(arr[i][j],
                            arr[i][k] + arr[k][j]);
            }
        }
    }

    private boolean check(int u ,int v) {
        boolean ret = false;
        for (int i = 0; i < n; i++)
            if (i != u && i != v)
                ret |= dp[u][v] == dp[u][i] + dp[i][v];
        return ret;
    }

    private void print(long[][] array) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (array[i][j] == INF)
                    System.out.printf("INF ");
                else
                    System.out.printf("%2d ", array[i][j]);
            }
            System.out.println();
        }
    }

    private class Edge {
        int a, b;
        long cost;
        Edge (int a, int b, long c) {
            this.a = a;
            this.b = b;
            this.cost = c;
        }

        @Override
        public String toString() {
            return String.format("%3d <-> %3d: %d", a, b, cost);
        }
    }
}