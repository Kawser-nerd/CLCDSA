import java.util.Scanner;
public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan=new Scanner(System.in);
		int A=scan.nextInt();
		int B=scan.nextInt();
		int C=scan.nextInt();
		int d[][]=new int[B][A];
		for(int i=0;i!=B;i++) {
			for(int j=0;j!=A;j++) {
				d[i][j]=1;
			}
		}
		for(int i=0;i!=C;i++) {
			int a=scan.nextInt();
			int b=scan.nextInt();
			int c=scan.nextInt();
			if(c==1) {
				for(int j=a-1;j!=-1;j--) {
					for(int k=0;k!=B;k++) {
						d[k][j]=0;
					}
				}
			}	if(c==2) {
				for(int j=a;j!=A;j++) {
					for(int k=0;k!=B;k++) {
						d[k][j]=0;
					}
				}
			}	if(c==3) {
				for(int j=B-b;j!=B;j++) {
					for(int k=0;k!=A;k++) {
						d[j][k]=0;
					}
				}
			}	if(c==4) {
				for(int j=B-b-1;j!=-1;j--) {
					for(int k=0;k!=A;k++) {
						d[j][k]=0;
					}
				}
			}
		}
		int ans=0;
		for(int j=0;j!=B;j++) {
			for(int k=0;k!=A;k++) {
				if(d[j][k]==1) {
					ans++;
			}
			}
	}
		System.out.println(ans);
	}
}