import java.awt.image.IndexColorModel;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.*;

public class Main {

    public static BigInteger comb(int a, int b) {
        BigInteger aa = new BigInteger(String.valueOf(1));
        BigInteger bb = new BigInteger(String.valueOf(1));

        for(int i = a; i >= a - b + 1; i--) {
            aa = aa.multiply(new BigInteger(String.valueOf(i))).mod(new BigInteger("1000000007"));
        }
        for(int i = b; i >= 1; i--) {
            bb = bb.multiply(new BigInteger(String.valueOf(i))).mod(new BigInteger("1000000007"));
        }


        aa = aa.multiply(bb.modInverse(new BigInteger("1000000007"))).mod(new BigInteger("1000000007"));
        return aa;

    }

    public static BigInteger c(int x, int y, int d, int l) {
        if(x < 0 || y < 0 || x * y < d || x * y - d < l || x * y - d < 0 ) return new BigInteger("0");
        BigInteger mod = new BigInteger("1000000007");
        // p2
        
        // p2_1 C p2_2 * p2_3 C p2_4

        BigInteger p2_1 = comb(x * y,d);
        BigInteger p2_2 = comb(x * y - d,l);

        


        BigInteger p2 = p2_1.multiply(p2_2).mod(mod);

        return p2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int d = sc.nextInt();
        int l = sc.nextInt();

        // p1
        int p1 = (r - x + 1) * (c - y + 1);
        BigInteger p2_i = c(x,y,d,l);
        BigInteger p2_1 = c(x-1,y,d,l).multiply(new BigInteger("2")).add(c(x,y-1,d,l).multiply(new BigInteger("2")));
        BigInteger m2_1 = c(x-1,y-1,d,l).multiply(new BigInteger("4")).add(c(x,y-2,d,l)).add(c(x-2,y,d,l));
        BigInteger p2_2 = c(x-2,y-1,d,l).multiply(new BigInteger("2")).add(c(x-1,y-2,d,l).multiply(new BigInteger("2")));
        BigInteger m2_2 = c(x-2,y-2,d,l);
        BigInteger p2_k = p2_1.add(p2_2).subtract(m2_1).subtract(m2_2);
        BigInteger p2 = p2_i.subtract(p2_k).multiply(new BigInteger(String.valueOf(p1))).mod(new BigInteger("1000000007"));
        //System.out.println(p2_k);
        //System.out.println(p2_i + " " + p1 + " " + p2_1.intValue() + " " + p2_2.intValue());
        System.out.println(p2.intValue());



    }
}