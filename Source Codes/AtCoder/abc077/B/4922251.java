import java.util.*;
public class Main {
	public static void main(String[] args) {
		B();
	}
	
	public static void A() {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		for(int i=0;i<3;i++) {
			if(s1.charAt(i)!=s2.charAt(2-i)) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
	
	// 1????????????N????????????? O(root(N))
	//?????????O(logN)
	// ??????N?????????????????
	public static long binsearchN2(long left, long right, int N) {
		if(left >= right) return (long) Math.pow(right, 2);
		long mid = (left+right)/2;
		if(Math.pow(mid, 2) > N ) return binsearchN2(left, mid-1, N);
		else {
			//???????????????????????????????
			if(Math.pow(mid+1, 2) > N) return (long) Math.pow(mid, 2) ;
			else return binsearchN2(mid+1,right, N);
		}
	}
	
	public static void B() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		System.out.println(binsearchN2(0,N,N));
	}
}