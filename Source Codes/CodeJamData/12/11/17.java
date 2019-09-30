import java.util.Scanner;


public class a {

	/**
	 * @param args
	 */
	Scanner in=new Scanner(System.in);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new a().go();
	}
	private void go() {
		// TODO Auto-generated method stub
		int numc=in.nextInt();
		for(int cnum=0;cnum<numc;cnum++){
			int a=in.nextInt(),b=in.nextInt();
			double[] p=new double[a];
			for(int i=0;i<a;i++)p[i]=in.nextDouble();
			double[] pp=new double[a+1];
			pp[0]=1;
			for(int i=1;i<=a;i++)pp[i]=pp[i-1]*p[i-1];
			double min=2+b;
			for(int i=0;i<=a;i++){
				double pcor=pp[a-i];
				min=Math.min(min, pcor*(i+i+b-a+1)+(1-pcor)*(i+i+b-a+1+b+1));
			}
			System.out.printf("Case #%d: %.7f\n", cnum+1,min);
		}

	}

}
