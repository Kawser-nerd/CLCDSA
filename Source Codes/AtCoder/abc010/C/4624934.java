import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int txa = sc.nextInt();
        int tya = sc.nextInt();
        int txb = sc.nextInt();
        int tyb = sc.nextInt();
        int T = sc.nextInt();
        int V = sc.nextInt();

        int n = sc.nextInt();

        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        PriorityQueue<Double> dist = new PriorityQueue<Double>();
        for (int i = 0; i < n; i++) {
            double dis = Math.sqrt(Math.pow((x[i] - txa), 2.0) + Math.pow((y[i] - tya), 2.0))
                    + Math.sqrt(Math.pow((x[i] - txb), 2.0) + Math.pow((y[i] - tyb), 2.0));
            dist.add(dis);
        }

        double maxDist = (double) T * V;
        if (dist.poll() <= maxDist) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }
}