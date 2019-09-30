import java.util.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),c=s.nextInt();
		int l=100001;
		int[][]r=new int[c+1][l];
		for(int i=0;i<n;++i) {
			int f=s.nextInt(),t=s.nextInt(),d=s.nextInt();
			r[d][f]++;
			r[d][t]--;
		}
		for(int i=1;i<=c;++i) {
			r[0][0]+=r[i][0];
			for(int j=1;j<l;++j) {
				r[0][j]+=(r[i][j]+=r[i][j-1]);
				if(r[i][j]>0&&r[i][j-1]==0)
					r[0][j-1]++;
			}
		}
		//Arrays.stream(r).map(Arrays::toString).forEach(System.err::println);
		System.out.println(Arrays.stream(r[0]).max().getAsInt());
	}
}