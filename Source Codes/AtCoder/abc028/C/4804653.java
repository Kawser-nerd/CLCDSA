import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int[]x=new int[5];
		for(int i=0;i<5;i++) {
			x[i]=sc.nextInt();
		}
		List<Integer>sum=new ArrayList<>();
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				if(j==i)
					continue;
				for(int k=0;k<5;k++) {
					if(k==i||k==j)
						continue;
					int s=x[i]+x[j]+x[k];
					if(!sum.contains(s))
							sum.add(s);
				}
			}
		}
		Collections.sort(sum,Collections.reverseOrder());
		System.out.println(sum.get(2));
	}
}