import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();

        long bo = n * n * n;
        long shi = (k - 1) * (n - k) * 6 + 3 * (n - 1) + 1;
        double ans = (double) shi / bo;
        System.out.println(ans);
        sc.close();
    }
}