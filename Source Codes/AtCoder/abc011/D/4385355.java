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
        int d = sc.nextInt();
        int xx = sc.nextInt();
        int yy = sc.nextInt();
        // if x => -x, probability doesn't change
        int x = Math.abs(xx);
        int y = Math.abs(yy);
        int[] dirchoice = new int[4];
        double probability = 0;
        double[][] procomb = Probability_nCk(n+3, n+3);

        
        if (x % d == 0 && y % d == 0) {
            x = x/d;
            y = y/d;
            for (int i = 0; i <= n; i++) {
                // y or -y is i times
                if (i - y < 0 || (i - y) % 2 != 0) {
                    //cannot move to correct y
                }else{
                    dirchoice[2] = (i+y)/2;
                    dirchoice[3] = (i-y)/2;
                    int j = n - i;
                    if (j - x < 0 || (j - x) % 2 != 0) {
                        //cannot move to correct x
                    }else{
                        dirchoice[0] = (j+x)/2;
                        dirchoice[1] = (j-x)/2;
                        // x and y 's probability 
                        // nC(ChoiceX)/2^N
                        // and choice right times xOR-x, yOR-y
                        probability += procomb[n][i] * procomb[i][dirchoice[2]] * procomb[j][dirchoice[0]];
                    }
                }
            }
            System.out.println(probability);
        } else {
            System.out.println(0);
        }

        sc.close();
    }


    private static long gcd(Long m, long n) {
        if(m < n) {
            return gcd(n, m);
        }
        if(n == 0){
            return m;
        } 
        return gcd(n, m % n);
    }

    private static long[][] Combination_nCk(long n, long k) {
        n++; k++;
        long[][] ans = new long[(int)n][(int)k];
        for (int i = 0; i < n; i++) {
            ans[i][0] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < k-1; j++) {
                if (i < j) {
                    ans[i][j] = 0;
                }else{
                    ans[i+1][j+1] = ans[i][j] + ans[i][j+1];
                }
            }
        }
        return ans;
    }
    private static double[][] Probability_nCk(int n, int k) {
        n++; k++;
        double[][] ans = new double[n][k];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans[i][0] = 1;
            }else{
                ans[i][0] = ans[i-1][0]/2;
            }
        }
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < k-1; j++) {
                if (i < j) {
                    ans[i][j] = 0;
                }else{
                    ans[i+1][j+1] = (ans[i][j] + ans[i][j+1])/2;
                }
            }
        }
        return ans;
    }
}