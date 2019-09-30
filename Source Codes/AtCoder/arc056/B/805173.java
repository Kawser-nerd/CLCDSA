import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int S = sc.nextInt() - 1;
        int[] u = new int[M];
        int[] v = new int[M];
        for (int i = 0; i < M; i++) {
            u[i] = sc.nextInt() - 1;
            v[i] = sc.nextInt() - 1;
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
                Park next = new Park(Math.min(current.min, node), node);
                queue.add(next);
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

    public static class Scanner {
        private BufferedInputStream inputStream;

        public Scanner(InputStream in) {
            inputStream = new BufferedInputStream(in);
        }

        public int nextInt() throws IOException {
            int num = 0;

            int read = skip();
            do {
                num = num * 10 + (read - 0x30);
            } while ((read = inputStream.read()) > 0x20);

            return num;
        }

        public int[] nextInt(int n) throws IOException {
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextInt();
            }

            return array;
        }

        public long nextLong() throws IOException {
            long num = 0;

            int read = skip();
            do {
                num = num * 10 + (read - 0x30);
            } while ((read = inputStream.read()) > 0x20);

            return num;
        }

        public long[] nextLong(int n) throws IOException {
            long[] array = new long[n];
            for (int i = 0; i < n; i++) {
                array[i] = nextLong();
            }

            return array;
        }

        public String next() throws IOException {
            StringBuilder builder = new StringBuilder();

            int read = skip();
            do {
                builder.append((char) read);
            } while ((read = inputStream.read()) > 0x20);

            return builder.toString();
        }

        private int skip() throws IOException {
            int read;
            while ((read = inputStream.read()) <= 0x20)
                ;

            return read;
        }
    }
}