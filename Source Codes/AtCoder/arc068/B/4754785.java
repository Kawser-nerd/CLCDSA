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
        int ans;
        int var = 0;
        int[] card = new int[100001];
        int amari = 0;
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            card[tmp]++;
        }

        for (int i = 0; i <= 100000; i++) {
            if (card[i] >= 1) {
                var++;
            }
            if (card[i] >= 2) {
                amari += (card[i] - 1);
            }
        }

        if (amari % 2 == 0) {
            ans = var;
        }else{
            ans = var - 1;
        }
        System.out.println(ans);
        sc.close();
    }
}