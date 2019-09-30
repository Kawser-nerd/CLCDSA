import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] h = new int[r];
        int[] w = new int[c];
        for (int i = 0; i < n ; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            h[a[i] - 1]++;
            w[b[i] - 1]++;
        }

        int[] hn = new int[100001];
        int[] wn = new int[100001];
        for (int i = 0; i < c ; i++) {
            hn[w[i]]++;
        }
        for (int i = 0; i < r ; i++) {
            wn[h[i]]++;
        }

        long count = 0;
        for (int i = 0 ; i <= k ; i++) {
            count += (long) hn[i] * wn[k - i];
        }

        for (int i = 0 ; i < n ; i++) {
            int sum = h[a[i] - 1] + w[b[i] - 1];
            if (sum == k ) {
                count--;
            }
            if (sum == k + 1) {
                count++;
            }
        }
        System.out.println(count);
    }

}