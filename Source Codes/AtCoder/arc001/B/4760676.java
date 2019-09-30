import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		String s=sc.next();
		int[]cnt=new int[4];
		for(int i=0;i<n;i++) {
			switch(s.charAt(i)) {
			case '1':
				cnt[0]++;
				break;
			case '2':
				cnt[1]++;
				break;
			case '3':
				cnt[2]++;
				break;
			case '4':
				cnt[3]++;
				break;
			}
		}
		int max=0,min=n;
		for(int i=0;i<4;i++) {
			max=Math.max(max, cnt[i]);
			min=Math.min(min, cnt[i]);
		}
		System.out.println(max+" "+min);
	}
}