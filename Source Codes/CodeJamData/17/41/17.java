import java.util.*;

class A {
    public static void main (String [] arg) {
        Scanner sc = new Scanner(System.in);
        int TT = sc.nextInt();
        for (int ii = 1; ii<= TT; ++ii) {
            int N = sc.nextInt();
            int P = sc.nextInt();
            int [] M = new int [5];
            for (int i = 0; i<N; ++i) {
                int G = sc.nextInt();
                M[G % P]++;
            }
            int ans = 1 + M[0];
            if (P == 2) {
                ans += M[1]/2;
                if (M[1] % 2 == 0) ans--;
            } else if (P == 3) {
                int min = Math.min(M[1], M[2]);
                int left = Math.max(M[1], M[2]) - min;
                if (left % 3 == 0) ans--;
                left /= 3;
                ans += min + left;
            } else if (P == 4) {
                // TBA
                while (M[2] >= 2) {
                    ans++;
                    M[2] -= 2;
                }
                while (M[1] > 0 && M[3] > 0) {
                    ans++;
                    M[1]--;
                    M[3]--;
                }
                
                if (M[2] == 1) {
                    if (M[1] % 4 >= 2) {
                        ans++;
                        M[1] -= 2;
                        M[2]--;
                    } else if (M[3] % 4 >= 2) {
                        ans++;
                        M[3] -= 2;
                        M[2]--;
                    }
                }
                int threes = M[3] / 4;
                int ones = M[1] / 4;
                ans += threes + ones;
                if (M[1] % 4 == 0 && M[3] % 4 == 0 && M[2] % 2 == 0) {
                    ans--;
                }
            }
            
            System.out.printf("Case #%d: %d\n", ii, ans);
        }
    }
}