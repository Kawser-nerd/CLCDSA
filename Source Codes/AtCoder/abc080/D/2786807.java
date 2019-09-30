import java.util.*;

public class Main {
    static int modP = 1000000007;
    static long inf  = 1 << 61;

    static int n, c;
    static int[] S, T, C;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        c = in.nextInt();
        S = new int[n];
        T = new int[n];
        C = new int[n];
        for(int i = 0; i < n; i++) {
            S[i] = in.nextInt();
            T[i] = in.nextInt();
            C[i] = in.nextInt();
        }

        int[] memo = new int[200005];
        int[] counts = new int[200005];
        for(int j = 1; j <= c; j++) {
            Arrays.fill(memo, 0);
            for(int i = 0; i < n; i++) {
                if(j == C[i]) {
                    int si = S[i];
                    int ti = T[i];
                    memo[2*si-1]++;
                    memo[2*ti]--;
                }
            }
            for(int i = 1; i < 200005; i++) {
                memo[i] += memo[i-1];
            }
            for(int i = 0; i < 200005; i++) {
                if(memo[i] > 0) {
                    counts[i]++;
                }
            }
        }

        int ans = Arrays.stream(counts).max().getAsInt();
        print(ans);
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }

    static void print(long i) {
        System.out.println(i);
    }

    static void print(float i) {
        System.out.println(i);
    }
}