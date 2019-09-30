import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int c=scan.nextInt(),d=scan.nextInt();
		int a=scan.nextInt();
		int b[]=new int[a];
		for(int i=0;i!=a;i++) {
			int e=scan.nextInt();
			if(e<c) {
				b[i]=c-e;
			}
			else {
				b[i]=e>d?-1:0;
			}
		}
		for(int i=0;i!=a;i++) {
			System.out.println(b[i]);
		}
	}
}