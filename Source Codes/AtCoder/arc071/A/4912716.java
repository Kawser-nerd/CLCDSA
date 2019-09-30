/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

class Main{

        // usual use input int
        static int n;
        static int x;
        static int c;
        static int k;
        static int m;
        static int height;
        static int width;
        static int left;
        static int right;
        static int ans;
        //
        static String s;
        static String anss;
        // 
        static String[] sAr;
        //
        static long ansl;
        //
        static int[] intAr;
        //

        // for dfs
        static int[] w;
        static int[] ww;
        static boolean[] isvisited;
        //
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        sAr = new String[n];
        int[][] alp  = new int[n][26];
        int[] ansalp = new int[26];
        Arrays.fill(ansalp, 1000000);
        for (int i = 0; i < n; i++) {
            sAr[i] = sc.next();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sAr[i].length(); j++) {
                alp[i][sAr[i].charAt(j)-'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < n; j++) {
                ansalp[i] = Math.min(ansalp[i] , alp[j][i]);
            }
        }

        char ch = 'a';

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < ansalp[i]; j++) {
                System.out.print(ch);
            }
            ch++;
        }
        System.out.println("");

        
        sc.close();
    }

        public static int gcd_int(int a, int b) {
        
            if (a < b) {
                int tmpp = a;
                a = b;
                b = tmpp;
            }
            if (b == 0) {
                return a;
            }else{
                return gcd_int(b, a%b);
            }
        }

        public static long gcd_long(long a, long b) {
        
            if (a < b) {
                long tmpp = a;
                a = b;
                b = tmpp;
            }
            if (b == 0) {
                return a;
            }else{
                return gcd_long(b, a%b);
            }
        }

        public static int lcm_int(int a, int b) {
            int gcd = gcd_int(a,b);
            return a/gcd*b;
        }

        public static long lcm_long(long a, long b) {
            long gcd = gcd_long(a,b);
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

            isvisited[placenow] = true;
            boolean success = true;
            for (int i = 0; i < n; i++) {
                if (isvisited[i] == false) { // not go all place
                    success = false;
                    break;
                }
            }
            if (success) {
                ans++;
                isvisited[placenow] = false;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (w[i] == placenow && isvisited[ww[i]] == false ) {
                    dfs(ww[i]);
                }else if(ww[i] == placenow && isvisited[w[i]] == false){
                    dfs(w[i]);
                }else{
                    continue;
                }
            }
            isvisited[placenow] = false;
            return;
        }

}