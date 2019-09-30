import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	double A,B,C;
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		A=sc.nextDouble();
		B=sc.nextDouble();
		C=sc.nextDouble();
		
		double left=0;
		double right=200;
		double mid=(left+right)/2;
		
		for(int i=0;i<100;i++){
			mid=(left+right)/2;
			if(func(mid)>100){
				right=mid;
			}else{
				left=mid;
			}
		}
		
		System.out.println(left);
		
	}
	double func(double t){
		return A*t+B*Math.sin(C*t*Math.PI);
	}
}