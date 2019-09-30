import java.util.Arrays;
import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
	
		int N = sc.nextInt();
		Boolean[] A = new Boolean[100001];
		int kaburi = 0;
		Arrays.fill(A, false);
		for(int i=0;i<N;i++){
			int a = sc.nextInt();
			if(A[a]){
				kaburi++;
			}else{
				A[a]= true;
			}
		}
		if(kaburi%2==1){
			kaburi++;
		}
		System.out.println(N-kaburi);
	}
	
}