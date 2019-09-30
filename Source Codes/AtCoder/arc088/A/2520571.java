import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		long y = sc.nextLong();
		long count = 0;
		while(x <= y){
			count++;
			x *= 2;
		}
		System.out.println(count);
	}
}