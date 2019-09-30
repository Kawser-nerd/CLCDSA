
import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 *
 * @author igor_kz
 */
public class SpaceEmergency {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int test = Integer.parseInt(in.nextLine());
        for (int tt = 1; tt <= test; tt++) {
            String nums = in.nextLine();
            StringTokenizer st = new StringTokenizer(nums);
            int L = Integer.parseInt(st.nextToken());
            long t = Long.parseLong(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            Planet[] p = new Planet[C + 1];
            for (int i = 0 ; i < C + 1 ; i++)
                p[i] = new Planet(0 , 0);
            for (int i = 0; i < C; i++) {
                int x = Integer.parseInt(st.nextToken());
                p[i] = new Planet(x, N / C);
            }
            int cur = 0;
            for (int i = (N / C) * C; i < N; i++, cur++) {
                p[cur].cnt++;
            }
            long curT = 0;
            cur = 0;
            int curN = 0;
            while (curT < t && curN < N) {
                curT += (long)p[cur].d * 2;
                p[cur].cnt--;
                cur = (cur + 1) % C;
                curN++;
                if (curT > t) {
                    p[C] = new Planet((int) ((curT - t) / 2) , 1);
                    C++;
                    curT = t;
                    curN--;

                } else if (curT == t) {
                    p[C] = new Planet(0 , 0);
                }
            }
            Arrays.sort(p);
            cur = 0;
            while (curN < N) {
                while (p[cur].cnt == 0) {
                    cur = (cur + 1) % C;
                }
                if (L > 0) {
                    curT += (long)p[cur].d;
                    L--;
                } else {
                    curT += (long)p[cur].d * 2;
                }
                p[cur].cnt--;
                curN++;
            }
            out.println("Case #" + tt + ": " + curT);
        }
        out.close();
    }
}

class Planet implements Comparable<Planet> {

    int d;
    int cnt;

    public Planet(int d, int cnt) {
        this.d = d;
        this.cnt = cnt;
    }

    public int compareTo(Planet o) {
        if (this.d < o.d) {
            return 1;
        } else if (this.d > o.d) {
            return -1;
        } else {
            return 0;
        }
    }
}
