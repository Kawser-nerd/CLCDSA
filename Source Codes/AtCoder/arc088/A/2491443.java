import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLong()) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            long ans = 0;
            long ai = x;

            while (ai <= y) {
                ai *= 2L;
                ans++;
            }

            System.out.println(ans);
        }
    }
}