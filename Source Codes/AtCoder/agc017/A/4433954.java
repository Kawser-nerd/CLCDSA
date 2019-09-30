import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        int even = 0;
        int odd = 0;
        for (int i = 0 ; i < n ; i++) {
            int a = sc.nextInt();
            if (a % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (p == 0) {
            if (odd == 0) {
                System.out.println((long) Math.pow(2, n));
            } else {
                System.out.println((long) Math.pow(2, n - 1));
            }
        } else {
            if (odd == 0) {
                System.out.println(0);
            } else {
                System.out.println((long) Math.pow(2, n - 1));
            }
        }

    }

}