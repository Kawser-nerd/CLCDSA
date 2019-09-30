import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S;
        String s[][] = new String[N][N];
        String t[][] = new String[N][N];
        for (int i = 0; i < N; i++) {
            S = sc.next();
            s[i] = S.split("");
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(s[N - 1 - j][i]);
            }
            System.out.println();
        }
    }
}