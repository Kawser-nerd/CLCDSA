import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] a = {0, 0, 1};
        for (int i = 2; i < n; i++) {
            int tmp = (a[0] + a[1] + a[2]) % 10007;
            a[0] = a[1];
            a[1] = a[2];
            a[2] = tmp;
        }
        System.out.println(a[1]);
    }
}