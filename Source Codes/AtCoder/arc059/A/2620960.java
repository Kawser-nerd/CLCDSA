import java.util.Arrays;
import java.util.Scanner;




public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {
    	Scanner sc=new Scanner(System.in);

    	int N=sc.nextInt();

    	int[] a=new int[N];

    	for(int i=0;i<N;i++) {
    		a[i]=sc.nextInt();
    	}

    	Arrays.sort(a);

    	int min=999999999;

    	for(int i=a[0];i<=a[N-1];i++) {
    		int cost=calc(i,a);

    		if(min>cost) {
    			min=cost;
    		}
    	}

    	System.out.println(min);

    }

    public static int calc(int m,int[] a) {

    	int result=0;
    	for(int i=0;i<a.length;i++) {
    		result+=Math.abs((a[i]-m)*(a[i]-m));
    	}

    	return result;

    }


}