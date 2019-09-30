import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        int ans = dfs(N, 0);
        out.println(ans);
    }

    // org?10??????int????????????????long org
    public static int dfs(long N, long org) {
        if (N < org) { return 0;}

        int ret = 0;
        if(have753(org)){ ret++; }

        int[] nums = {7, 5, 3};
        for (int num : nums) {
            ret += dfs(N, org * 10 + num);
        }
        return ret;
    }

    public static boolean have753(long num){
        boolean[] isExists = new boolean[10];
        while(num > 0){
            int rest = (int)(num % 10);
            num = num / 10;
            isExists[rest] = true;
        }

        return isExists[3] & isExists[5] & isExists[7];
    }
}