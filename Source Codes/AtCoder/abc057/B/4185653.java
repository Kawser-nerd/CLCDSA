import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int c[][]=new int[a][2];
	int d[][]=new int[b][2];
	int m[]=new int[a];
	for(int i=0;i!=a;i++) {
		c[i][0]=scan.nextInt();
		c[i][1]=scan.nextInt();
	}
	for(int i=0;i!=b;i++) {
		d[i][0]=scan.nextInt();
		d[i][1]=scan.nextInt();
	}
	for(int i=0;i!=a;i++) {
		int min=1145148101;
		int C=0;
		for(int j=0;j!=b;j++) {
			int K=0;
			K=Math.abs(c[i][0]-d[j][0])+Math.abs(c[i][1]-d[j][1]);
			if(K<min) {
				min=K;
				C=j+1;
			}
		}
		m[i]=C;
	}
	for(int i=0;i!=a;i++) {
		System.out.println(m[i]);
	}
}
}