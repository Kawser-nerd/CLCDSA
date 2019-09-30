import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int H = sc.nextInt();
	int W = sc.nextInt();
	String[] a = new String[H];
	for(int i = 0; i<H; i++) {
	    a[i] = sc.next();
	}
	for(int i = 0; i<H*2; i++) {
	    System.out.println(a[i/2]);
	}
    }
}