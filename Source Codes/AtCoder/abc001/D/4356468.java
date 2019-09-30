import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        PriorityQueue<Entry> pq = new PriorityQueue<Entry>(N, new EntryComparator());
        for (int i = 0; i < N; i++) {
            String str = sc.next();
            String[] se_str = str.split("-");
            int[] se = new int[2];
            for(int j = 0; j < se_str.length; j++) {
                se[0] = Integer.parseInt(se_str[0]);
                se[1] = Integer.parseInt(se_str[1]);
            }
            se = roundSe(se);

            pq.add(new Entry(se[0], se[1]));
        }

        //PriorityQueue<Entry> pq_tmp = new PriorityQueue<Entry>(pq);
        //while(!pq_tmp.isEmpty()){
        //    Entry entry = pq_tmp.poll();
        //    out.println(entry.S + "," + entry.E);
        //}

        check(pq);
    }


    public static void check(PriorityQueue<Entry> pq){
        PriorityQueue<Entry> ans = new PriorityQueue<Entry>(pq.size(), new EntryComparator());

        Entry entry = pq.poll();
        int s = entry.S;
        int e = entry.E;

        while(!pq.isEmpty()){
            entry = pq.poll();
            int nextS = entry.S;
            int nextE = entry.E;

            //out.println("*" + s + "-" + e);
            //out.println("*" + nextS + "-" + nextE);

            // ??????????
            if(e < nextS){ // ???????
                ans.add(new Entry(s, e));
                s = nextS;
                e = nextE;
                continue;
            }

            // ??????
            if(e < nextE) {
                e = nextE;
            }
        }
        ans.add(new Entry(s, e));

        while(!ans.isEmpty()){
            entry = ans.poll();
            out.printf("%04d-%04d%n", entry.S, entry.E);
        }
    }

    public static int[] roundSe(int[] se) {
        se[0] = se[0] - (se[0] % 5);

        if(se[1] % 5 != 0) {
            se[1] = ((se[1] / 5) + 1) * 5;
        }

        //???? 1160 -> 1200
        if((se[1] - 60) % 100 == 0) {
            se[1] = (se[1] - 60) + 100;
        }

        return se;
    }

    // ?????????
    static class EntryComparator implements Comparator<Entry> {
        @Override
        public int compare(Entry t1, Entry t2) {
            if (t1.S > t2.S){
                return 1;
            } else if (t1.S == t2.S){
                if(t1.E > t2.E) {
                    return 1;
                } else if(t1.E == t2.E) {
                    return 0;
                }
            }
            return -1;
        }
    }

    static class Entry {
        public int S;
        public int E;

        public Entry(int S, int E){
            this.S = S;
            this.E = E;
        }
    }
}