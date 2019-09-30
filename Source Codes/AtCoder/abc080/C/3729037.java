import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            solve(sc);
        }
    }

    public static void solve(Scanner sc) {
        int numOfPattern = 1023;
        int[] benefits = new int[numOfPattern];
        int n = sc.nextInt();
        sc.nextLine();
        
        int[][] fss = new int[n][10];
        for (int i = 0; i < n; i++) {
            String[] fs = sc.nextLine().split(" ");
            int[] fint = new int[10];
            for (int j = 0; j < 10; j++) {
                fint[j] = Integer.parseInt(fs[j]);
            }
            fss[i] = fint;
        }

        int[][] pss = new int[n][11];
        for (int i = 0; i < n; i++) {
            String[] ps = sc.nextLine().split(" ");
            int[] pint = new int[11];
            for (int j = 0; j < 11; j++) {
                pint[j] = Integer.parseInt(ps[j]);
            }
            pss[i] = pint;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= numOfPattern; j++) {
                int count = 0;
                for (int k = 0; k < 10; k++) {
                    if ((j & (1 << k)) != 0 && fss[i][k] == 1) {
                        count++;
                    }
                }
                benefits[j - 1] += pss[i][count];
            }
        }

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < benefits.length; i++) {
            max = Math.max(max, benefits[i]);
        }
        System.out.println(max);
    }
}