import java.math.BigInteger;

public class C {

    public static void main(String[] args) {
        int N = 32;
        int J = 500;
        System.out.println("Case #1:");
        for (int i = 0; i < J; i++) {
            String bitmask = Integer.toBinaryString(i);
            while (bitmask.length() + 2 < N / 2) {
                bitmask = '0' + bitmask;
            }
            String divisor = String.format("1%s1", bitmask);
            String jamcoin = divisor + divisor;
            System.out.print(jamcoin);
            for (int base = 2; base <= 10; base++) {
                System.out.print(" " + new BigInteger(divisor, base));
            }
            System.out.println();
        }
    }

}
