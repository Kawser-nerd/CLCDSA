import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int D=sc.nextInt();
		int K=sc.nextInt();
		int[]L=new int[D];
		int[]R=new int[D];
		for(int i=0;i<D;i++){
			L[i]=sc.nextInt();
			R[i]=sc.nextInt();
		}
		int[]S=new int[K];
		int[]T=new int[K];
		for(int i=0;i<K;i++){
			S[i]=sc.nextInt();
			T[i]=sc.nextInt();
		}
		int[] day=new int[K];
		for(int i=0;i<D;i++){
			for(int j=0;j<K;j++){
				if(S[j]==T[j])continue;
				day[j]++;
				if(L[i]<=S[j] && S[j]<=R[i]){
					if(L[i]>T[j])S[j]=L[i];
					else if(R[i]<T[j])S[j]=R[i];
					else S[j]=T[j];
				}
			}
		}
		for(int i=0;i<K;i++)System.out.println(day[i]);
	}
	
}