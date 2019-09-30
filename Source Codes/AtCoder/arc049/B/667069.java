import java.util.Scanner;

class Main{
	static int n;
	static class P{
		final double x;
		final double y;
		final double c;
		P(double x,double y,double c){
			this.x=x;
			this.y=y;
			this.c=c;
		}
	}
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();

		P[] p=new P[n];	
		for(int i=0;i<n;i++){
			p[i]=new P(sc.nextDouble(),sc.nextDouble(),sc.nextDouble());
		}

		double sup=100000000;
		double low=0;


		for(int j=0;j<100;j++){
			double mid=(sup+low)/2;
			double R=1000000;
			double L=-1000000;
			double U=1000000;
			double D=-1000000;
			
			for(int i=0;i<n;i++){
				R=Math.min(R, p[i].x+mid/(p[i].c));			
				L=Math.max(L,p[i].x-mid/(p[i].c));
				U=Math.min(U, p[i].y+mid/(p[i].c));
				D=Math.max(D, p[i].y-mid/(p[i].c));
//				System.out.println("R"+R+"\n"
//						+"L"+L+"\n"
//						+"U"+U+"\n"
//						+"D"+D);
//				System.out.println("sup"+sup+"\n"+"low"+low+"\n");
			}
			if(R>=L&&U>=D){
				sup=mid;
			}else{
				low=mid;
			}
		}
		System.out.println(low);
	}
}