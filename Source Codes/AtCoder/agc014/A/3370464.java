import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
            System.out.println("0");
            return;
        }
        if ((A == B && B == C)) {
            System.out.println("-1");
            return;
        }
        long count = 1;
        while (true) {
            long a = A / 2;
            long b = B / 2;
            long c = C / 2;
            A = b + c;
            B = a + c;
            C = a + b;
            if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
                break;
            }
            count++;
        }
        System.out.println(count);
    }
}