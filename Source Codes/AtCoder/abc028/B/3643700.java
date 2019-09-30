import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		int[] cnt=new int[6];
		for(int i=0; i<6; i++) {
			cnt[i]=0;
		}

		for(int i=0; i<a.length(); i++) {
			cnt[a.charAt(i)-65]++;
		}
		System.out.println(cnt[0]+" "+cnt[1]+" "+cnt[2]+" "+cnt[3]+" "+cnt[4]+" "+cnt[5]);
	}
}