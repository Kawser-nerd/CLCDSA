import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		long T[]=new long[N];
		int z=0,s=0,t=0;
		long y=0,x=0,w=0;
		while(z<N){
			T[z]=stdIn.nextLong();
			z++;
		}z=0;
		Arrays.sort(T);
		while(z<N-1){
			y=T[z];x=T[z+1];
			while(true){
				if(x==y){
					s=2;
					break;
				}
				if(x>y){
					s=0;
					if(x%y==0)
						break;
					else{
						w=y;
						y=x%y;
						x=w;
					}
				}
				if(y>x){
					s=1;
					if(y%x==0)
						break;
					else{
						w=x;
						x=y%x;
						y=w;
					}
				}
			}
			if(s==0)
				T[z+1]=T[z]/y*T[z+1];
			if(s==1)
				T[z+1]=T[z]/x*T[z+1];
			if(s==2)
				t=0;
			z++;
		}
		System.out.println(T[z]);
	}
}