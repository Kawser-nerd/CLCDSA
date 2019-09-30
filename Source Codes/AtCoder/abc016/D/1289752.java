import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int a[]=new int[2];
		a[0]=scan.nextInt();
		a[1]=scan.nextInt();
		kP A = new kP(a[0],a[1]);

		a[0]=scan.nextInt();
		a[1]=scan.nextInt();
		kP B = new kP(a[0],a[1]);
		int N=scan.nextInt();
		kP[] X = new kP[N+1];
		for(int i=0;i<N;i++){
			a[0]=scan.nextInt();
			a[1]=scan.nextInt();
			X[i]=new kP(a[0],a[1]);
		}
		X[N]=new kP(X[0].x,X[0].y);

			int cnt=0;
			for(int i=1;i<N+1;i++){

				int g1=gaiseki(A,B,A,X[i]);
				int g2=gaiseki(A,B,A,X[i-1]);
				int g3=gaiseki(X[i],X[i-1],X[i],A);
				int g4=gaiseki(X[i],X[i-1],X[i],B);
				if(g1*g2<0&&g3*g4<0){
					cnt++;
				}
			}
			System.out.println(cnt/2 +1);
	}

	static int gaiseki(kP a,kP b,kP c,kP d){
		//ab×cd???
		//???????
		kP vA = new kP(b.x-a.x,b.y-a.y);
		kP vB = new kP(d.x-c.x,d.y-c.y);
		if(vA.x*vB.y>vA.y*vB.x){
			return 1;
		}else if(vA.x*vB.y<vA.y*vB.x){
			return -1;
		}else{
			return 0;
		}


	}
}

class kP{
	int x;
	int y;
	kP(int x_,int y_){
		x=x_;
		y=y_;
	}
}