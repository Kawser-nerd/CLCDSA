import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        PriorityQueue<Entry> pq = new PriorityQueue<Entry>(N, new EntryComparator());
        for (int i = 0; i < M; i++) {
            Entry entry = new Entry(sc.nextInt(), sc.nextInt());
            pq.add(entry);
        }

        Entry entry = pq.poll();
        int maxB = entry.b;

        int ans = 1;
        while(!pq.isEmpty()){
            entry = pq.poll();
            if(entry.a >= maxB){
                ans++;
                maxB = entry.b;
            } else {
                maxB = Math.min(entry.b, maxB);
            }
        }

        out.println(ans);
    }

    // ??
    static class EntryComparator implements Comparator<Entry> {
        @Override
        public int compare(Entry t1, Entry t2) {
            if (t1.a >= t2.a){
                return 1;
            }
            return -1;
        }
    }

    static class Entry {
        public int a;
        public int b;

        public Entry(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
}