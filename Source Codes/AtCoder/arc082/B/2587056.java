import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] p = new int[n];
		for(int i=0;i<n;i++){
			p[i] = sc.nextInt();
		}

		int count = 0;
		for(int i=0;i<n;i++){
			if(i==n-1 && p[i] == (i+1)){
				int x = p[i];
				p[i] = p[i-1];
				p[i-1] = x;
				count++;
			}
			else if(p[i] == (i+1)){
				int x = p[i];
				p[i] = p[i+1];
				p[i+1] = x;
				count++; 
			}
		}
		System.out.println(count);
	}
}