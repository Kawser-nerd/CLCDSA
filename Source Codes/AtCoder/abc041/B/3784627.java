import java.math.BigInteger;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] abc = scanner.nextLine().split(" ", 3);
        BigInteger a = new BigInteger(abc[0]);
        BigInteger b = new BigInteger(abc[1]);
        BigInteger c = new BigInteger(abc[2]);
        BigInteger x = a.multiply(b).multiply(c);
        BigInteger mod = new BigInteger("1000000007");
        System.out.println(x.mod(mod));
    }
}