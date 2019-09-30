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
        long[] ball = new long[n];
        long[] ruisekiball = new long[n];
        int ans = 1;
        int ite = n-1;
        for (int i = 0; i < n; i++) {
            ball[i] = sc.nextInt();
        }
        Arrays.sort(ball);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ruisekiball[i] = ball[i];
            }else{
                ruisekiball[i] = ruisekiball[i-1] + ball[i];
                // i made no wa
            }
        }
        while (true) {
            ite--;
            if (ruisekiball[ite] * 2 >= ball[ite+1]) {
                ans++;
            }else{
                break;
            }
            if (ite == 0) {
                break;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}