import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        String s = String.valueOf(n);
        int l = s.length();
        if (l == 1) {
            System.out.println(n);
        } else {
            boolean nine = true;
            for (int i = 1; i < l; i++) {
                if (s.charAt(i) != '9') {
                    nine = false;
                    break;
                }
            }
            if (nine) {
                System.out.println(9 * (l - 1) + n / (long)(Math.pow(10, l - 1)));
            } else {
                System.out.println(9 * (l - 1) + n / (long)(Math.pow(10, l - 1)) - 1);
            }

        }
    }
}