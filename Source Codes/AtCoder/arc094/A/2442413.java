import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        int n[] = new int[3];
        for (int i = 0; i < 3; i++) {
            n[i] = sc.nextInt();
        }

        Arrays.sort(n);

        int cnt = 0;

        int tmp = (n[2] - n[0]) / 2;
        n[0] += tmp * 2;
        cnt += tmp;

        tmp = (n[2] - n[1]) / 2;
        n[1] += tmp * 2;
        cnt += tmp;

        tmp = n[0] + n[1] - 2 * n[2] + 3;
        cnt += tmp % 3;

        System.out.println(cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}