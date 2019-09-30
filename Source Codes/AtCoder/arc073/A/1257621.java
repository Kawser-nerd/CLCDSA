import java.util.Scanner;

/**
 * Created by admin on 2017/05/02.
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        long total = 0;
        long timeTotal = 0;
        scanner.nextInt();
        for (int i = 0; i < N - 1; i++) {
            int temp = scanner.nextInt();
            total += Math.min(T, temp-timeTotal);
            timeTotal=temp;
        }
        total += T;
        System.out.println(total);
    }
}