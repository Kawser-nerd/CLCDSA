import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
	int[] a	= new int[N];
	int d =	Integer.MAX_VALUE;
        for(int i = 0; i<N; i++) {
	    d = Math.min(d,sc.nextInt());
	}
	System.out.println(d);
    }
}