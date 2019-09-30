import java.util.*;
public class B {
    static double L = 1000*1000;
    static double EPS = 1e-9;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        CAS: for(int cas=1; cas<=T; cas++) {
            n = in.nextInt();
            int[] A = new int[n];
            for(int i=0; i<n; i++)
                A[i] = in.nextInt();
            D = new double[n-1];
            for(int i=0; i<n-1; i++)
                D[i] = A[i+1]-A[i];

            double a_lo = -L;
            double a_hi = L;
            while(a_lo + EPS < a_hi) {
                double a1 = a_lo + (a_hi-a_lo)/3;
                double a2 = a_hi - (a_hi-a_lo)/3;
                
                double b_a1 = f1(a1);
                double b_a2 = f1(a2);

                if(f2(a1,b_a1) < f2(a2, b_a2)) {
                    a_hi = a2;
                } else {
                    a_lo = a1;
                }
            }

            double a = a_lo;
            double b = f1(a);
            double ans = f2(a,b);
            System.out.printf("Case #%d: %.8f\n", cas, ans);
        }
    }

    static double f1(double a) {
        double b_lo = -L;
        double b_hi = L;
        while(b_lo + EPS < b_hi) {
            double b1 = b_lo + (b_hi-b_lo)/3;
            double b2 = b_hi - (b_hi-b_lo)/3;
            if(f2(a,b1) < f2(a,b2)) {
                b_hi = b2;
            } else {
                b_lo = b1;
            }
        }
        return b_lo;
    }

    static int evals = 0;

    static int n;
    static double[] D;
    static double f2(double a, double b) {
        evals++;
        double[] D2 = Arrays.copyOf(D, n-1);
        D2[0] += a;
        D2[n-2] += b;


        double ans = Math.max(Math.abs(a), Math.abs(b));
        double avg = 0;
        for(int i=0; i<n-1; i++)
            avg += D2[i];
        avg /= n-1;
//        System.out.println(Arrays.toString(D2)+" "+avg);
        for(int i=0; i+1<n-1; i++) {
//            System.out.println(i+" "+D2[i]+" "+avg);
            double adjust = avg-D2[i];
            ans = Math.max(Math.abs(adjust), ans);
            D2[i] += adjust;
            D2[i+1] -= adjust;
        }
        return ans;
    }
}
