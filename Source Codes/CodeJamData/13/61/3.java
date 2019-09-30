import java.util.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int cas=1; cas<=T; cas++) {
            int c = in.nextInt();
            int x = in.nextInt();
            int n = in.nextInt();
            int[][] A = new int[c][4];
            for(int i=0; i<c; i++) {
                A[i][0] = in.nextInt()-1;
                A[i][1] = in.nextInt()-1;
                A[i][2] = in.nextInt();
                A[i][3] = A[i][2] + ((A[i][1]-A[i][0]+n)%n);
            }

            int ans = 0;
            for(int t0=0; t0<=x; t0++)
                for(int n0=0; n0<n; n0++) {
                    T1: for(int t1=t0; t1<=x; t1++) {
                        boolean must_leave = false;


                        int my_pos = n0 - (t1-t0);
                        while(my_pos < 0) my_pos+=n;
                        for(int i=0; i<c; i++) {
                            if(t1<A[i][2] || t1 > A[i][3]) continue;
                            int pos = (A[i][0]+ t1-A[i][2])%n;

                            System.out.println(pos+" "+my_pos);

                            if(pos == my_pos) break T1;
                            if(pos!=A[i][1] && (pos+1)%n == my_pos) must_leave = true;
                        }
                        ans = Math.max(ans, t1-t0);
                        if(must_leave) break T1;
                    }
                }
            System.out.printf("Case #%d: %d\n", cas, ans);
        }
    }
}
