import java.util.*;

public class Main {
    public static long[] buildValues(int d) {
        long[] res = new long[d/2];
        long high = (long) Math.pow(10, d - 1);
        long low = 1L;
        for (int i = 0; i < d / 2; i++) {
            res[i] = high - low;
            high /= 10;
            low *= 10;
        }

        return res;
    }

    public static long calc(long[] vs, long D) {
        long res = 1;
        long ten = 10;
        for (int i = 0; i < vs.length; i++) {
            long now = 0;
            while (D % ten != 0 && now < 9) {
                D -= vs[i];
                now++;
            }
            D = Math.abs(D);
            ten *= 10;
            res *= (i == 0) ? (9 - now) : (10 - now);
        }
        return D == 0 ? res : 0;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int D = in.nextInt();

        long res = 0;
        for (int d = 1; d <= 20; d++) {
            long[] vs = buildValues(d);
            long next = calc(vs, D);
            if (d % 2 == 1) next *= 10;
            res += next;
        }
        System.out.println(res);
    }
    /*
    a = 10x + y
    b = 10y + x
    a - b = 9x - 9y = 9(x - y)

    a = 100x + 10y + z
    b = 100z + 10y + x
    a - b = 99x - 99z = 99(x - z) + 0y

    a = 1000x + 100y + 10z + w
    b = 1000w + 100z + 10y + x
    a - b = 999x - 999w + 90y - 90z = 999(x - w) + 90(y - z)

    a = 10000x + 1000y + 100z + 10w + v
    b = 10000v + 1000w + 100z + 10y + x
    a - b = 9999(x - v) + 990(y - w) + 0z

    a = 100000x + 10000y + 1000z + 100w + 10v + u
    b = 100000u + 10000v + 1000w + 100z + 10y + x
    a - b = 99999(x - u) + 9990(y - v) + 900(z - w)
    */
    static int rev(int x) {
        String s = "0";
        while (x > 0) {
            s += x % 10 + "";
            x /= 10;
        }
        return Integer.valueOf(s);
    }
}