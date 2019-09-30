import java.util.*;
public class Main {
	public static void main(String[] args) {
		B();
	}
	
	// R+X = 2G
	public static void A() {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int g = sc.nextInt();
		System.out.println(2*g-r);
	}
	
	//??????
	public static void B() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int ret = 1;
		for(int i=0;i<N;i++) {
			if(ret<K) ret += ret;
			else ret += K;
		}
		System.out.println(ret);
	}
}