import java.util.*;
public class Main {
public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
	int L = sc.nextInt();
	int[] a = new int[L];
	int[] b = new int[L];
	for(int i=0;i<L;i++) {
	b[i]=sc.nextInt();
	}
	int xor = b[0] ^ b[1];
    for (int i=2;i<L-1;i++){
        xor = xor ^ b[i];
    }
	if(L==2&&b[0]!=b[1]) {
		System.out.println(-1);
	}else if(L != 2 && b[L-1] != xor){
		System.out.println(-1);
	}else {
		a[0]=0;
		System.out.println(a[0]);
		for(int i=1;i<L;i++) {
			a[i] = a[i-1] ^ b[i-1];
			System.out.println(a[i]);
		}
	}
}
}