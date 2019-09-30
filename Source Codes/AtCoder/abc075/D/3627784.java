import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		List<int[]> list = new ArrayList<>();
		for(int i=0;i<n;i++) {
			int[] tmp = {in.nextInt(),in.nextInt()};
			list.add(tmp);
		}
		list.sort((x1,x2)->x1[0]-x2[0]);
		
		long ans = Long.MAX_VALUE;
		for(int i=0;i<n-k+1;i++) {
			for(int j=i+k-1;j<n;j++) {
				int[] y = new int[j-i+1];
				for(int l=0;l<j-i+1;l++) {
					y[l] = list.get(l+i)[1];
				}
				Arrays.sort(y);
				int yWidthMin = y[k-1] - y[0];
				for(int l=1;l+k-1<j-i+1;l++) {
					yWidthMin = Math.min(yWidthMin, y[l+k-1]-y[l]);
				}
				int xWidth = list.get(j)[0] - list.get(i)[0];
				ans = Math.min(ans, (long)xWidth*yWidthMin);
			}
		}
		
		System.out.println(ans);
		in.close();
		

	}

}