import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long h = sc.nextInt();
        long w = sc.nextInt();
        long a1 = calc(h, w);
        long a2 = calc(w, h);
        long ans = a1 > a2 ? a2 : a1;
        System.out.println(ans);
    }

    public static long calc(long i1, long i2) {
        long[] ss = new long[3];
        long ans = Long.MAX_VALUE;
        long sMax, sMin;
        for (int j = 1; j < i1; j++) {
            ss[0] = j * i2;
            for (int k = 0; k < 2; k++) {
                sMax = Long.MIN_VALUE;
                sMin = Long.MAX_VALUE;
                if (k == 0)
                    ss[1] = (i1 - j) * (i2 / 2);
                else
                    ss[1] = ((i1 - j) / 2) * i2;
                ss[2] = (i1 * i2) - (ss[0] + ss[1]);
                for (int i = 0; i < 3; i++) {
                    if (sMax < ss[i])
                        sMax = ss[i];
                    if (sMin > ss[i])
                        sMin = ss[i];
                }
                if (ans > (sMax - sMin))
                    ans = sMax - sMin;
            }
        }
        return ans;
    } 
}