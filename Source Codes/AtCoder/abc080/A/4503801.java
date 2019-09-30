import java.util.*;
public class Main {
	public static void main(String[] args){
		//???????
		Scanner sc = new Scanner(System.in);
		//String S = sc.next();
		//int N = sc.nextInt();
		//System.out.println();
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int cnt = 0;
		
		if(N*A>=B){
			System.out.println(B);
		}else{
			System.out.println(N*A);
		}
	}
}