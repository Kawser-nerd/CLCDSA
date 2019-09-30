import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] l = new int[q];
        int[] r = new int[q];
        int[] t = new int[q];
        for (int i = 0; i < q; i++) {
            l[i] = sc.nextInt();
            r[i] = sc.nextInt();
            t[i] = sc.nextInt();
        }
        int[] ans = new int[n + 1];
        for (int i = 0; i < q; i++) {
            for (int j = l[i]; j <= r[i]; j++) {
                ans[j] = t[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            System.out.println(ans[i]);
        }
        sc.close();
    }
}