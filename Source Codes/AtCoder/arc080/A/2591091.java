import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++){
			a[i] = sc.nextInt();
		}
		int[] num = new int[3];
		for(int i=0;i<n;i++){
			if(a[i]%4==0){
				num[0]++;
			}
			else if(a[i]%2==0){
				num[1]++;
			}
			else{
				num[2]++;
			}
		}
		if(num[2]>num[0]+1){
			System.out.println("No");
		}
		else if(num[2]>num[0] && num[1]!=0){
			System.out.println("No");
		}
		else if(num[2]!=0 && num[0]==0){
			System.out.println("No");
		}
		else{
			System.out.println("Yes");
		}
	} 
}