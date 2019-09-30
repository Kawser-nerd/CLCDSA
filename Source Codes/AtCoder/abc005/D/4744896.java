import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[][] a = new int[N+1][N+1];
	for(int i = 1; i<=N; i++) {
	    for(int j = 1; j<=N; j++) {
		a[i][j] = sc.nextInt();
	    }
	}
	int[][] b = new int[N+1][N+1];
	for(int i = N; i>=1; i--) {
            for(int j = N; j>=1; j--) {
		if(i == N && j == N) b[N][N] = a[N][N];
		else {
		    b[i][j] = a[i][j];
		    if(j+1<=N) b[i][j] += b[i][j+1];
		    if(i+1<=N) b[i][j] += b[i+1][j];
		    if(i+1<=N && j+1<=N) b[i][j] -= b[i+1][j+1];
		}
            }
        }

	int[] score = new int[N*N+1];
	for(int i = 1; i<=N; i++) {
	    for(int j = 1; j<=N; j++) {
		for(int k = 1; k<=N; k++) {
		    for(int l = 1; l<=N; l++) {
			int s = b[i][j];
			if(i+k<=N) s -= b[i+k][j];
			if(j+l<=N) s -= b[i][j+l];
			if(i+k<=N && j+l<=N) s += b[i+k][j+l];
			score[k*l] = Math.max(score[k*l], s);
		    }
		}
	    }
	}

	for(int i = 1; i<N*N+1; i++) {
	    score[i] = Math.max(score[i-1], score[i]);
	}

	int M = sc.nextInt();
	for(int i = 0; i<M; i++) {
	    System.out.println(score[sc.nextInt()]);
	}
    }
}