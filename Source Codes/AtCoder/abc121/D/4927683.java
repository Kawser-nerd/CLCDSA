import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long num = 0;

        if (a % 2 == 1) {
            a = a - 1;
            num = a;
        }

        long sub = b - a;
        if (sub % 4 == 0) {
            System.out.println(b ^ num);

        } else if (sub % 4 == 1) {
            System.out.println(b ^ (b - 1) ^ num);

        } else if (sub % 4 == 2) {
            System.out.println(b ^ 1 ^ num);

        } else if (sub % 4 == 3) {
            System.out.println(b ^ (b - 1) ^ 1 ^ num);

        }
    }
}