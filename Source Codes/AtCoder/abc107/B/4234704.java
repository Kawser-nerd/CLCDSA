import java.util.Scanner;
public class Main {
public static void main(String[]srgs) {
	Scanner scan=new Scanner(System.in);
	int a=scan.nextInt();
	int b=scan.nextInt();
	String str[]=new String[a];
	boolean boolh[]=new boolean[a];
	boolean boolw[]=new boolean[b];
	for(int i=0;i<a;i++) {
		str[i]=scan.next();
	}
	for(int i=0;i<a;i++) {
		for(int j=0;j<b;j++) {
			if(str[i].charAt(j)=='#'){
				boolh[i]=true;
				boolw[j]=true;
			}
		}
	}
	for(int i=0;i<a;i++) {
		int count=0;
		for(int j=0;j<b;j++) {
			if(boolh[i]&&boolw[j]) {
				count=1;
				System.out.print(str[i].charAt(j));
			}
		}
		System.out.print(count==1?"\n":"");
	}
	scan.close();
}
}