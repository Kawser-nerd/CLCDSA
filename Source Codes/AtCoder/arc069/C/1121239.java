import java.util.Arrays;
import java.util.Scanner;

public class Main {
    Scanner   sc   = new Scanner(System.in);

    void run() {
        int n = sc.nextInt();
        Pair[] p = new Pair[n + 1];
        for (int i = 0; i < n; i++) p[i] = new Pair(i + 1, sc.nextLong());
        p[n] = new Pair(0, 0);
        Arrays.sort(p);
        long[] res = new long[n + 1];
        long cnt = 0;
        int idmin = n + 1;
        for (int i = 0; i < n; i++) {
            Pair nowP = p[i];
            idmin = Math.min(idmin, nowP.id);
            cnt++;
            while (nowP.cnt == p[i + 1].cnt) {
                i++;
                cnt++;
            }
            res[idmin] += cnt * (nowP.cnt - p[i + 1].cnt);
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < n + 1; i++) sb.append(res[i]+"\n");
        System.out.print(sb);
    }

    class Pair implements Comparable<Pair> {

        int  id;
        long cnt;

        public Pair(int id, long cnt) {
            super();
            this.id = id;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Pair arg0) {
            if (this.cnt == arg0.cnt) {
                return this.id - arg0.id;
            }
            return -Long.compare(this.cnt, arg0.cnt);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}