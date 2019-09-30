import java.util.Scanner;

public class Main {

	static int K;

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		K = scan.nextInt();
		int M = scan.nextInt();
		long[] A = new long[K];
		long[] C = new long[K];

		long one = Integer.parseInt("-1",2);
		long[][][] mat = new long[32][K][K];
		long[][] summat = new long[K][K];

		for(int i=0;i<K;i++){
			A[i] = Long.parseLong(scan.next());
		}

		for(int i=0;i<K;i++){
			C[i] = Long.parseLong(scan.next());

			summat[i][i]=one;
			mat[0][0][i]=C[i];
			if(i>0){
				mat[0][i][i-1]=one;
			}
		}
		for(int i=1;i<32;i++){
			mat[i]=matmult(mat[i-1],mat[i-1]);
		}

		long AM;

		if(M>K){
			String MK = String.format("%32s", Integer.toBinaryString(M-K)).replaceAll(" ", "0");
			for(int i=0;i<32;i++){
				String s = MK.substring(31-i, 32-i);
				if(s.equals("1")){
					summat=matmult(summat,mat[i]);
				}
			}

			AM=0;
			for(int i=0;i<K;i++){
				AM = AM^(summat[0][i]&A[K-1-i]);
			}
		}else{
			AM=A[M-1];
		}


		System.out.println(AM);



	}

	static long[][] matmult(long[][] x,long[][]y){
		long[][] ans = new long[K][K];
		for(int j=0;j<K;j++){
			for(int k=0;k<K;k++){
				for(int l=0;l<K;l++){
					ans[j][k]=ans[j][k]^(x[j][l]&y[l][k]);
				}
			}
		}
		return ans;
	}

}