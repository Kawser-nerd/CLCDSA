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
        Integer[] height = new Integer[n];
        for (int i = 0; i < n; i++) {
            height[i] = sc.nextInt();
        }
        abc041cSenojun(n,height);

        sc.close();
    }

    public static void abc041cSenojun(int n,Integer[] height) {
        Integer[] id = new Integer[n];
        Arrays.setAll(id, i -> i);
        Arrays.sort(id, Comparator.comparingInt(i -> height[i]));
        for (int i = n-1; i >= 0; i--) {
            System.out.println(id[i] + 1);
        }
    }

}