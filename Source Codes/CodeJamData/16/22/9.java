import java.util.*;
import static java.lang.Math.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            String c = in.next();
            String j = in.next();
            int N = c.length();
            int[] C = new int[N];
            int[] J = new int[N];
            for (int i = 0; i < N; i++) {
                C[i] = c.charAt(i) == '?' ? -1 : (int)(c.charAt(i)-'0');
                J[i] = j.charAt(i) == '?' ? -1 : (int)(j.charAt(i)-'0');
            }

            ac = Long.MAX_VALUE;
            aj = 0;

            for (int i = 0; i < N; i++) {
                solve(copy(C), copy(J), N, i, false);
                solve(copy(J), copy(C), N, i, true);
            }
            for (int i = 0; i < N; i++) {
                if (C[i] == -1 && J[i] == -1) {
                    C[i] = 0;
                    J[i] = 0;
                } else if (C[i] == -1) {
                    C[i] = J[i];
                } else if (J[i] == -1) {
                    J[i] = C[i];
                }
            }
            test(C, J);
            String AC = Long.toString(ac);
            while (AC.length() < N)
                AC = "0" + AC;
            String AJ = Long.toString(aj);
            while (AJ.length() < N)
                AJ = "0" + AJ;
            System.out.format("Case #%d: %s %s\n", zz, AC, AJ);
        }
    }
    static long ac, aj;
    static int[] copy(int[] A) {
        int[] B = new int[A.length];
        for (int i = 0; i < A.length; i++)
            B[i] = A[i];
        return B;
    }

    // a lower than B
    static void solve(int[] A, int[] B, int N, int split, boolean back) {
        if (A[split] == -1 && B[split] == -1) {
            A[split] = 0;
            B[split] = 1;
        }
        if (A[split] == -1) {
            if (B[split] == 0)
                return;
            A[split] = B[split] - 1;
        }
        if (B[split] == -1) {
            if (A[split] == 9)
                return;
            B[split] = A[split] + 1;
        }
        for (int i = 0; i < split; i++) {
            if (A[i] == -1 && B[i] == -1) {
                A[i] = 0;
                B[i] = 0;
            } else if (A[i] == -1) {
                A[i] = B[i];
            } else if (B[i] == -1) {
                B[i] = A[i];
            }
        }
        for (int j = split + 1; j < N; j++) {
            if (A[j] == -1)
                A[j] = 9;
            if (B[j] == -1)
                B[j] = 0;
        }
        if (back) {
            test(B, A);
        } else {
            test(A, B);
        }
    }
    static void test(int[] A, int[] B) {
        long a = get(A);
        long b = get(B);
        //System.out.println("\ttest " + a +" "+ b);
        if (abs(a-b) < abs(ac-aj)) {
            ac = a;
            aj = b;
            return;
        } else if (abs(a-b) > abs(ac-aj)) {
            return;
        }
        if (a < ac) {
            ac = a;
            aj = b;
            return;
        } else if (a > ac) {
            return;
        }
        if (b < aj) {
            ac = a;
            aj = b;
            return;
        }
    }
    static long get(int[] A) {
        long ans = 0;
        for (int i = 0; i < A.length; i++) {
            ans *= 10;
            ans += A[i];
            if (A[i] == -1) {
                throw new RuntimeException();
            }
        }
        return ans;
    }
}
