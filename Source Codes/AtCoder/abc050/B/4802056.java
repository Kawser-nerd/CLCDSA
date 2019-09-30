/*
* @Author Silviase(@silviasetitech)
* For ProCon
*/

import java.util.*;
import java.lang.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        
        int n = sc.nextInt();
        int[] t = new int[n];
        int ruiseki = 0;
        for (int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
            ruiseki+= t[i];
        }
        int m = sc.nextInt();
        int[] p = new int[m];
        int[] x = new int[m];
        for (int i = 0; i < m; i++) {
            p[i] = sc.nextInt();
            x[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            System.out.println(ruiseki - t[p[i]-1] + x[i]);
        }


        

        sc.close();
    }

}