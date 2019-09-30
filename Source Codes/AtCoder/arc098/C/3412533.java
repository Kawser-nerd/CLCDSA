import static java.util.Arrays.*;
import static java.util.stream.Collectors.*;

import java.util.*;

public class Main {
    private class Data {
        int n, p;

        public Data(int n, int p) {
            this.n = n;
            this.p = p;
        }

        @Override
        public String toString() {
            return n + ":" + p;
        }
    }

    private class Range {
        int src, dst;

        public Range(int src, int dst) {
            this.src = src;
            this.dst = dst;
        }

        public int len() {
            return dst - src + 1;
        }

        public boolean isInc(int tgt) {
            return src <= tgt && tgt <= dst;
        }

        @Override
        public String toString() {
            return src + "-" + dst;
        }
    }

    public void main(Scanner sc) {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int q = sc.nextInt();
        int a[] = new int[n];
        Data data[] = new Data[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            data[i] = new Data(a[i], i);
        }
        sc.close();
        sort(data, (o1, o2) -> o1.n - o2.n);

        Map<Integer, Range> map = new HashMap<>();
        map.put(0, new Range(0, n - 1));
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n;) {
            LinkedList<Integer> tmp = new LinkedList<>();
            for (Range r : map.values()) {
                tmp.addAll(stream(copyOfRange(a, r.src, r.dst + 1)).sorted().limit(r.len() - k + 1)
                    .boxed().collect(toList()));
            }
            Collections.sort(tmp);
            if (tmp.size() < q) {
                break;
            }

            int y = tmp.get(q - 1);
            int x = data[i].n;
            ans = Math.min(ans, y - x);

            splash(map, k, data[i].p);
            while (i < n && data[i].n == x) {
                splash(map, k, data[i].p);
                i++;
            }
        }

        System.out.println(ans);
    }

    private void splash(Map<Integer, Range> map, int minSize, int p) {
        for (Range r : new ArrayList<>(map.values())) {
            if (r.isInc(p)) {
                Range newR = new Range(p + 1, r.dst);
                if (newR.len() >= minSize) {
                    map.put(p + 1, newR);
                }

                r.dst = p - 1;
                if (r.len() < minSize) {
                    map.remove(r.src);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}