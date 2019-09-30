import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		int C[]=new int[N-1];
		int S[]=new int[N-1];
		int F[]=new int[N-1];
		int z=0,y=0,time=0;
		while(z<N-1){
			C[z]=stdIn.nextInt();
			S[z]=stdIn.nextInt();
			F[z]=stdIn.nextInt();
			z++;
		}z=0;
		while(z<N-1){
			y=z;
			while(y<N-1){
				if(y==0)
					time+=C[y]+S[y];
				else{
					if(time>S[y]){
						if((time-S[y])%F[y]==0)
							time+=C[y];
						else
							time+=((time-S[y])/F[y]+1)*F[y]-(time-S[y])+C[y];
					}
					else
						time+=(S[y]-time)+C[y];
				}
				y++;
			}
			z++;
			System.out.println(time);
			time=0;
		}
		System.out.println(time);
	}

}