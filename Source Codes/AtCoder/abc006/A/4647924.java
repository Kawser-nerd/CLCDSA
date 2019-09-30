import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	int i =	sc.nextInt();
	if(i%3==0) {
            System.out.println("YES");
            return;
        }
	while(i>0) {
            if(i%3==0) {
		System.out.println("YES");
                return;
            }
            i = i/10;
	}
        System.out.println("NO");
    }
}