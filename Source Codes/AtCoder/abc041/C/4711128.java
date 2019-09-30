import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        PriorityQueue<Entry> pq = new PriorityQueue<Entry>(N, new EntryComparator());

        for (int i = 1; i <= N; i++) {
            pq.add(new Entry(sc.nextInt(), i));
        }

        while (!pq.isEmpty()) {
            Entry e = pq.poll();
            System.out.println(e.index);
        }
    }

    // ????????
    static class EntryComparator implements Comparator<Entry> {
        @Override
        public int compare(Entry t1, Entry t2) {
            if (t1.height < t2.height) {
                return 1;
            }
            return -1;
        }
    }

    static class Entry {
        public int height;
        public int index;

        public Entry(int height, int index) {
            this.height = height;
            this.index = index;
        }
    }
}