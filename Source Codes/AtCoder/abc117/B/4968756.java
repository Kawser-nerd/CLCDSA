import java.util.Scanner;
public class Main{
	public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int sum = 0;
	int max = 0;
	int arr[] = new int[N];
		for(int i=0; i<N; i++){
		arr[i] = sc.nextInt();
		sum = sum + arr[i];
			if(max<arr[i]){
			max=arr[i];
			}
		}
		if(max*2<sum){
		System.out.println("Yes");
		}else{
		System.out.println("No");
		}
	}
}