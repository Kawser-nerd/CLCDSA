import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int count = 0;
        int p = 0;
        for (int i = 0 ; i < n - 1 ; i++) {
            if (p == 0) {
                p = a[i + 1] - a[i];
            } else if (p > 0) {
                if (a[i + 1] - a[i] < 0) {
                    count++;
                    p = 0;
                }
            } else {
                if (a[i + 1] - a[i] > 0) {
                    count++;
                    p = 0;
                }
            }
        }

        System.out.println(count + 1);
    }

}