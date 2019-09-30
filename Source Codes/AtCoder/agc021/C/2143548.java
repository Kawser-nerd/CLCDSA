import java.util.*;

public class Main {
    static char[][] c;
    public static void main(String[] args) throws InterruptedException {
        Scanner scan = new Scanner(System.in);
        int m = scan.nextInt();
        int n = scan.nextInt();
        int a = scan.nextInt();
        int b = scan.nextInt();
        c = new char[n][m];
        if(n * m < 2 * (a + b)) {
            System.out.println("NO");
            return;
        }
        if(n % 2 != 0) {
            int v = Math.min(b, m / 2);
            b -= v;
            for (int i = 0; i < v; i++) {
                c[n-1][2* i] = '^';
                c[n-1][2* i + 1] = 'v';
            }
        }
        if(m % 2 != 0) {
            int r = Math.min(a, n / 2);
            a -= r;
            for (int i = 0; i < r; i++) {
                c[2 * i][m- 1] = '<';
                c[2* i + 1][m-1] = '>';
            }
        }

        int ca = 0;
        for (int i = 0; i < n / 2 ; i++) {
            for (int j = 0; j < m / 2; j++) {
                if(ca == a) {
                    break;
                }
                if(a - ca != 1) {
                    putAS(2 * i, 2 * j);
                    ca += 2;
                }
                else {
                    if(b % 2 != 1) {
                        putAs(2 * i, 2 * j);
                    }
                    ca++;
                }
            }
            if(ca == a) {
                break;
            }
        }
        int cb = 0;
        ca = 0;
        for (int i = 0; i <n / 2 ; i++) {
            for (int j = 0; j < m / 2; j++) {
                if(ca < a - 1) {
                    ca += 2;
                    continue;
                }
                if(cb == b) {
                    if(a - ca == 1) {
                        putAs(2 * i, 2 * j);
                    }
                    break;
                }
                if(b - cb != 1) {
                    putBS(2 *i, 2* j);
                    cb += 2;
                }
                else {
                    putBs(2 *i, 2* j);
                    cb++;
                }

            }
            if(cb == b) {
                break;
            }
        }
        boolean flag = true;
        if( (n - n %2) * (m - m % 2) < 4 * ((a / 2 + a % 2) + (b / 2 + b % 2))) {
            if(m > 2 && n > 2 && m % 2 == 1 && n % 2 == 1 && a % 2 == 1 && b % 2 == 1) {
                if((n / 2) * (m / 2) == (a / 2) + (b / 2) + 1) {
                    c[n-2-1][m-2-1] = '<';
                    c[n-1-1][m-2-1] = '>';
                    c[n-1][m-2-1] = '^';
                    c[n-1][m-1-1] = 'v';
                    c[n-1][m-1] = '>';
                    c[n-1-1][m-1] = '<';
                    c[n-2-1][m-1] = 'v';
                    c[n-2-1][m-1-1] = '^';
                    c[n-1-1][m-1-1] = '.';
                    flag = false;
                }
            }
        }
        else {
            flag = false;
        }
        if(flag) {
            System.out.println("NO");
            return;
        }

        char[] line = new char[n];
        System.out.println("YES");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                line[j] = (c[j][i] == 0) ? '.' : c[j][i];
            }
            System.out.println(new String(line));
        }
    }

    static void putAS(int i, int j){
        c[i][j] = '<';
        c[i+1][j] = '>';
        c[i][j+1] = '<';
        c[i+1][j+1] = '>';
    }
    static void putAs(int i, int j){
        c[i][j] = '<';
        c[i+1][j] = '>';
    }
    static void putBS(int i, int j){
        c[i][j] = '^';
        c[i+1][j] = '^';
        c[i][j+1] = 'v';
        c[i+1][j+1] = 'v';
    }
    static void putBs(int i, int j){
        c[i][j] = '^';
        c[i][j+1] = 'v';
    }
}