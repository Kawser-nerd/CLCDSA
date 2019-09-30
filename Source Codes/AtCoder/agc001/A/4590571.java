import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Integer[] L = new Integer[2*N];
        for (int i = 0; i < 2*N; i++) {
            L[i] = sc.nextInt();
        }

        Arrays.sort(L, Collections.reverseOrder());

        int ans = 0;
        for(int i = 0; i < N; i++){
            ans += Math.min(L[2*i],L[2*i+1]);
        }

        out.println(ans);
    }
}