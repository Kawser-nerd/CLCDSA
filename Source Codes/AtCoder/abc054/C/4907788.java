/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

class Main{

    static int n;
    static int m;
    static int ans;
    static int[] w;
    static int[] ww;
    static boolean[] visit;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        m = sc.nextInt();
        w = new int[m];
        ww = new int[m];
        
        for (int i = 0; i < m; i++) {
            int tmp = sc.nextInt();
            int tmpp = sc.nextInt();
            w[i] = tmp-1;
            ww[i] = tmpp-1;
        }

        visit  = new boolean[n];
        Arrays.fill(visit, false);
        dfs(0);
        System.out.println(ans);
        sc.close();
    }

    public static void dfs(int placenow) {
        visit[placenow] = true;
        boolean success = true;
        for (int i = 0; i < n; i++) {
            if (visit[i] == false) { // not go all place
                success = false;
                break;
            }
        }
        if (success) {
            ans++;
            visit[placenow] = false;
            return;
        }

        for (int i = 0; i < m; i++) {
            if (w[i] == placenow && visit[ww[i]] == false ) {
                dfs(ww[i]);
            }else if(ww[i] == placenow && visit[w[i]] == false){
                dfs(w[i]);
            }else{
                continue;
            }
        }
        visit[placenow] = false;
        return;
    }

}