import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                continue;
            }
            int yakusuu = 0;
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) {
                    yakusuu++;
                }
            }
            if (yakusuu == 8) {
                count++;
            }
        }
        System.out.println(count);
    }

}