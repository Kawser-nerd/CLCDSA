import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int data[] = new int[n];
		int group[] = new int[101];
		int sum = 0;
		for(int i = 0; i < n; i++) {
			data[i] = sc.nextInt();
			group[data[i]]++;
		}
		for(int i = 0; i < 101; i++) {
			if(group[i]>0) {
				sum++;
			}
		}
		System.out.println(sum);
	}
}