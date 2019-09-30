import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] a = new int[n];
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int idx = n - 1;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (idx < 0) break;
            ans[i] = a[idx--];
            if (idx < 0) break;
            ans[j] = a[idx--];
        }

        for (int i : ans) {
            System.out.print(i + " ");
        }



    }
}