import java.util.Arrays;
import java.util.Scanner;
	

public class Main{

	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		long W = sc.nextLong();
		int[] w = new int[N];
		int[] v = new int[N];
		for(int i=0;i<N;i++){
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}
		
		int[] num = new int[4];
		for(int i=0;i<N;i++){
			num[w[i]-w[0]]++;
		}
		
		int[] w0 = new int[num[0]];
		int[] w1 = new int[num[1]];
		int[] w2 = new int[num[2]];
		int[] w3 = new int[num[3]];
		int[] p = new int[4];
		for(int i=0;i<N;i++){
			switch(w[i]-w[0]){
			case 0:
				w0[p[0]] = v[i];
				p[0]++;
				break;
			case 1:
				w1[p[1]] = v[i];
				p[1]++;
				break;
			case 2:
				w2[p[2]] = v[i];
				p[2]++;
				break;
			case 3:
				w3[p[3]] =v[i];
				p[3]++;
				break;
			}
		}
		
		Arrays.sort(w0);
		Arrays.sort(w1);
		Arrays.sort(w2);
		Arrays.sort(w3);
		
		int[] W0 = new int[num[0]+1];
		int[] W1 = new int[num[1]+1];
		int[] W2 = new int[num[2]+1];
		int[] W3 = new int[num[3]+1];
		
		for(int i=1;i<=num[0];i++){
			W0[i] = W0[i-1] + w0[num[0]-i];
		}
		
		for(int i=1;i<=num[1];i++){
			W1[i] = W1[i-1] + w1[num[1]-i];
		}
		
		for(int i=1;i<=num[2];i++){
			W2[i] = W2[i-1] + w2[num[2]-i];
		}
		
		for(int i=1;i<=num[3];i++){
			W3[i] = W3[i-1] + w3[num[3]-i];
		}
		
		long wsum = 0;
		long max = 0;
		for(int i=0;i<=num[0];i++){
			for(int j=0;j<=num[1];j++){
				for(int k=0;k<=num[2];k++){
					for(int l=0;l<=num[3];l++){
						wsum = (long)w[0]*(long)(i+j+k+l) + (long)(j+k+k+l+l+l);
						if(wsum<=W){
							max = Math.max(max, W0[i]+W1[j]+W2[k]+W3[l]);
						}
					}
				}
			}
		}
		System.out.println(max);
	}
	

}