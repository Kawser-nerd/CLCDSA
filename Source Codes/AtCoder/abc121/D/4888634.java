import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long fa = 0;
        long fb = 0;
        for(int i=0;i<50;i++){
        	long x = (long)Math.pow(2,i);
        	long count = (a-1) / (2*x);
        	count = count * x;
        	count += (long)Math.max(0, (a-1) - (a-1)/(2*x)*(2*x) - (x-1));
        	if(count%2==1){
        		fa += x;
        	}
        }

        for(int i=0;i<50;i++){
        	long x = (long)Math.pow(2,i);
        	long count = b / (2*x);
        	count = count * x;
        	count += (long)Math.max(0, b - b/(2*x)*(2*x) - (x-1));
        	if(count%2==1){
        		fb += x;
        	}
        }

        System.out.println(fa^fb);
    }
}