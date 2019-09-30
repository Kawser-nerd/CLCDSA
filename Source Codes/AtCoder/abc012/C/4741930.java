import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	long sum = 0;
	for(int i = 1; i<=9; i++) {
	    for(int j = 1; j<=9; j++) {
		sum += i*j;
	    }
	}
	long N = sc.nextLong();
	long diff = sum-N;
	for(int i = 1; i<=9; i++) {
	    for(int j = 1; j<=9; j++) {
		if(diff == i*j) {
		    System.out.println(i + " x " + j);
		}
            }
        }
    }
}