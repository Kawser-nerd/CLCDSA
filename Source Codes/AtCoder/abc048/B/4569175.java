import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long a = sc.nextLong();
        long b = sc.nextLong();
        long x = sc.nextLong();

        a = a > 0 ? (a-1) / x + 1 : 0;
        b = b / x + 1;
        long cnt = b - a;

        System.out.println(cnt);
    }
}