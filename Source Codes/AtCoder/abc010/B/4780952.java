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
        int ans = 0;
        int[] fl = new int[n];
        for (int i = 0; i < n; i++) {
            fl[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            if (fl[i] % 2 == 0) {
                ans++;
                fl[i]--;
                if (fl[i] % 3 == 2) {
                    ans += 2;
                }
            }else{
                if (fl[i] % 3 == 2) {
                    ans += 2;
                }
            }
        }
        System.out.println(ans);


        sc.close();
    }

}