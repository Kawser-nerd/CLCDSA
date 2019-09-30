import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] a = new int[2 * N - 1];
        for (int i = 0; i < a.length; ++i) {
            a[i] = sc.nextInt();
        }

        int high = 2 * N - 1;
        int low = 1;
        while ((high - low) > 1) {
            int mid = (high + low) / 2;
            if (go(a, mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        out.println(low);
        out.flush();
    }
    private static boolean go(int[] a, int mid) {
        int len = a.length;
        int[] b = new int[len];
        for (int i = 0; i < len; ++i) {
            b[i] = a[i] >= mid ? 1 : 0;
        }

        int start = -1;
        for (int i = 1; i < len; ++i) {
            if (b[i] != b[i - 1]) {
                if (start == -1) {
                    start = i - 1;
                }
            } else {
                if (start != -1) {
                    if ((i - start) % 2 == 1) {
                        for (int j = start; j <= i; ++j) {
                            b[j] = b[i];
                        }
                    } else {
                        for (int j = start; j < start + (i - start) / 2; ++j) {
                            b[j] = b[start];
                        }
                        for (int j = start + (i - start) / 2; j <= i; ++j) {
                            b[j] = b[i];
                        }
                    }
                }
                start = -1;
            }
        }
        if (start != -1) {
            int i = len;
            if ((i - start) % 2 == 1) {
                for (int j = start; j < i; ++j) {
                    b[j] = b[start];
                }
            } else {
                for (int j = start; j < start + (i - start) / 2; ++j) {
                    b[j] = b[start];
                }
                for (int j = start + (i - start) / 2; j < i; ++j) {
                    b[j] = b[start] == 1 ? 0 : 1;
                }
            }
        }
        return b[len / 2] == 1;
    }
}