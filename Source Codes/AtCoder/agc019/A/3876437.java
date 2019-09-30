import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long q = sc.nextInt();
        long h = sc.nextInt();
        long s = sc.nextInt();
        long d = sc.nextInt();
        long n = sc.nextInt();
        long money = 0;
        long v[] = new long[4];
        v[0] = q * 8;
        v[1] = h * 4;
        v[2] = s * 2;
        v[3] = d;
        if (v[0] <= v[1] && v[0] <= v[2] && v[0] <= v[3]) {
            money = n * 4 * q;
        } else if (v[1] <= v[2] && v[1] <= v[3]) {
            money = n * 2 * h;
        } else if (v[2] <= v[3]) {
            money = n * s;
        } else if (n % 2 == 0) {
            money = n / 2 * d;
        } else if (v[0] <= v[1] && v[0] <= v[2]) {
            money = n / 2 * d + q * 4;
        } else if (v[1] <= v[2]) {
            money = n / 2 * d + h * 2;
        } else {
            money = n / 2 * d + s;
        }
        System.out.println(money);
    }
}