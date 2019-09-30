import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int N = scanner.nextInt();
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int C = scanner.nextInt();
            int[] array = new int[N];
            for (int i = 0; i < N; i++) {
                array[i] = scanner.nextInt();
            }
            System.out.println(recurse(0, 0, 0, A, B, C, array, 0));
        }
    }

    static int recurse(int lenA, int lenB, int lenC, int a, int b, int c, int[] array, int pos) {
        if (pos == array.length) {
            if (Math.min(Math.min(lenA, lenB), lenC) > 0) {
                return Math.abs(lenA - a) + Math.abs(lenB - b) + Math.abs(lenC - c) - 30;
            } else {
                return Integer.MAX_VALUE - 100000;
            }
        }
        int ret1 = recurse(lenA, lenB, lenC, a, b, c, array, pos + 1);
        int ret2 = recurse(lenA + array[pos], lenB, lenC, a, b, c, array, pos + 1) + 10;
        int ret3 = recurse(lenA, lenB + array[pos], lenC, a, b, c, array, pos + 1) + 10;
        int ret4 = recurse(lenA , lenB, lenC+ array[pos], a, b, c, array, pos + 1) + 10;
        return Math.min(ret1, Math.min(ret2, Math.min(ret3, ret4)));
    }
}