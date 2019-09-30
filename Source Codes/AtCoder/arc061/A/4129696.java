import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    private static final PrintStream so = System.out;
    private static final Scanner     sc = new Scanner(System.in);

    public static void main(String[] args) {
        String s = sc.next();
        int len = s.length();
        long ans = 0;
        for (int i = 0; i < (1 << len-1); i++) { // (1 << 9) == 512
            ans += sumOf(s, i);
        }
        so.println(ans);
    }
    
    static long sumOf(String s, int bits) {
        long sum = 0;
        long temp = 0;
        for (int i = 0; i < s.length(); i++) {
            int digit = s.charAt(i) - '0';
            temp += digit;
            if (((bits >> i) & 1) == 1) {
                sum += temp;
                temp = 0;
            } else {
                if (i != s.length()-1) {
                    temp *= 10;
                }
            }
        }
        sum += temp;
        return sum;
    }
}