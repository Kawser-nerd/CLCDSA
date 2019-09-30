import java.util.Scanner;
	

public class Main{
	static int N;
	static int[] s;
	static int[] B;
	
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		String S = sc.next();
		s = new int[N];
		B = new int[N];
		for(int i=0;i<N;i++){
			char c= S.charAt(i);
			if(c=='o'){
				s[i]=0;
			}else{
				s[i]=1;
			}
		}
		if(solve(0,0)){
			write(B);
		}else if(solve(0,1)){
			write(B);
		}else if(solve(1,0)){
			write(B);
		}else if(solve(1,1)){
			write(B);
		}else{
			System.out.println(-1);
		}
		
			
		

	}
	private static void write(int[] b2) {
		for(int i=0;i<N;i++){
			if(b2[i]==0){
				System.out.print("S");
			}else{
				System.out.print("W");
			}
		}
		
	}
	static Boolean solve(int i, int j) {
		B[0] = i;
		B[1] = j;
		for(int k=2;k<N;k++){
			if((B[k-2]^B[k-1]^s[k-1]) == 0){
				B[k] = 0;
			}else{
				B[k] = 1;
			}
		}
		
		if(((B[N-2]^B[N-1]^s[N-1])==B[0])&&(B[0]^B[1]^s[0])==B[N-1]){
			return true;
		}else{
			return false;
		}
		
	}
	

}