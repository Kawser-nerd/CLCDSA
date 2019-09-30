import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int[] a = new int[3];
	for(int i = 0; i<3; i++) {
	    a[i] = sc.nextInt();
	}
	Arrays.sort(a);
	long sum = 0;
	for(int i = 0; i<3; i++) {
	    if(i == 2) {
		int n = sc.nextInt();
		while(n>0) {
		    a[i] *= 2;
		    n--;
		}
	    }
	    sum += a[i];
	}
	System.out.println(sum);
    }
}