import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        int M = scan.nextInt();
        int K = scan.nextInt();
        String S = scan.next();
        String T = scan.next();
        solve(N, M, K, S, T);
    }
    public static void solve(int N, int M, int K, String S, String T) {
        int[] x = new int[10000000];
        int[] y = new int[10000000];
        Arrays.fill(x, -1);
        Arrays.fill(y, -1);
        int t = 0;
        for(char c : new StringBuilder(S).reverse().toString().toCharArray()) {
            x[t++] = c == '0' ? 0 : 1;
        }
        t = 0;
        for(char c : new StringBuilder(T).reverse().toString().toCharArray()) {
            y[t++] = c == '0' ? 0 : 1;
        }
        int min = Math.min(N-1, M-1);
        for (int i = min; 0 <= i; i--) {
            if (x[i] != 1 || y[i] != 1) {
                continue;
            }
            int times = 0;
            boolean x_up = false;
            boolean y_up = false;
            int j = i;
            while(times < K) {
                if (x[j] == 1 && y[j] == 1) {
                    x[j] = 0;
                    y[j] = 0;
                    x_up = true;
                    y_up = true;
                    times += 1;
                } else {
                    break;
                }
                while (x_up || y_up) {
                    j++;
                    if (x_up) {
                        if (x[j] == -1) {
                            x[j] = 1;
                        } else {
                            x[j] += 1;
                        }
                        x_up = false;
                    }
                    if (y_up) {
                        if (y[j] == -1) {
                            y[j] = 1;
                        } else {
                            y[j] += 1;
                        }
                        y_up = false;
                    }
                    if (x[j] == 2) {
                        x[j] = 0;
                        x_up = true;
                    }
                    if (y[j] == 2) {
                        y[j] = 0;
                        y_up = true;
                    }
                }
            }
        }

        StringBuffer x_str = new StringBuffer();
        for(int i = 0; i < 10000000; i++) {
            if (x[i] != -1) {
                x_str.append(x[i]);
            } else {
                break;
            }
        }
        StringBuffer y_str = new StringBuffer();
        for(int i = 0; i < 10000000; i++) {
            if (y[i] != -1) {
                y_str.append(y[i]);
            } else {
                break;
            }
        }
        System.out.println(x_str.reverse().toString());
        System.out.println(y_str.reverse().toString());
    }
}