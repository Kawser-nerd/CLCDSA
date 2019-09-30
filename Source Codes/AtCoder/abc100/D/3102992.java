import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int[] a= {1,1,1,1,-1,-1,-1,-1};
		int[] b= {1,1,-1,-1,1,1,-1,-1};
		int[] c= {1,-1,1,-1,1,-1,1,-1};

		long kati=Long.MIN_VALUE;
		long tmp=Long.MIN_VALUE;
		int N=sc.nextInt();
		int M=sc.nextInt();
		long[] x=new long[N];
		long[] y=new long[N];
		long[] z=new long[N];

		long[] maxes=new long[N];
		for(int i=0; i<N; i++) {
			x[i]=sc.nextLong();
			y[i]=sc.nextLong();
			z[i]=sc.nextLong();
		}

		for(int i=0; i<8; i++) {
			tmp=0;
			for(int j=0; j<N; j++) {
				maxes[j]=x[j]*a[i]+y[j]*b[i]+z[j]*c[i];
			}
			Arrays.sort(maxes);
			for(int k=0; k<M; k++) {
				tmp+=maxes[N-1-k];
			}
			kati=Math.max(kati, tmp);
		}
		System.out.println(kati);
	}
}