import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] name=new String[n];
		int[] vote = new int[n];
		int max= 0;
		for(int i =0;i<n;i++) {
			name[i]=sc.next();
		}
		
		for(int i =0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(name[i].equals(name[j])) {
					vote[i]++;
				}
			}
		}
		
		for(int i=0;i<n;i++) {
			max=Math.max(vote[i], max);
		}
		for(int i=0; i<n;i++) {
			if(vote[i]==max) {
				System.out.println(name[i]);
				break;
			}
		}
	}
}