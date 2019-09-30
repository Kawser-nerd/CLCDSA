import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[]$){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),v[][]=new int[n][3],max[]={0,0,0};
		for(int i=0;i<n;++i) {
			for(int j=0;j<3;++j)
				v[i][j]=s.nextInt();
			Arrays.sort(v[i]);
			for(int j=0;j<3;++j)
				max[j]=Math.max(max[j],v[i][j]);
		}
		System.out.println(max[0]*max[1]*max[2]);
	}
}