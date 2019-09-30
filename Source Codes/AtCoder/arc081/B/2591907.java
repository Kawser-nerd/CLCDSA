import java.util.*;

public class Main {

    private static final int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S1 = sc.next();
        String S2 = sc.next();
        System.out.println( solve(N, S1, S2) );
    }

    private static int solve(int N, String S1, String S2) {
        long ans;
        boolean prev_tate;
        int i;
        if( S1.charAt(0) == S2.charAt(0) ) {
            //??
            prev_tate = true;
            i = 1;
            ans = 3;

        } else {
            // ?
            prev_tate = false;
            i = 2;
            ans = 6;
        }

        while( N > i ) {
            if( S1.charAt(i) == S2.charAt(i) ) {
                if( prev_tate ) {
                    ans = ans * 2 % MOD;
                }
                i++;
                prev_tate = true;

            } else {
                if( prev_tate ) {
                    ans = ans * 2 % MOD;
                } else {
                    ans = ans * 3 % MOD;
                }
                i = i+2;
                prev_tate = false;
            }
        }
        return (int)ans;
    }
}