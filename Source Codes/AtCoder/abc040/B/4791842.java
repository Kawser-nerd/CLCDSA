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
        int hen = 1;
        int min = 20000000;
        while (!(hen * hen > n)) {
            hen++;
        }
        hen--;
        while (hen != 0) {
            min = Math.min((n-n/hen*hen)+(n/hen-hen),min);
            hen--;
        }
        System.out.println(min);

        sc.close();
    }

}