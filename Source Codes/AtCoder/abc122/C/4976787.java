import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		int N,Q;
		String str;

		N=sc.nextInt();
		Q=sc.nextInt();
		str=sc.next();

		int[] l=new int[Q];
		int[] r=new int[Q];

		for(int i=0;i<Q;i++) {
			l[i]=sc.nextInt();
			r[i]=sc.nextInt();
		}

		int[] sum=new int[N+1];

		char a='A';
		char c='C';

		for(int i=1;i<N;i++) {
			if(str.charAt(i-1)==a && str.charAt(i)==c) {
				sum[i+1]=sum[i]+1;
			}else {
				sum[i+1]=sum[i];
			}
		}


		for(int i=0;i<Q;i++) {
			int ans=sum[r[i]]-sum[l[i]];
			System.out.println(ans);
		}

		sc.close();

	}

}