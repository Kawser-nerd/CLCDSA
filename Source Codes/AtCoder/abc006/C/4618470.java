import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.close();
        if (2 * n > m || 4 * n < m) {
            System.out.println("-1 -1 -1");
            return;
        }
        int remain = m - 2 * n;
        String ans = "";
        if (remain <= n) {
            ans = n - remain + " " + remain + " " + 0;
        } else if (remain <= n * 2) {
            int tmp = 2 * n - remain;
            ans = "0 " + tmp + " " + (remain - n);

        }
        System.out.println(ans);
    }
}