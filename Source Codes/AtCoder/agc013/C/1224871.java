import java.util.Arrays;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int N =scan.nextInt();
		int L =scan.nextInt();
		long T =scan.nextInt();
		int[] X=new int[N];
		int[] W=new int[N];

		long[] x=new long[N];


		for(int i=0;i<N;i++){
			X[i]=scan.nextInt();
			W[i]=scan.nextInt();
			x[i]=X[i]+T*(3-2*W[i]);
			while(true)
			{
				if(x[i]>0)break;
				x[i]+=L;
			}
			x[i]%=L;

		}
		long x0 = x[0];
		Arrays.sort(x);

		long cnt=0;
		if(W[0]==1){
			for(int i=1;i<N;i++){
				if(W[i]==1){continue;}
					cnt+=(2*T-X[i]+X[0]+L)/L;
				}
					cnt%=N;
		}else{
			for(int i=N-1;i>0;i--){
				if(W[i]==2){continue;}
					cnt-=(2*T-X[0]+X[i])/L;
				}
			while(true)
			{
				if(cnt>0)break;
				cnt+=N;
			}
			cnt%=N;
			}

		int ini=0;
		for(int i=0;i<N;i++){
			if(x[i]==x0){
				if(i<N-1&&x[i+1]==x0&&W[0]==1){
					ini = i+1 - (int)cnt;
					break;
				}
				ini = i-(int)cnt;
				break;
			}
		}

		for(int i=0;i<N;i++){
			System.out.println(x[(ini+i+N)%N]);
		}



	}

}