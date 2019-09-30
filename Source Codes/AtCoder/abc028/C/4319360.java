import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int e = sc.nextInt();
        int[] sum = new int[10];
        int tmp = a + b;
        sum[0] = tmp + c;
        sum[1] = tmp + d;
        sum[2] = tmp + e;
        tmp = a + c;
        sum[3] = tmp + d;
        sum[4] = tmp + e;
        sum[5] = a + d + e;
        tmp = b + c;
        sum[6] = tmp + d;
        sum[7] = tmp + e;
        sum[8] = b + d + e;
        sum[9] = c + d + e;
        Arrays.sort(sum);
        System.out.println(sum[7]);
    }
}