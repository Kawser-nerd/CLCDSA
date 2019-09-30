import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int min = 0;
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                min = a[i];
                max = a[i];
                continue;
            }
            if (a[i] < min) {
                min = a[i];
            }
            if (a[i] > max) {
                max = a[i];
            }
        }
        System.out.println(max - min);
    }

}