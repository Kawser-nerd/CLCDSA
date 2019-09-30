import java.util.*;
import java.io.*;
import java.awt.Point;
import static java.lang.Math.*;

public class rush {
    static Comparator<int[]> cmp = new Comparator<int[]>() {
        public int compare(int[] A, int[] B) {
            if(A[0] != B[0]) return A[0] - B[0];
            return A[1] - B[1];
        }
    };
    static Comparator<int[]> cmp2 = new Comparator<int[]>() {
        public int compare(int[] A, int[] B) {
            if(A[0] != B[0]) return A[0] - B[0];
            if(A[1] != B[1]) return B[1] - A[1];
            return A[1] - B[1];
        }
    };
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int TE = in.nextInt();
        CASE: for(int cas=1; cas<=TE; cas++) {
            TreeSet<int[]> T = new TreeSet<int[]>(cmp);
            TreeSet<int[]> O = new TreeSet<int[]>(cmp2);
            int n = in.nextInt();
            int[][] P = new int[n][2];
            int[] done = new int[n];
            for(int i=0; i<n; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                P[i] = new int[]{a,b};
                T.add(new int[]{b,i});
                O.add(new int[]{a,b,i});
            }

            int ans = 0;
            int cur = 0;
OUTER:
            while(cur < 2*n) {
                ans++;
                //Take any 2s
                //Take 1 with most expensive 2
                int best_o = -1;
                for(int i=0; i<n; i++) {
                    if(cur >= P[i][1] && done[i]<2) {
                        cur += 2-done[i];
                        done[i] = 2;
                        continue OUTER;
                    }
                    if(cur >= P[i][0] && done[i]<1 && (best_o==-1 || P[i][1] >= P[best_o][1]))
                        best_o = i;
                }
                if(best_o == -1) {
                    System.out.printf("Case #%d: Too Bad\n", cas);
                    continue CASE;
                }
                else {
                    cur++;
                    done[best_o] = 1;
                }
            }
            System.out.printf("Case #%d: %d\n", cas, ans);
        }
    }
}
