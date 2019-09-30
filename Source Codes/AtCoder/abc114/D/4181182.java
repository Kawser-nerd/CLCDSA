import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        int N = sc.nextInt();
        int[] p = {2,3,5,7,11,13,17,
                   19,23,29,31,37,41,
                   43,47,53,59,61,67,
                   71,73,79,83,89,97};
        int[] pTotal = new int[p.length];
        for(int i = 0; i < p.length; i++) pTotal[i] = legendre(N, p[i]);

        int ans = 0;
        for(int i = 0; i < p.length; i++) {
            if(pTotal[i] >= 74) ans++;
        }

        for(int i = 0; i < p.length; i++) {
            for(int j = 0; j < p.length; j++) {
                if(i != j && pTotal[i] >= 2 && pTotal[j] >= 24)
                    ans++;
            }
        }

        for(int i = 0; i < p.length; i++) {
            for(int j = 0; j < p.length; j++) {
                if(i != j && pTotal[i] >= 4 && pTotal[j] >= 14)
                    ans++;
            }
        }

        int plus = 0;
        for(int i = 0; i < p.length; i++) {
            for(int j = 0; j < p.length; j++) {
                for(int k = 0; k < p.length; k++) {
                    if(i != j && j != k && k != i && pTotal[i] >= 2 && pTotal[j] >= 4 && pTotal[k] >= 4)
                        plus++;
                }
            }
        }

        ans += plus/2;

        System.out.println(ans);
    }

    static int legendre(int n, int p) {
        int c = 0;
        int m = p;
        while(m <= n) {
            c += n / m;
            m *= p;
        }
        return c;
    }
}