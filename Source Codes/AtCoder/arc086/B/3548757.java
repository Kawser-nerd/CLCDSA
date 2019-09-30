import java.util.Scanner;

public class Main{
	
	public static void main(String args[])throws Exception{
		
		Scanner sc= new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i=0;i<N;i++){
			A[i] = sc.nextInt();
		}
		int pmaxnum = 0;
		int pmax = 0;
		int mmaxnum = 0;
		int mmax = 0;
		for(int i=0;i<N;i++){
			if(A[i]>=0){
				if(pmax<=A[i]){
					pmax= A[i];
					pmaxnum = i+1;
				}
			}else{
				if(mmax>=A[i]){
					mmax = A[i];
					mmaxnum = i+1;
				}
			}
		}
		System.out.println(N*2-2);
		if(Math.abs(pmax)>=Math.abs(mmax)){
			for(int i=1;i<=N;i++){
				if(i!=pmaxnum)
				System.out.println(pmaxnum + " " + i);
			}
			for(int i=1;i<N;i++){
				System.out.println(i + " " + (i+1));
			}
		}else{
			for(int i=1;i<=N;i++){
				if(i!=mmaxnum)
				System.out.println(mmaxnum + " " + i);
			}
			for(int i=N;i>1;i--){
				System.out.println(i + " " + (i-1));
			}
		}
		

	}
}