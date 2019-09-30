/*
* Author. Silviase(@silviasetitech)
* For AtCoder
*/

import java.util.*;
import java.lang.*;
import java.math.*;


public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        double[] coin = new double[n];
        for (int i = 0; i < n; i++) {
            coin[i] = sc.nextDouble();
        }
        Arrays.sort(coin);
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double tmp = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && coin[i] % coin[j] == 0) {
                    tmp = tmp + 1;
                }
            }
            if (tmp % 2 == 0) {
                sum += (tmp + 2)/(2*tmp +2);
            } else {
                sum += 0.5;
            }
        }
        System.out.println(sum);

        sc.close();
    }
}