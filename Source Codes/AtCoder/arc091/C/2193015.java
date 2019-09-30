import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		int B = sc.nextInt();
		int sq = (int)Math.sqrt((double)N);
		if((A+B>N+1) || (A<sq && B<sq)) System.out.println(-1);
		else if(A+B==N+1){
			for(int i=B;i<=N;++i) System.out.print(i+" ");
			for(int i=B-1;i>=1;--i) System.out.print(i+" ");
			System.out.println();
		}else{
			int tempA = (N/B)+(N%B!=0? 1:0);
			int hidari = 0;
			while(tempA+hidari!=A){
				hidari++;
				if(hidari>N){
					System.out.println(-1);
					return;
				}
				if((N-hidari)%B==0) tempA--;
			}
			
			int[] a = new int[N];
			int count = 0;
			for(int i=1;i<=hidari;++i){
				a[count] = i;
				count++;
			}
			int nowN = N-hidari;
			for(int i=1;i<=nowN/B;i++){
				for(int j=i*B;j>(i-1)*B;j--){
					a[count] = j+hidari;
					count++;
				}
			}
			for(int j=nowN;j>B*(nowN/B);--j){
				a[count] = j+hidari;
				count++;
			}
			for(int i=0;i<N;++i) System.out.print(a[i]+" ");
			System.out.println();
		}
		return;
	}
}