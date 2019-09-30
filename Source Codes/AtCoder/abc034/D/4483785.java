import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main (String[] args) throws Exception {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int K=sc.nextInt();
		double[][] nacl=new double[N][2];
		double EPS=0.001d;
		for(int i=0; i<N; i++) {
			nacl[i][0]=sc.nextDouble()/100;
			nacl[i][1]=sc.nextDouble();
		}
		double lower=0d;
		double upper=100d;
		double[] sio=new double[N];
		for(int h=0; h<60; h++){
			//pl(upper+" "+lower+" "+(upper-lower));
			double middle=(lower+upper)/2;
			for(int i=0; i<N; i++) {
				sio[i]=(nacl[i][1]-middle)*nacl[i][0];
			}
			Arrays.sort(sio);
			double sum=0;
			for(int i=0; i<K; i++) {
				sum+=sio[N-1-i];
			}
			if(sum>EPS) {
				lower=middle;
			}
			else if(sum<-EPS) {
				upper=middle;
			}
			else {
			}
		}
		pl((upper+lower)/2);
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}