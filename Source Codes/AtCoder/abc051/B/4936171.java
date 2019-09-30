import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        int ans = 0;
        for (int i = 0; i <= Math.min(s, k); i++) {
            ans += Math.max(0, Math.min(s-i+1, k+1)-Math.max(0,s-i-k));
        }

        System.out.println(ans);
    }

}