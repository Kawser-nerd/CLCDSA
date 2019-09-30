import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[100100];
        for (int i = 0; i < N; ++i) A[i] = sc.nextInt();
        int res = A[0];
        for (int i = 0; i < N; ++i) {
            res = gcd(res, A[i]);
        }
        System.out.println(res);
    }
    private static int gcd(int x, int y) {
        if (y > 0) return gcd(y, x % y);
        return x;
    }
}