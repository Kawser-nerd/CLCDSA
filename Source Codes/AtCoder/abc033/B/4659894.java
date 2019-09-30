import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	String machi = "";
	int sum = 0;
	int max = 0;
	for(int i = 0; i<N;i++) {
	    String s = sc.next();
	    int x = sc.nextInt();
	    if(max<x) {
		max = x;
		machi = s;
	    }
	    sum+=x;
	}
	if(max>sum/2) {
	    System.out.println(machi);
	} else {
	    System.out.println("atcoder");
	}
    }
}