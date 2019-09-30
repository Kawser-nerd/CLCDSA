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
        int[] pp = new int[n];
        int sum = 0;
        int ans = 0;
        int ave = 0;
        for (int i = 0; i < n; i++) {
            pp[i] = sc.nextInt();
            sum += pp[i];
        }
        
        if (sum % n == 0) {
            ave = sum/n;
            for (int i = 0; i < n-1; i++) {
                if (pp[i] != ave) {
                    ans++;
                    int tmp = ave-pp[i];
                    pp[i+1] = pp[i+1]-tmp;
                    pp[i] = ave;
                }
            }
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
        

        sc.close();
    }

}