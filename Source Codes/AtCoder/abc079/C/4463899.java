import java.util.Scanner;
import java.util.StringJoiner;

public class Main {

    private static void print(int a, int b, int c, int d, int i, int j, int k) {
        StringJoiner sj = new StringJoiner("");
        sj.add(String.valueOf(a));
        if (i == 0) {
            sj.add("+");
        } else {
            sj.add("-");
        }
        sj.add(String.valueOf(b));
        if (j == 0) {
            sj.add("+");
        } else {
            sj.add("-");
        }
        sj.add(String.valueOf(c));
        if (k == 0) {
            sj.add("+");
        } else {
            sj.add("-");
        }
        sj.add(String.valueOf(d));
        sj.add("=7");
        System.out.println(sj.toString());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] n = sc.next().split("");
        int a = Integer.parseInt(n[0]);
        int b = Integer.parseInt(n[1]);
        int c = Integer.parseInt(n[2]);
        int d = Integer.parseInt(n[3]);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int sum = 0;
                    if (i == 0) {
                        sum = a + b;
                    } else {
                        sum = a - b;
                    }
                    if (j == 0) {
                        sum += c;
                    } else {
                        sum -= c;
                    }
                    if (k == 0) {
                        sum += d;
                    } else {
                        sum -= d;
                    }
                    if (sum == 7) {
                        print(a, b, c, d, i, j, k);
                        return;

                    }
                }
            }
        }
    }

}