import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Solver().solve(new Scanner(System.in));
//        new Solver().solve(new Scanner(ex));
    }

//    private static final String ex = "1000 300";
    private static final String ex = "567876543 0";
}

class Solver {
    Solver() {}

    void solve(Scanner scanner) {
        String[] split = scanner.nextLine().split(" ");
        BigInteger A = new BigInteger(split[0]);
        BigInteger K = new BigInteger(split[1]);
        BigInteger target = new BigInteger("2000000000000");
        BigInteger one = new BigInteger("1");

        if (K.compareTo(new BigInteger("0")) == 0) {
            System.out.println(target.subtract(A).longValue());
            System.exit(0);
        }

        int ans = 0;
        while (A.compareTo(target) < 0) {
            A = A.add(one.add(K.multiply(A)));
            ans ++;
        }

        System.out.println(ans);
    }

    private int[] splitInt(String s) {
        String[] split = s.split(" ");
        int[] splitInt = new int[split.length];
        for (int i = 0; i < split.length; i ++) {
            splitInt[i] = Integer.parseInt(split[i]);
        }
        return splitInt;
    }

    private long[] splitLong(String s) {
        String[] split = s.split(" ");
        long[] splitInt = new long[split.length];
        for (int i = 0; i < split.length; i ++) {
            splitInt[i] = Long.parseLong(split[i]);
        }
        return splitInt;
    }

}