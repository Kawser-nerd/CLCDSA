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
    static int[] rate;
    static int var;
    static int ansmin;
    static int ansmax;
    static int[] w;
    static int[] ww;
    static boolean[] visit;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        ansmin = 0;
        ansmax = 0;
        rate = new int[9];
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            if (tmp >= 3200) {
                tmp = 3200;
            }
            rate[tmp/400]++;
        }
        for (int i = 0; i < 7; i++) {
            if (rate[i] != 0) {
                ansmin++;
                ansmax++;
            }
        }
        if (rate[7] == 0) {
            if (rate[8] != 0) {
                ansmin++;
                ansmax+=rate[8];
            }
        }else{
            ansmin++;
            ansmax++;
            if (rate[8] != 0) {
                ansmax+=(rate[8]);
            }
        }

        System.out.println(ansmin + " " + ansmax);

        sc.close();
    }

    public static void dfs(int placenow) {
        // if went all -> success! 
        // if not went all -> fail...
        
        /*
         dfs
         Go All Place that there is way to and not having been yet. 

         if island 1 is start point, dfs(1);
         if there is way to island 2 and island 3,
         - island 2 changes non-visited -> visited, and dfs(2).
         - island 3 changes non-visited -> visited, and dfs(3).
         

        */

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