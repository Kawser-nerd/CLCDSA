import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve();
	}
	int MAX_RATE=100000;
	void solve() {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]r=new int[n];
		int[]h=new int[n];
		for(int i=0;i<n;i++) {
			r[i]=sc.nextInt()-1;
			h[i]=sc.nextInt()-1;
		}
		ArrayList<Integer>[]rate=new ArrayList[MAX_RATE];
		for(int i=0;i<MAX_RATE;i++) {
			rate[i]=new ArrayList<Integer>();
		}
		for(int i=0;i<n;i++) {
			rate[r[i]].add(i);
		}
		int[][]ans=new int[n][3];
		int k=0;
		int A=0,B=0,C=0;
		for(int i=0;i<MAX_RATE;i++) {
			A=0; //??
			B=0; //???
			C=0; //??
			for(int j=0;j<rate[i].size();j++) {
				if(h[rate[i].get(j)]==0)A++;
				else if(h[rate[i].get(j)]==1)B++;
				else if(h[rate[i].get(j)]==2)C++;
			}
			for(int j=0;j<rate[i].size();j++) {
				int idx=rate[i].get(j);
				if(h[rate[i].get(j)]==0) {
					ans[idx][0]=k+B;
					ans[idx][1]=n-k-A-B;
					ans[idx][2]=A-1;
				}else if(h[rate[i].get(j)]==1) {
					ans[idx][0]=k+C;
					ans[idx][1]=n-k-B-C;
					ans[idx][2]=B-1;
				}else if(h[rate[i].get(j)]==2){
					ans[idx][0]=k+A;
					ans[idx][1]=n-k-C-A;
					ans[idx][2]=C-1;
				}
			}
			k+=rate[i].size();
		}
		for(int i=0;i<n;i++) {
			System.out.println(ans[i][0]+" "+ans[i][1]+" "+ans[i][2]);
		}
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.