import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		long h = sc.nextLong();
		long count=0;
		long r = 0;
		ArrayList<Long> b1=new ArrayList<Long>();
		for(int i = 0; i<n; i++){
			long a = sc.nextLong();
			long b = sc.nextLong();
			r=Math.max(r,a);
			b1.add(b);
		}
		Collections.sort(b1);
		for(int i=b1.size()-1; i>=0; i--){
			if(b1.get(i)<=r){
					break;
			}
			count++;
			h-=b1.get(i);
			if(h<=0){
				System.out.println(count);
				return;
			}
		}
			if(h%r==0){
				System.out.println(count+h/r);
			}else{
				System.out.println(count+h/r+1);
			}
	}
}