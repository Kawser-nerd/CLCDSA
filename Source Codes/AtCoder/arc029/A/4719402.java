import java.util.Scanner;

public class Main {
    private static int loast(int[] t, int n, int i, int a, int b) {
        if(i == n) return Math.max(a, b);

        return Math.min(loast(t, n, i + 1, a + t[i], b), loast(t, n, i + 1, a, b + t[i]));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] t = new int[n];
        for(int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
        }
        System.out.println(loast(t, n, 0, 0, 0));

        sc.close();
    }
}