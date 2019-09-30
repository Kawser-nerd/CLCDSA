import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b[]=new int[a];
	int ans=999999999;
	int max=0;
	int min=999999999;
	for(int i=0;i<a;i++) {
		b[i]=scan.nextInt();
		if(b[i]<min) {
			min=b[i];
		}
		if(b[i]>max) {
			max=b[i];
		}
	}
	for(int i=min;i<=max;i++) {
		int count=0;
		for(int j=0;j!=a;j++) {
			if(b[j]==i) {
				continue;
			}
			else {
				count+=(b[j]-i)*(b[j]-i);
			}
		}
		if(ans>count) {
			ans=count;
		}
	}
	System.out.println(ans);
	scan.close();
	}
}