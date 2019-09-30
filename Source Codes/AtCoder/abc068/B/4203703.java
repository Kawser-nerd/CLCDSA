import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int ans=0;
	int ansc=0;
	for(int i=1;i!=a+1;i++) {
		int count=0;
		for(int j=i;j%2==0;count++,j/=2) {}
			if(ansc<count) {
				ans=i;
				ansc=count;
			}
	}
	System.out.println(a==1?1:ans);
}
}