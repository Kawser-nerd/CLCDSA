import java.util.Scanner;
 
public class Main {
	public static void main(String[] args){
		try(Scanner sc=new Scanner(System.in)){
			int N=sc.nextInt();
			int[] w=new int[N];
			int[] d=new int[N];
			for(int i=0; i<N; i++) {
				w[i]=sc.nextInt();
				d[i]=10000000;
			}
			int ret=0;
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(d[j]>=w[i]) {
						d[j]=w[i];
						//System.out.println(i+" "+j+":"+d[j]);
						ret=Math.max(ret, j+1);
						break;
					}
				}
			}
			System.out.println(ret);
			
		}
	}	
}