import java.util.*;

public class Main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        System.out.println(calc(A,B));
    }

    public static long calc(long A,long B){
        if(A == B) {
            return 1;
        }
        long ans = 0;
        long k = 1;
        for(int i = 0; i <= 60; i++){
            k = k * 2;
        }
        while((A & k) == (B & k)){
            A = (A | k) ^ k;
            B = (B | k) ^ k;
            k = k / 2;
        }
        long s1 = k - A;
        long s2 = k - A;
        long s3 = maxbit(B - k);
        ans = s1 + s2 + s3;
        // System.out.println(s1+" "+s2+" "+s3);
        long rb = k + s3 - 1;
        long lb = k + A;
        if(rb >= lb){
            ans = ans - (rb - lb + 1);
        }
        return ans;
    }

    public static long maxbit(long n){
        if(n == 0){
            return 1;
        }
        long k = 1,ans = 0;
        for(int i = 0; i <= 60; i++){
            if((n & k) > 0){
                ans = k;
            }
            k = k * 2;
        }
        return ans * 2;
    }
}