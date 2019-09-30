import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int[] a = new int[N+1];
	int left = 1;
	int right = N;
	int num = 0;
	for(int i = 0; i<N+1; i++) {
	    a[i] = Integer.MAX_VALUE;
	}
	for(int i = 0; i<N; i++) {
	    num = sc.nextInt();
	    int cleft = left;
	    int cright = right;
	    int middle = (cleft+cright)/2;
	    //System.out.println(num);
	    while(cleft<=cright) {
		if(cleft == cright) {
		    a[cleft] = Math.min(num, a[cleft]);
		    cleft++;
		}
		if(a[middle] < num) {
		    cleft = middle + 1;
		    middle = (cleft+cright)/2;
		}
		if(a[middle] > num) {
		    cright = middle;
		    middle = (cleft+cright)/2;
		}
	    }
	}
	int cnt = 0;
	for(int i = 0; i<N+1; i++) {
	    if(a[i]<Integer.MAX_VALUE) {
		//System.out.println(a[i]);
		cnt++;
	    }
	}
	System.out.println(N-cnt);

    }
}