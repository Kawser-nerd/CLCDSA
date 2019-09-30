import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n*3];
        for (int i = 0; i < n*3; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        long ans = 0L;
        for (int i = n; i < n*3; i++) {
            if((i-n) % 2 == 0){
                ans += a[i];
            }
        }
        System.out.println(ans);
        sc.close();

    }

}