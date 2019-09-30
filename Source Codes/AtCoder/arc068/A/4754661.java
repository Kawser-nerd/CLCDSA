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
        long n = sc.nextLong();
        if (n % 11  <= 6) {
            System.out.println( (n / 11) * 2 + (n % 11 + 10)/11 );
        } else {
            System.out.println( (n / 11) * 2 + 2 );
        }
        sc.close();
    }
}