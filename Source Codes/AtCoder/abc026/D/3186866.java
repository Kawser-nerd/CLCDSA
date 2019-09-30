import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		double A=(double)(sc.nextInt());
		double B=(double)(sc.nextInt());
		double C=(double)(sc.nextInt());
		double PI=3.1415926535897932384626d;

		if(A-B>=0) {	//??????
			double min=0d;
			double max=100d;

			while(Math.abs(A*min+B*Math.sin(C*PI*min)-100d)>0.0000001) {
				double middle=(min+max)/2;
				if(A*middle+B*Math.sin(C*PI*middle)-100d<0) {
					min=middle;
				}
				else {
					max=middle;
				}
			}
			System.out.println(min);
		}

		else {		//?????????		??????????0?1/2??????	??????????????
			double niPi=1/(2*C);
			if(A*niPi+B*Math.sin(C*PI*niPi)-100d>0){		//??????????

				double min=0d;
				double max=niPi;

				while(Math.abs(A*min+B*Math.sin(C*PI*min)-100d)>0.00000001) {
					double middle=(min+max)/2;
					if(A*middle+B*Math.sin(C*PI*middle)-100d<0) {
						min=middle;
					}
					else {
						max=middle;
					}
				}
				System.out.println(min);
			}

			else {
				int counter=1;
				double min=0;
				double max=0;
				double middle=0;
				while(min<100d) {
					max=(1+4*counter)/(2*C);
					min=(-1+4*counter)/(C*2);
					double low=A*min+B*Math.sin(C*min*PI);
					double sup=A*max+B*Math.sin(C*max*PI);
					if(sup<100d && low<100d) {
						counter++;
						continue;
					}
					else if(low>100d && sup>100d) {
						counter++;
						continue;
					}
					else if(low<=100d && sup>=100d) {
						low=A*min+B*Math.sin(C*min*PI);
						sup=A*max+B*Math.sin(C*max*PI);
						middle=(min+max)/2;
						middle=A*middle+B*Math.sin(C*middle*PI);
						while(true) {
							middle=(min+max)/2;
							middle=A*middle+B*Math.sin(C*middle*PI);
							if(middle<100d) {
								min=(min+max)/2;
							}
							else if(middle>100d) {
								max=(min+max)/2;
							}
							low=A*min+B*Math.sin(C*min*PI);
							sup=A*max+B*Math.sin(C*max*PI);

							if(Math.abs(low-100d)<0.00000001) {
								System.out.println(min);
								System.exit(0);
							}
						}

					}

				}
			}

		}
	}
}