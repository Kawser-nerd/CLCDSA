import java.util.*;

public class Main {
    static long MOD = 109+7;

    static public void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long limitW = sc.nextLong();

        long[] w = new long[n];
        long[] v = new long[n];

        for(int i = 0; i < n; i++) {
            w[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }

        Knapsack knapsack = new Knapsack(n, limitW, w, v);
        System.out.println(knapsack.calc());
    }

    static class Knapsack {
        int n;
        long limitW;
        Item[] items;

        public Knapsack(int n, long limitW, long[] w, long[] v) {
            this.n = n;
            this.limitW = limitW;
            items = new Item[n];
            for(int i =0; i < n; i++) items[i] = new Item(w[i], v[i]);
        }

        public long calc() {
            Arrays.sort(items);

            Map<Long, Long> map = new HashMap();
            map.put(0L, 0L);
            for(Item item: items) {
                Map<Long, Long> curMap = new HashMap();
                for (long key : map.keySet()) {
                    long weight = key + item.w;
                    long value = map.get(key) + item.v;
                    if (weight <= limitW) {
                        curMap.put(weight, value);
                    }
                }

                for (long key : curMap.keySet()) {
                    if (map.containsKey(key)) {
                        map.put(key, Math.max(curMap.get(key), map.get(key)));
                    } else {
                        map.put(key, curMap.get(key));
                    }
                }
            }

            return Collections.max(map.values());
        }
        class Item implements Comparable<Item> {
            long w, v;
            Item(long w, long v) {
                this.w = w;
                this.v = v;
            }

            private double getEfficiency() {
                return 1.0 * v / w;
            }

            @Override
            public String toString() {
                return "w: " + w + ", " + "v: " + v;
            }

            @Override
            public int compareTo(Item o) {
                if(this.getEfficiency() - o.getEfficiency() > 0) return -1;
                else if(this.getEfficiency() - o.getEfficiency() < 0) return 1;
                else {
                    return (int) (o.w - this.w);
                }
            }
        }
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.