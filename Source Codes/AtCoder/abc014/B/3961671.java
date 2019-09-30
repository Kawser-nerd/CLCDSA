import java.util.Scanner;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
 
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextInt();
            b[i] = x % 2;
            x /= 2;
        }
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            ans += a[i] * b[i];
        }
        System.out.println(ans);
 
    }
 
}