import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        final long a = sc.nextLong();
        final long b = sc.nextLong();
        final long c = sc.nextLong();
        final long x = sc.nextInt();
        final long y = sc.nextInt();

        if ((a + b) <= c * 2) {
            System.out.println(a * x + b * y);
            return;
        }

        long numReplace = Math.min(x, y);
        long x1 = x - numReplace;
        if (x1 < 0) x1 = 0;
        long y1 = y - numReplace;
        if (y1 < 0) y1 = 0;
        long half1 = numReplace * 2;
        long sum1 = a * x1 + b * y1 + c * half1;

        long numReplace2 = Math.max(x, y);
        long x2 = x - numReplace2;
        if (x2 < 0) x2 = 0;
        long y2 = y - numReplace2;
        if (y2 < 0) y2 = 0;
        long half2 = numReplace2 * 2;
        long sum2 = a * x2 + b * y2 + c * half2;


        long answer = Math.min(sum1, sum2);
        System.out.println(answer);
    }
}