import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    private static int[] path;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        path = new int[1 << n];
        if (Integer.bitCount(a ^ b) % 2 != 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
            return;
        }
        path(a, b, 0, (1 << n) - 1);
        PrintWriter pw = new PrintWriter(System.out);
        for (int i = 0; i < path.length; i++) {
            pw.print(path[i] + " ");
        }
        pw.println();
        pw.flush();
    }

    private static void path(int a, int b, int st, int mask) {
        int diffBit = Integer.highestOneBit(mask & (a ^ b));
        mask = mask ^ diffBit;
        int size = Integer.bitCount(mask);
        if (size == 0) {
            path[st] = a;
            path[st + 1] = b;
        } else {
            int otherBit = Integer.highestOneBit(mask);
            path(a, a ^ otherBit, st, mask);
            path(a ^ diffBit ^ otherBit, b, st + (1 << size), mask);
        }
    }
}