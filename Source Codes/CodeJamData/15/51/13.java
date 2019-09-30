import java.util.*;
import static java.lang.Math.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int zz = 1; zz <= T; zz++) {
            int N = in.nextInt();
            int D = in.nextInt();
            long S0 = in.nextInt();
            long As = in.nextInt();
            long Cs = in.nextInt();
            long Rs = in.nextInt();
            long M0 = in.nextInt();
            long Am = in.nextInt();
            long Cm = in.nextInt();
            long Rm = in.nextInt();

            int[] P = new int[N];
            int[] S = new int[N];
            P[0] = (int)M0;
            S[0] = (int)S0;
            for (int i = 1; i < N; i++) {
                P[i] = (int)((P[i-1] * Am + Cm) % Rm);
                S[i] = (int)((S[i-1] * As + Cs) % Rs);
            }

            int[] L = new int[N];
            int[] H = new int[N];
            L[0] = S[0];
            H[0] = S[0];
            ArrayList<Integer> add = new ArrayList<Integer>();
            ArrayList<Integer> remove = new ArrayList<Integer>();
            for (int i = 0; i < N; i++) {
                if (i != 0) {
                    P[i] %= i;
                    L[i] = L[P[i]];
                    H[i] = H[P[i]];
                    L[i] = min(L[i], S[i]);
                    H[i] = max(H[i], S[i]);
                }

                int a = H[i] - D;
                int r = L[i];
                //System.out.println(i+" "+a+" "+r);
                if (a <= r) {
                    add.add(a);
                    remove.add(r);
                }
            }
            Collections.sort(add);
            Collections.sort(remove);
            int aat = 0;
            int rat = 0;
            int total = 0;
            int ans = 0;
            while (aat < add.size() && rat < remove.size()) {
                if (add.get(aat) <= remove.get(rat)) {
                    total++;
                    aat++;
                } else {
                    total--;
                    rat++;
                }
                ans = max(ans, total);
            }
            System.out.format("Case #%d: %d\n", zz, ans);
        }
    }
}
