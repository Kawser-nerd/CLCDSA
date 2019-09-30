import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		int c=scan.nextInt();
		int d=scan.nextInt();
		int ans=100;
		int e[]=new int[d];
		e[0]=scan.nextInt();
		for(int i=1;i!=d;i++) {
			e[i]=scan.nextInt();
		}
		int count=0;
		for(int i=0;i!=d;i++) {
			count=0;
			if(e[i]==b) {count++;}
			if(e[i]==c) {count++;}
			for(int j=0;j!=d;j++) {
				if(e[i]==e[j]) {count++;}
			}
			if(count>=2) {ans=0;}
		}
		if(ans==0) {System.out.println("NO");}
		else {System.out.println("YES");}
}
}