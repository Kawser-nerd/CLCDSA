import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	int c[]=new int[a];
	long one=0;
	long zero=0;
	for(int i=0;i!=a;i++) {
		c[i]=scan.nextInt()%2;
	}
	for(int i=0;i!=a;i++) {
		if(c[i]==0) {
			zero++;
		}
		else {
			one++;
		}
	}
	long ans=1;
	if(one==0) {
		if(b==1) {
			System.out.println(0);
			return;
		}
		else {
			for(int i=0;i!=a;i++) {
				ans*=2;
			}
			System.out.println(ans);
			return;
		}
	}
	else {
		for(int i=1;i<a;i++) {
			ans*=2;
		}
		System.out.println(ans);
		return;
	}
	}
}