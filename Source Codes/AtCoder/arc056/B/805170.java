import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] NMS = reader.readLine().split(" ");
        int N = Integer.parseInt(NMS[0]);
        int M = Integer.parseInt(NMS[1]);
        int S = Integer.parseInt(NMS[2]) - 1;
        int[] u = new int[M];
        int[] v = new int[M];
        for (int i = 0; i < M; i++) {
            String[] uv = reader.readLine().split(" ");
            u[i] = Integer.parseInt(uv[0]) - 1;
            v[i] = Integer.parseInt(uv[1]) - 1;
        }

        List<List<Integer>> graph = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            graph.get(u[i]).add(v[i]);
            graph.get(v[i]).add(u[i]);
        }

        boolean[] used = new boolean[N];
        Integer[] cost = new Integer[N];
        PriorityQueue<Park> queue = new PriorityQueue<>();

        queue.add(new Park(S, S));

        while (!queue.isEmpty()) {
            Park current = queue.poll();

            if (used[current.now]) {
                continue;
            }

            used[current.now] = true;
            cost[current.now] = current.min;

            for (Integer node : graph.get(current.now)) {
                if (!used[node]) {
                    Park next = new Park(Math.min(current.min, node), node);
                    queue.add(next);
                }
            }
        }

        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (cost[i] >= i) {
                builder.append(i + 1);
                builder.append(System.lineSeparator());
            }
        }

        System.out.print(builder.toString());
    }

    private static class Park implements Comparable<Park> {
        public Integer min;
        public int now;

        public Park(Integer min, int now) {
            this.min = min;
            this.now = now;
        }

        public Integer getMin() {
            return min;
        }

        public int getNow() {
            return now;
        }

        @Override
        public int compareTo(Park other) {
            return other.now - this.now;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Park park = (Park) o;

            if (min != park.min) return false;
            return now == park.now;

        }

        @Override
        public int hashCode() {
            int result = min;
            result = 31 * result + now;
            return result;
        }

        @Override
        public String toString() {
            return "Park{min=" + min + ", now=" + now + '}';
        }
    }
}