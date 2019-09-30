import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String s = sc.next();
	int N = sc.nextInt();
	char[] a = s.toCharArray();
	char[] b = new char[a.length];
	for(int i = 0; i<N; i++) {
	    int start = sc.nextInt() - 1;
	    int end = sc.nextInt() - 1;
	    for(int j = a.length-1; j>=0; j--) {
		b[j] = a[j];
	    }
	    for(int j = start; j<=end; j++) {
		a[j] =  b[end-j+start];
	    }
	}
	for(char c : a) {
	    System.out.print(c);
	}
	System.out.println();
    }
}