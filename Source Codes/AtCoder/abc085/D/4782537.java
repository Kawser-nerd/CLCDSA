import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long H = sc.nextInt();

        PriorityQueue<Entry> sords = new PriorityQueue<Entry>(new EntryComparator());
        for (int i = 0; i < N; i++) {
            sords.add(new Entry(sc.nextLong(), false));
            sords.add(new Entry(sc.nextLong(), true));
        }

        // a, b???????????????
        // ???b??????????b???????a????
        int cnt = 0;
        long aAttach = -1l;
        while (H > 0) {
            Entry entry = sords.poll();

            // A?????????
            if (!entry.isB) {
                aAttach = entry.attack;
                break;
            }

            H -= entry.attack;
            cnt++;
        }

        if (aAttach != -1) {
            cnt += (long) Math.ceil((double) H / aAttach);
        }

        out.println(cnt);
    }

    // ??????
    static class EntryComparator implements Comparator<Entry> {
        @Override
        public int compare(Entry t1, Entry t2) {
            if (t1.attack < t2.attack) {
                return 1;
            }
            return -1;
        }
    }

    static class Entry {
        long attack;
        boolean isB;

        Entry(long attack, boolean isB) {
            this.attack = attack;
            this.isB = isB;
        }
    }
}