import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a=new BigInteger(scan.next());
        BigInteger b=a.multiply(a);
        BigInteger aa=a.add(BigInteger.ONE);
        BigInteger bb=aa.multiply(aa).subtract(BigInteger.ONE);
        BigInteger ans=null;
        BigInteger ten=BigInteger.valueOf(100);
        BigInteger nine=BigInteger.valueOf(99);
        while(b.compareTo(bb)<=0){
            if(false){
                System.err.println(b);
                System.err.println(bb);
            }
            BigInteger u=b.add(nine).divide(ten);
            BigInteger v=bb.divide(ten);
            if(u.compareTo(v)>0){
                ans=b;
                break;
            }
            b=u;
            bb=v;
        }
        System.out.println(ans);
    }
}