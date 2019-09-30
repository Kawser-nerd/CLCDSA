import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long x = (new Scanner(System.in)).nextLong();
        long ans = x / 11 * 2;
        x %= 11;
        System.out.println(ans + (x == 0 ? 0 : x > 6 ? 2 : 1));
    }
}