/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

class Main{

    static int n;
    static int c;
    static int k;
    static int lef;
    static int rig;
    static String s;
    static String anss;
    static int[] times;
    static long ans;
    static int[] w;
    static int[] ww;
    static boolean[] visit;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        ans = 0;
        String[] st = new String[n];
        long[] m = new long[5];
        for (int i = 0; i < n; i++) {
            st[i] = sc.next();
            if (st[i].charAt(0) == 'M') {
                m[0]++;
            }
            if (st[i].charAt(0) == 'A') {
                m[1]++;
            }
            if (st[i].charAt(0) == 'R') {
                m[2]++;
            }
            if (st[i].charAt(0) == 'C') {
                m[3]++;
            }
            if (st[i].charAt(0) == 'H') {
                m[4]++;
            }
        }

        System.out.println(
            m[0]*m[1]*(m[2]+m[3]+m[4]) + m[0]*m[2]*(m[3]+m[4]) + m[0]*m[3]*m[4]
                +m[1]*m[2]*(m[3]+m[4]) + m[1]*m[3]*m[4] + m[2]*m[3]*m[4]
        );

        
        sc.close();
    }

    public static long gcd(long a, long b) {
        
        if (a < b) {
            long tmpp = a;
            a = b;
            b = tmpp;
        }
        if (b == 0) {
            return a;
        }else{
            return gcd(b, a%b);
        }
    }

    public static long lcm(long a, long b) {
        long gcd = gcd(a,b);
        return a/gcd*b;
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

        for (int i = 0; i < n; i++) {
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