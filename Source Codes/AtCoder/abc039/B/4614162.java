import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long x = sc.nextLong();

        int ans = 1;
        for (int i = 1; i < x; i++) {
            long tmp = i * i * i * i;
            if (tmp == x) {
                ans = i;
                break;
            } else if (tmp > x)   break; // ????
        }

        System.out.println(ans);
    }
}