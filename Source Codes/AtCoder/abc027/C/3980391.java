import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long count = 1;
        long n2 = n;
        while(n2 / 2 > 0) {
            n2 /= 2;
            count++;
        }
        long x = 1;
        for (int i = 1 ; i <= count ; i++) {
            if (count % 2 == 1) {
                if (i % 2 == 0) {
                    x *= 2;
                } else {
                    x = 2 * x + 1;
                }
            } else {
                if (i % 2 == 0) {
                    x = 2 * x + 1;
                } else {
                    x *= 2;
                }
            }
            if (x > n) {
                if (i % 2 == 0) {
                    System.out.println("Takahashi");
                    return;
                } else {
                    System.out.println("Aoki");
                    return;
                }
            }
        }
    }

}