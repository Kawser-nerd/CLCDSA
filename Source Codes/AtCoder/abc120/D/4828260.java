import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskDecayed solver = new TaskDecayed();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskDecayed {
        public static TaskDecayed.V[] vertices;
        public static TaskDecayed.E[] edges;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int N = in.nextInt();
            int M = in.nextInt();
            vertices = new TaskDecayed.V[N];
            edges = new TaskDecayed.E[M];
            for (int i = 0; i < N; i++) {
                vertices[i] = new TaskDecayed.V(i + 1);
            }
            for (int i = 0; i < M; i++) {
                edges[i] = new TaskDecayed.E(in.nextInt(), in.nextInt(), i);
            }

            long res[] = new long[M + 1];
            long Nlong = N;
            res[M] = Nlong * (Nlong - 1) / 2l;
            for (int i = M - 1; i >= 0; i--) {
                res[i] = res[i + 1] - union(edges[i].v1, edges[i].v2);
            }
            if (res[0] != 0)
                throw new RuntimeException("Diff");
            for (int i = 1; i <= M; i++) {
                out.println(res[i]);
            }
        }

        private long union(TaskDecayed.V v1, TaskDecayed.V v2) {
            TaskDecayed.V rootV1 = findRoot(v1);
            TaskDecayed.V rootV2 = findRoot(v2);
            if (rootV1 == rootV2)
                return 0;
            if (rootV1.rank < rootV2.rank) {
                TaskDecayed.V tmp = rootV1;
                rootV1 = rootV2;
                rootV2 = tmp;
            }
            if (rootV1.rank == rootV2.rank)
                rootV2.rank++;
            long res = rootV1.nb * rootV2.nb;
            rootV1.parent = rootV2;
            rootV2.nb += rootV1.nb;
            return res;
        }

        private TaskDecayed.V findRoot(TaskDecayed.V v) {
            if (v.parent == null)
                return v;
            v.parent = findRoot(v.parent);
            return v.parent;
        }

        public static class V {
            int id;
            int rank;
            long nb;
            TaskDecayed.V parent;

            public V(int id) {
                this.id = id;
                this.rank = 1;
                this.nb = 1;
            }

        }

        public static class E {
            TaskDecayed.V v1;
            TaskDecayed.V v2;
            int id;

            public E(int id1, int id2, int id) {
                this.v1 = vertices[id1 - 1];
                this.v2 = vertices[id2 - 1];
                this.id = id;
            }

        }

    }
}