import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	for(int i = 0; i<1000; i++) {
	    if(N==i*i*i*i) {
		System.out.println(i);
		return;
	    }
	}
    }
}