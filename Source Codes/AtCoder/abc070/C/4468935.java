import java.math.BigInteger;
import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        System.out.println(lcm(IntStream.range(0, scanner.nextInt()).mapToLong(i -> scanner.nextLong()).toArray()));
    }

    public static long lcm(long... array) {
        BigInteger j = BigInteger.valueOf(array[0]), temp;
        for (int i = 1; i < array.length; i++)
            j = j.multiply(temp = BigInteger.valueOf(array[i])).divide(j.gcd(temp));
        return j.longValue();
    }
}