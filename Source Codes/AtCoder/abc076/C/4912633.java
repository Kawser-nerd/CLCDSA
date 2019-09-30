import java.util.*;
public class Main {
	public static void main(String[] args) {
		C();
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
	
	//T?????????????
	//?????a????
	
	//T?????????????????????????????? else -1
	public static int match(String S, String T) {
		for(int i=S.length()-1;i>=T.length()-1;i--) {
			if((S.charAt(i)==T.charAt(T.length()-1) || S.charAt(i)=='?')  && checksame(S,T,i)) return i-T.length()+1;
		}
		return -1;
	}
	// i-T.length()+1 ~ i???????????????????
	public static boolean checksame(String S, String T, int i) {
		for(int j = 0;j<T.length();j++) {
			if(S.charAt(i-T.length()+1+j)!=T.charAt(j) && S.charAt(i-T.length()+1+j)!='?') return false;
		}
		return true;
	}
	
	public static void C() {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String T = sc.next();
		int matchidx = match(S,T);
		if(matchidx == -1) {
			System.out.println("UNRESTORABLE");
			return;
		}
		StringBuilder ns = new StringBuilder();
		int i=0;
		for(;i<matchidx;i++) {
			if(S.charAt(i)=='?') ns.append('a');
			else ns.append(S.charAt(i));
		}
		ns.append(T.toCharArray());
		i += T.length();
		for(;i<S.length();i++) {
			if(S.charAt(i)=='?') ns.append('a');
			else ns.append(S.charAt(i));
		}
		ns.toString();
		System.out.println(ns);
	}
}