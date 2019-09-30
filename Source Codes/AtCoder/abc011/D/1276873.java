import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int N=scan.nextInt();
		int D=scan.nextInt();
		int X=scan.nextInt();
		int Y=scan.nextInt();

		double ans=0;

		if(X%D==0&&Y%D==0){
			double x=Math.abs(X/D);
			double y=Math.abs(Y/D);

			if((N-x-y)%2==0&&x+y<=N){
				//??
				double K=(N-x-y)/2;

				double[] M=new double[4];

				for(int a=0;a<=K;a++){
					M[0]=x+a;
					M[1]=a;
					M[2]=y+K-a;
					M[3]=K-a;
					double s=1;
					for(int i=0;i<N;i++){
/*						if(i<x+a){
							s*=(i+1)/(4*(x+a-i));
						}else if(i <x+2*a){
							s*=(i+1)/(4*(x+2*a-i));
						}else if(i <x+y+K+a){
							s*=(i+1)/(4*(x+y+K+a-i));
						}else{
							s*=(i+1)/(4*(x+y+2*K-i));
						}*/

						Arrays.sort(M);
						s*=(N-i)/(4*M[3]);
						M[3]--;
					}
					ans+=s;
				}
			}
		}
		System.out.println(ans);
	}

}