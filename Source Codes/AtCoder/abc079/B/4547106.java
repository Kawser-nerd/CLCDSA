import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		//String S = sc.next();
		//int N = sc.nextInt();
		//System.out.println();
		int N = sc.nextInt();
		long a1 = 2;
		long a2 = 1;
		long lucas = 3;
		if(N==1){
			System.out.println(a2);
		}else{
			for(int i=1; i<N;i++){
				lucas = a1 + a2;
				a1 = a2;
				a2 = lucas;
			}
			System.out.println(lucas);
		}
			
	}
}