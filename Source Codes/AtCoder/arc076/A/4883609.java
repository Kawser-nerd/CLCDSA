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
        

        long inu =  sc.nextLong();
        long saru = sc.nextLong();
        long ans = 1;

        if (inu == saru) {
            for (int i = 1; i <= inu; i++) {
                ans = (ans * i) % 1000000007;
            }
            for (int i = 1; i <= saru; i++) {
                ans = (ans * i) % 1000000007;
            }
            ans = (ans * 2) % 1000000007;

            System.out.println(ans);
        } else {
            if (Math.abs(inu - saru) >= 2) {
                System.out.println(0);
            } else {
                for (int i = 1; i <= inu; i++) {
                    ans = (ans * i) % 1000000007;
                }
                for (int i = 1; i <= saru; i++) {
                    ans = (ans * i) % 1000000007;
                }
                System.out.println(ans);
            }
        }

        sc.close();
    }

}