import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	int q = sc.nextInt();
	int[] a = new int[n];
	for(int i = 0; i<q; i++) {
	    int start = sc.nextInt();
	    int end = sc.nextInt();
	    int t = sc.nextInt();
	    for(int j = start -1; j<end; j++) {
		a[j] = t;
	    }
	}
	for(int i: a) {
	    System.out.println(i);
	}
    }
}