import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int[] x = new int[100001];
		for(int i=2;i<=100000;i++) {
			x[i] = 1;
		}
		for(int i=2;i<=100000;i++) {
			if(x[i]==0) continue;
			int j = i+i;
			while(j<=100000) {
				x[j] = 0;
				j += i;
			}
		}
		
		int[] like2017 = new int[100001];
		like2017[3] = 1;
		like2017[5] = 1;
		for(int i=9;i<=100000;i+=4) {
			if(x[i]==1 && x[(i+1)/2]==1) like2017[i] = 1;
		}
		for(int i=1;i<=100000;i++) {
			like2017[i] += like2017[i-1];
		}
		
		Scanner in = new Scanner(System.in);
		int q = in.nextInt();
		int[] l = new int[q];
		int[] r = new int[q];
		for(int i=0;i<q;i++) {
			l[i] = in.nextInt();
			r[i] = in.nextInt();
		}
		for(int i=0;i<q;i++) {
			System.out.println(like2017[r[i]]-like2017[l[i]-1]);
		}
		in.close();
	}

}