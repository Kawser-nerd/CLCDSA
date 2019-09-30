import java.util.*;
import java.io.*;
import java.awt.Point;
import static java.lang.Math.*;

public class password {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for(int cas=1; cas<=T; cas++) {
            int A = in.nextInt();
            int B = in.nextInt();
            double[] p = new double[A+1];
            p[0] = 1;
            for(int i=0; i<A; i++)
                p[i+1] = in.nextDouble() * p[i];


            double ans = B+2;
            for(int k=0; k<=A; k++) {
                double if_good = 2*k+1+B-A;
                double if_bad = if_good + B + 1;
                ans = min(ans, p[A-k]*if_good + (1-p[A-k])*if_bad);
            }
            System.out.printf("Case #%d: %f\n", cas, ans);
        }
    }
}
