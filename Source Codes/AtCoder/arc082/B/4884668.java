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
        int[] num = new int[n+1];
        int ans = 0;
        int tmp;
        num[0] = 10000000;
        for (int i = 1; i <= n; i++) {
            num[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                if (num[i] == i) {
                    tmp  = num[i];
                    num[i] = num[i-1];
                    num[i-1] = tmp;
                    ans++;
                }
            } else {
                if (num[i] == i) {
                    tmp  = num[i];
                    num[i] = num[i+1];
                    num[i+1] = tmp;
                    ans++;
                }
            }
        }
        System.out.println(ans);

        sc.close();
    }

}