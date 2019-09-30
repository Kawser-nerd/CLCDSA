
import java.math.*;
import java.util.*;

class A {
    public static void main(String... args) {
	new A().run();
    }
    public void run(){
	Scanner in = new Scanner(System.in);
	int nCase = in.nextInt();
	for(int iCase = 1; iCase <= nCase; ++iCase) {
	    BigInteger r = in.nextBigInteger();
	    BigInteger t = in.nextBigInteger();
 	    BigInteger r2 = r.shiftLeft(1);
// 	    BigInteger left = new BigInteger("0"); 
// 	    BigInteger right = new BigInteger("1100000000000000000");
// 	    while(right.subtract(left).compareTo(BigInteger.ONE) > 0){
// 		BigInteger med = left.add(right).shiftRight(1);
// 		BigInteger tmp = med.multiply(r2.add(med).add(med).subtract(BigInteger.ONE));
// 		if(tmp.compareTo(t) <= 0){
// 		    left = med;
// 		}else{
// 		    right = med;
// 		}
// 	    }
	    BigInteger d = r2.subtract(BigInteger.ONE).pow(2).add(t.shiftLeft(3));
	    

	    System.out.println("Case #" + iCase + ": " + left);
	}
    }
}