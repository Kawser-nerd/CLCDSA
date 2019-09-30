import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }
        Arrays.sort(c);
        if (n % 2 == 1) {
            for (int i = 0; i < n; i++) {
                if (c[i] % 2 != 0) {
                    System.out.println(0);
                    return;
                } else {
                    if (i == 0 && c[i] != 0) {
                        System.out.println(0);
                        return;
                    } else if (i != 0 && c[i] != ((i - 1) / 2 + 1) * 2) {
                        System.out.println(0);
                        return;
                    }
                }
            }
            System.out.println(new BigDecimal(2).pow((n - 1) / 2).remainder(new BigDecimal(1000_000_007)));
        } else {
            for (int i = 0; i < n; i++) {
                if (c[i] % 2 != 1 || c[i] != i / 2 * 2 + 1) {
                    System.out.println(0);
                    return;
                }
            }
            System.out.println(new BigDecimal(2).pow(n / 2).remainder(new BigDecimal(1000_000_007)));
        }

    }
}