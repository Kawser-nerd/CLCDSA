import java.util.*;

public class Main {
    static Map<Integer, List<Path>> map;
    static int n;
    static long[] memo;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        map = new HashMap<>();
        memo = new long[n+1];
        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            List<Path> tmp = map.get(a);
            if(tmp != null) {
                tmp.add(new Path(b, c));
            }
            else {
                List<Path> tmp1 = new ArrayList<>();
                tmp1.add(new Path(b, c));
                map.put(a, tmp1);
            }
            tmp = map.get(b);
            if(tmp != null) {
                tmp.add(new Path(a, c));
            }
            else {
                List<Path> tmp1 = new ArrayList<>();
                tmp1.add(new Path(a, c));
                map.put(b, tmp1);
            }
        }
        int Q = sc.nextInt();
        int k = sc.nextInt();
        Deque<Integer> q = new ArrayDeque<>();
        q.add(k);
        while (!q.isEmpty()) {
            int c = q.poll();
            for(Path next : map.get(c)){
                if(memo[next.a] != 0) {
                    continue;
                }
                memo[next.a] = memo[c] + next.b;
                q.add(next.a);
            }
        }
        for (int i = 0; i < Q; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println(memo[a] + memo[b]);
        }
    }

    static class Path{
        int a;
        long b;

        public Path(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Path path = (Path) o;
            return a == path.a &&
                    b == path.b;
        }

        @Override
        public int hashCode() {
            return Objects.hash(a, b);
        }
    }
}