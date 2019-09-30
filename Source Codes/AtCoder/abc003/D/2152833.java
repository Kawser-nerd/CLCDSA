import java.util.Scanner;
class Main {
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int D = sc.nextInt();
        int L = sc.nextInt();
        long A = 1000000007;
        int part = X * Y;
        long[][] comb = new long[part + 1][part + 1];
        comb[0][0] = 1;
        for (int i = 1; i <= part ; i++) {
        	for (int j  =0; j <= i; j++) {
        		if (j == 0) {
        			comb[i][j] = 1;
        		} else {
        			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % A;
        		}
        	}
        }

    	long answer = 0;
        if (D + L == X * Y) {
        	answer = (R - X + 1) * (C - Y + 1) * comb[X * Y][D] % A;
        } else {
        	for (int i = 0; i <= 2; i++) {
        		for (int j = 0; j <= 2; j++) {
        			if ((X - i) * (Y - j) < D + L) {
        				continue;
        			}
        			if ((i + j) % 2 == 0) {
        				answer += comb[2][i] * comb[2][j]  * (R - X + 1) * (C - Y + 1)
        						* comb[(X - i) * (Y - j)][D] % A
        								* comb[(X - i) * (Y- j) - D][L] % A;
        			}else {
        				answer -= comb[2][i] * comb[2][j]  * (R - X + 1) * (C - Y + 1)
        						* comb[(X - i) * (Y - j)][D] % A
        								* comb[(X - i) * (Y- j) - D][L] % A;
        			}
        		}
        	}
        	answer %= A;
        	if (answer < 0) {
        		answer += A;
        	}
        }
        System.out.println(answer);
	}
}