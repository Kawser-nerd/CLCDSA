import java.util.Scanner;
	

public class Main{

	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		int K = sc.nextInt();
		long[] a = new long[N];
		

		for(int i=0;i<N;i++){
			a[i] = sc.nextLong();
		}
		
		long[] s = new long[N+1];
		long[] bla = new long[N+1];
		
		for(int i=0;i<N;i++){
			s[i+1] = s[i] + a[i];
			if(a[i]>0){
				bla[i+1] = bla[i] + a[i];
			}else{
				bla[i+1] = bla[i];
			}
		}
		long max = 0;
		
		for(int i=0;i<N-K+1;i++){
			
			max = Math.max(max,bla[i]-bla[0]+Math.max(s[i+K]-s[i],0)+bla[N]-bla[i+K]);
		}

		System.out.println(max);
	}
	

}