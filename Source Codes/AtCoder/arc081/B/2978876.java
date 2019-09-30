import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		long mod=1000000007;
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		char[] s1=sc.next().toCharArray();
		char[] s2=sc.next().toCharArray();
		long sol = (s1[0]==s2[0])?3:6;
		for(int i=1;i<n;i++){
			if(s1[i]==s2[i]&&s1[i-1]==s2[i-1] && s1[i]!=s1[i-1]&&s2[i]!=s2[i-1]){
				sol=(sol*2)%mod;
			}else if(s1[i]!=s2[i]&&s1[i-1]==s2[i-1] && s1[i]!=s1[i-1]&&s2[i]!=s2[i-1]){
				sol=(sol*2)%mod;				
			}else if(s1[i]!=s2[i]&&s1[i-1]!=s2[i-1] && s1[i]!=s1[i-1]&&s2[i]!=s2[i-1]){
				sol=(sol*3)%mod;				
			}
		}
		System.out.println(sol);
	}
}