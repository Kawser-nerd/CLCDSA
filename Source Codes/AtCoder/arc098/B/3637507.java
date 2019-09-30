import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		
		int[] A = new int[N];
		for(int i=0;i<N;i++){
			A[i] = sc.nextInt();
		}
		
		int[] bit = new  int[20];
		
		int l = 0;
		int r = 0;
		
		long ans = 1;
		for(int i=0;i<20;i++){
			if((A[0]>>i&1) == 1){
				bit[i]++;
			}
		}
		
		while(l<N){			
			if(isOK(bit)&&r==N-1){
			
				break;
			}
			
			if(isOK(bit)&&r==N-1){
				break;
			}
			if(isOK(bit)&&r<N-1){
				r++;
				for(int i=0;i<20;i++){
					bit[i] += A[r]>>i&1;
				}
				if(isOK(bit)){
					ans += r-l+1;
					
				}
			}else{
				
				for(int i=0;i<20;i++){
					bit[i] -= A[l]>>i&1;
				}
				
				l++;
				if(isOK(bit)){
					ans += r-l+1;
				}
			}
		}

		
		
		System.out.println();
		System.out.println(ans);
		
		
		
		
	}
	
	static void show(int[] a ,int b,int c) {
		for(int i=0;i<20;i++){
			System.out.print(a[i]);
		}
		System.out.println(" " + b + " " + c);
	}

	static Boolean isOK(int[] a){
		for(int i=0;i<20;i++){
			if(a[i]>1){
				return false;
			}
		}
		return true;
	}
	

}