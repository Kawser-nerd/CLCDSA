import java.util.*;
class Main {
    static int[][] t;
    static int N;
    static int K;
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	N = sc.nextInt();
	K = sc.nextInt();
	t = new int[N][K];
	for(int i = 0; i<N; i++) {
	    for(int j = 0; j<K; j++) {
		t[i][j] = sc.nextInt();
	    }
	}
	for(int i = 0; i<K; i++) {
	    if(isXOR(1,t[0][i],0)) {
		System.out.println("Found");
		return;
	    }
	}
	System.out.println("Nothing");
    }
    private static boolean isXOR(int depth, int node, int total) {
	if(depth==N) {
	    return ((node^total) == 0);
	}
	for(int i = 0; i<K; i++) {
	    if(isXOR(depth+1, t[depth][i], (total^node))) {
		return true;
	    }
	}
	return false;
    }
}