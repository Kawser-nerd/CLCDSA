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
        int[] pr = new int[n];
        for (int i = 0; i < n; i++) {
            pr[i] = sc.nextInt();
        }
        Arrays.sort(pr);
        for (int i = 0; i < n; i++) {
            if (pr[pr.length-1-i] != pr[pr.length-1-i-1]) {
                System.out.println(pr[pr.length-1-i-1]);
                break;
            }
        }


        sc.close();
    }

}