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
    static int m;
    static int height;
    static int width;
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
        
        height = sc.nextInt();
        width = sc.nextInt();
        String[] s = new String[height+2];
        boolean[][] bool = new boolean[height+2][width+2];
        boolean ans = true;
        for (int i = 0; i < height+2; i++) {
            for (int j = 0; j < width+2; j++) {
                bool[i][j] = false;
            }
        }
        

        for (int i = 1; i <= height; i++) {
            s[i] = sc.next();
            for (int j = 1; j <= width; j++) {
                bool[i][j] = (s[i].charAt(j-1)=='#');
            }
        }
        for (int i = 1; i <= height; i++) {
            for (int j = 1; j < width; j++) {
                if (bool[i][j]) {
                    if ( bool[i-1][j] || bool[i+1][j] || bool[i][j-1] || bool[i][j+1] ) {
                        continue;
                    }else{
                        ans = false;
                    }
                }
            }
        }

        if (ans) {
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }

        
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