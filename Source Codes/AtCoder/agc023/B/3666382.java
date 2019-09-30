import java.util.Scanner;
	
 
public class Main{
 
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		
	    int N = sc.nextInt();
	    int ansbase = 0;
	    String[] S = new String[N];
		char[][] s = new char[N][N];
		for(int i=0;i<N;i++){
			S[i] = sc.next();
			for(int j=0;j<N;j++){
				s[i][j] = S[i].charAt(j);
			}
		}
		
		for(int i=0;i<N;i++){
			Boolean OK = true;
			for(int j=0;j<N;j++){
				for(int k=0;k<N;k++){
					if(s[(i+j)%N][k]!=s[(i+k)%N][j]){
						OK = false;
					}
				}
			}
			if(OK){
				ansbase++;
			}
		}
		System.out.println(ansbase*N);
		
	}
 
}