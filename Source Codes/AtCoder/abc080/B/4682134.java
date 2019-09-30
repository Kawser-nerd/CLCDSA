import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N =	sc.nextInt();
        int x =	N;
	int sum = 0;

	while(x>0) {
            sum	+= x%10;
            x /= 10;
        }
	if(N%sum == 0) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}