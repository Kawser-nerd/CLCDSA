import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	String[] a = new String[n];
	for(int i = 0; i<n; i++) {
	    a[i] = sc.next();
	}
	for(int i = 0; i<n; i++) {
	    for(int j = n-1; j>=0; j--) {
		System.out.print(a[j].charAt(i));
	    }
	    System.out.println();
	}
    }
}