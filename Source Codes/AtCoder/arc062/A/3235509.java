import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            long t = 1;
            long a = 1;

            for (int i = 0; i < N; i++) {
                long T = sc.nextLong();
                long A = sc.nextLong();

                long tx = -1;
                long ax = -1;

                for (int ti = 0; ti < T; ti++) {
                    if ( (t + ti) % T == 0 ) {
                        tx = t + ti;
                        ax = (tx / T) * A;
                    }
                }

                long ty = -1;
                long ay = -1;

                for (int ai = 0; ai < A; ai++) {
                    if ( (a + ai) % A == 0 ) {
                        ay = a + ai;
                        ty = (ay / A) * T;
                    }
                }

                long tn = -1;
                long an = -1;

                if ( tx >= t && ax >= a ) {
                    tn = tx;
                    an = ax;
                }

                if ( tn == -1 || ty >= t && ay >= a && (ty + ay) < (tn + an) ) {
                    tn = ty;
                    an = ay;
                }

                t = tn;
                a = an;

                if ( t == -1 ) {
                    int zero = 1 / 2;
                    int hoge = 10 / zero;
                }
            }

            System.out.println(t + a);
        }
    }
}