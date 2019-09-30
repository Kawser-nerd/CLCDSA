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
        int[] fl = new int[100000];
        int ans  = 0;
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            fl[tmp-1]++;
        }
        for (int i = 0; i < 100000; i++) {
            if (fl[i] >= 1) {
                ans += fl[i]-1;
            }
        }

        System.out.println(ans);

        sc.close();
    }

}