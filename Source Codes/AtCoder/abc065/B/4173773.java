import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		int b[]=new int[a];
		int fig=0;
		for(int i=0;i!=a;i++) {
			b[i]=scan.nextInt();
		}
		int za=0;
		int count=0;
		for(int i=0;i!=a+1;i++) {
			if(b[za]==2) {
				fig=1;
				count=i+1;
				break;
			}
			za=b[za]-1;
		}
		System.out.println(fig==1?count:-1);
	}
}