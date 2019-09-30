import java.math.BigInteger;
import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long N = sc.nextLong();
        long A = sc.nextLong();
        long B = sc.nextLong();
        
        if (A > B || (N == 1 && A != B)) {
        	System.out.println(0);
        	return;
        }
        
        //??
        if (N == 2) {
        	System.out.println(3);
        	return;
        }
        N -=2;
        
        String ans = BigInteger.valueOf(B).multiply(BigInteger.valueOf(N)).subtract(BigInteger.valueOf(A).multiply(BigInteger.valueOf(N))).add(BigInteger.ONE).toString(10);
        
        System.out.println(ans);
    }
}