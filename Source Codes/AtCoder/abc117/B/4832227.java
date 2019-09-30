import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int l[] = new int[n];
		for(int i = 0; i < n; i++){
			l[i] = sc.nextInt();
		}
		Arrays.sort(l);
		int sum = 0;
		for(int i = 0; i < n-1; i++){
			sum+= l[i];
		}
		System.out.print(l[n-1] < sum?"Yes":"No");
	}
}