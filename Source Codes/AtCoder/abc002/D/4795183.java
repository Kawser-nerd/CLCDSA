import java.util.*;
class Main {
    static int N;
    static int[] x;
    static int[] y;
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	N = sc.nextInt();
	int M = sc.nextInt();
	x = new int[M];
	y = new int[M];
	for(int i = 0; i<M; i++) {
	    x[i] = sc.nextInt();
	    y[i] = sc.nextInt();
	}
	if(M == 0) {
	    System.out.println(1);
	    return;
	}
	int index = 0;
	int[] a = new int[N];
	System.out.println(dfs(index, a, 1));
    }
    public static int dfs(int index, int[] a, int depth) {
	if(depth == N+1) {
	    if(isFriend(a,index)) return index;
	    else return 2;
	}
	int[] c1 = makeCopy(a);
	int[] c2 = makeCopy(a);
	c2[index] = depth;
	return Math.max(dfs(index, c1, depth+1), dfs(index+1, c2,depth+1));
    }
    public static boolean isFriend(int[] a,int index) {
	int cnt = 0;
	for(int i = 0; i<x.length; i++) {
	    for(int j = 0; j<index; j++) {
		if(x[i] == a[j]) {
		    for(int k = 0; k<index; k++) {
			if(y[i] ==a[k]) {
			    cnt++;
			    //System.out.println("x " + x[i] + " y " + y[i]);
			}
		    }
		}
	    }
	}
	int edge = 0;
	for(int i = 1; i<index; i++) {
	    edge += i;
	}
	//System.out.println("cnt "+ cnt + " edge " + edge);
	if(cnt==edge) return true;
	else return false;
    }
    public static int[] makeCopy(int[] a) {
	int[] b = new int[a.length];
	for(int i = 0; i<a.length; i++) {
	    b[i] = a[i];
	}
	return b;
    }

}