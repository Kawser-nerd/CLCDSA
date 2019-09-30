import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i<n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();
        int prev = -1;
        int ren = 1;
        int ans = 0;
        for (int i = 0; i<n; i++) {
            //System.out.println(prev+","+ren+","+ans);
            if (prev==a[i]) ren++;
            else {
                ans += (ren/2);
                ren = 1;
            }
            prev = a[i];
        }
        ans += (ren/2);
        System.out.println(ans);
    }
}