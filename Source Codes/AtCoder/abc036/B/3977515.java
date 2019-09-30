import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		String b[]=new String[a];
		for(int i=0;i!=a;i++) {
			b[i]=scan.next();
		}
		String c[][]=new String[a][a];
		String d[][]=new String[a][a];
		for(int i=0;i!=a;i++) {
			for(int j=0;j!=a;j++) {
				String str=String.valueOf(b[i].charAt(j));
					d[i][j]=str;
			}
		}
		int count2=a-1;
		int count1=a-1;
		int k=0;
		for(;count2!=-1;) {
			count1=a-1;
			for(;count1!=-1;){
				c[count1][k]=d[count2][count1];
			count1--;
			}
			k++;
			count2--;
		}
		for(int i=0;i!=a;i++) {
			for(int j=0;j!=a;j++) {
				System.out.print(c[i][j]);
			}
			System.out.println();
		}
	}
}