import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		int arr[] = new int[55];
		while(n--!=0) {
			int w = sc.nextInt();
			int yes = 0;
			int mid=100005,j=-1;
			for (int i = 0; i < arr.length; i++) {
				if(arr[i]==w) {
					yes = 1;
					break;
				}
				if(arr[i]>w) {
					if(arr[i]-w<mid) {
						mid = arr[i]-w;
						j=i;
					}
				}
				if(arr[i]==0) break;
			}
			if(yes == 0 && j!=-1) {
				arr[j] = w;
			}
			if(yes == 0&&j==-1) {
				for (int i = 0; i < arr.length; i++) {
					if(arr[i]==0) {
						arr[i]=w;
						ans++;
						break;
					}
				}
			}
		}
		System.out.println(ans);
	}
}