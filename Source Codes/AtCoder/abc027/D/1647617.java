import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        new Main().solve();
    }
    
   void solve() {
	   Scanner sc=new Scanner(System.in);
	   String s=sc.next();
	   int m=0;
	   int n=s.length();
	   for(int i=0;i<n;i++) {
		   if(s.charAt(i)=='M')m++;
	   }
	   int[]a=new int[m];
	   int countp=0;
	   int countm=0;
	   int j=0;
	   for(int i=n-1;i>=0;i--) {
		   if(s.charAt(i)=='+')countp++;
		   else if(s.charAt(i)=='-')countm++;
		   else if(s.charAt(i)=='M') {
			   a[j++]=countp-countm;
		   }
	   }
	   Arrays.sort(a);
	   int sum=0;
	   for(int i=0;i<m;i++) {
		   if(i<m/2)sum-=a[i];
		   else sum+=a[i];
	   }
	   System.out.println(sum);
   }
}