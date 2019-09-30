import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        String N = sc.next();
        char[] n = N.toCharArray();
        boolean[] ans = new boolean[4];
        for (int i = 0; i < N.length(); i++) {
            if (n[i] == 'N') {
                ans[0] = true;
            } else if (n[i] == 'W') {
                ans[1] = true;
            } else if (n[i] == 'S') {
                ans[2] = true;
            } else if (n[i] == 'E') {
                ans[3] = true;
            }
        }
        if((ans[0]==ans[2])&&(ans[1]==ans[3])){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}