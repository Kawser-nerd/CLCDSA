import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[][] a = new int[n][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
        }
        Arrays.sort(a, (x, y) -> x[0] - y[0]);
        long sum = 0;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][1];
            if(sum >= k){
                ans = a[i][0];
                break;
            }
        }

        System.out.println(ans);
        sc.close();
    }

}