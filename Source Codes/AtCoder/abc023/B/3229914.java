import java.util.*;
public class Main{
	static int Juzu(int n, String s){
		if(n%2==0)return -1;
		if(n==1){
			if(s.equals("b"))return 0;
			else return -1;
		}
		if(s.charAt(0)=='b'){
			for(int i=0; i<n-2; i+=3){
				if(!s.substring(i, i+3).equals("bca"))return -1;
			}
			if(s.charAt(n-1)=='b')return n / 2;
		}
		if(s.charAt(0)=='a'){
			for(int i=0; i<n-2; i+=3){
				if(!s.substring(i, i+3).equals("abc"))return -1;
			}
			if(s.charAt(n-1)=='c')return n / 2;
		}
		if(s.charAt(0)=='c'){
			for(int i=0; i<n-2; i+=3){
				if(!s.substring(i, i+3).equals("cab"))return -1;
			}
			if(s.charAt(n-1)=='a' && s.charAt(n-2)=='c')return n / 2;
		}
		return -1;
	}		

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		System.out.println(Juzu(N, S));
	}
}