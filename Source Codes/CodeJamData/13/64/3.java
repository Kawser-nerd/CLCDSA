import java.util.*;
public class D {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        CAS: for(int cas=1; cas<=T; cas++) {
            n = in.nextInt();
            d = in.nextInt();
            int k = in.nextInt();
            A = new int[n][d];
            for(int i=0; i<n; i++)
                for(int j=0; j<d; j++)
                    A[i][j] = in.nextInt();

            Integer[][] JUMP = new Integer[n][d]; //how far can I go if I am at roll N with # D?
            for(int i=0; i<n; i++)
                for(int j=0; j<d; j++) {
                    if(JUMP[i][j]!=null) continue;
                    int ed = i;
                    while(ok(ed,A[i][j]))
                        ed++;
                    for(int ii=i; ii<ed; ii++)
                        for(int jj=0; jj<d; jj++)
                            if(A[i][j]==A[ii][jj])
                                JUMP[ii][jj] = ed;
                }

            best_st = -1;
            best_ed = -1;
            for(int st=0; st<n; st++) {
                for(int i=0; i<d; i++) {
                    int x1 = A[st][i];
                    int ix1 = JUMP[st][i];
                    if(n-st < best_ed-best_st) continue;
                    if(ok(st-1,x1)) continue;
                    update(st, ix1-1);
                    if(k>=2 && ix1<n) {
                        for(int j=0; j<d; j++) {
                            int ix2 = ix1;
                            int x2 = A[ix2][j];
                            while(true) {
                                if(ok(ix2,x2))
                                    ix2 = JUMP[ix2][index(ix2,x2)];
                                else break;

                                if(ok(ix2, x1))
                                    ix2 = JUMP[ix2][index(ix2,x1)];
                                else break;
                            }
                            update(st, ix2-1);
                            if(k>=3 && ix2 < n) {
                                for(int l=0; l<d; l++) {
                                    int ix3 = ix2;
                                    int x3 = A[ix3][l];
                                    while(true) {
                                        boolean done = true;
                                        if(ok(ix3,x1)) {
                                            done = false;
                                            ix3 = JUMP[ix3][index(ix3,x1)];
                                        }
                                        if(ok(ix3,x2)) {
                                            done = false;
                                            ix3 = JUMP[ix3][index(ix3,x2)];
                                        }
                                        if(ok(ix3,x3)) {
                                            done = false;
                                            ix3 = JUMP[ix3][index(ix3,x3)];
                                        }
                                        if(done) break;
                                    }
                                    update(st, ix3-1);
                                }
                            }
                        }
                    }
                }
            }
            System.out.printf("Case #%d: %d %d\n", cas, best_st, best_ed);
        }
    }
    static int best_st;
    static int best_ed;
    static void update(int st, int ed) {
        int best_len = best_ed - best_st;
        int len = ed-st;
        if(best_st==-1 || len > best_len || (len==best_len && st<best_st)) {
            best_st = st;
            best_ed = ed;
        }
    }

    static int n;
    static int[][] A;
    static int d;
    static boolean ok(int roll, int x1) {
        if(roll<0 || roll >= n) return false;
        for(int i=0; i<d; i++)
            if(A[roll][i]==x1) return true;
        return false;
    }
    static int index(int roll, int x) {
        if(roll<0 || roll >= n) return -1;
        for(int i=0; i<d; i++)
            if(A[roll][i]==x) return i;
        return -1;
    }
}
