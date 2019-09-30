import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] t = new int[n + 2], v = new int[n + 2];
        int tSum = 0;
        for (int i = 1; i <= n; i++) {
            t[i] = in.nextInt() * 2;
            tSum += t[i];
        }
        for (int i = 1; i <= n; i++) {
            v[i] = in.nextInt();
        }
        double[] vMax = new double[tSum + 1];
        int idx = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < t[i]; j++) {
                vMax[idx + j] = v[i];
            }
            idx += t[i];
        }
//        System.out.println(Arrays.toString(vMax));
        idx = 0;
        for (int i = 0; i < n; i++) {
            double max = v[i];
            int tmp = idx + 1;
            while(max < vMax[tmp]) {
                max += 0.5;
                vMax[tmp++] = max;
                if(vMax.length <= tmp) break;
            }
            idx += t[i+1];
        }
        idx = tSum + 1;
        for (int i = n+1; i > 0 ; i--) {
            double max = v[i];
            int tmp = idx - 1;
            while(max < vMax[tmp]) {
                vMax[tmp--] = max;
                max += 0.5;
                if(tmp < 0) break;
            }
            idx -= t[i-1];
        }
//        for (int i = 0; i < vMax.length; i++) {
//            System.out.println("idx = " + i  + " time = " + (i / 2.0) + " v = " + vMax[i]);
//        }
        double ans = 0, now = 0;
        for (int i = 0; i < vMax.length - 1; i++) {
            ans += now * 0.5;
            if(vMax[i] < vMax[i + 1]) {
                ans += 0.125;
                now += 0.5;
            }
            if(vMax[i + 1] < vMax[i]) {
                ans -= 0.125;
                now -= 0.5;
            }
        }
        System.out.println(ans);
    }
}