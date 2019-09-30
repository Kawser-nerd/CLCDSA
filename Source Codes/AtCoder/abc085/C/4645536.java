import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int Y = Integer.parseInt(sc.next());

        for (int a=0;a<=N;a++) {
        	for (int b=0;b<=N-a;b++) {

        		if(10000*a+5000*b+1000*(N-a-b)==Y) {
        			System.out.println(a+" "+b+" "+(N-a-b));
        			return;
        		}
        	}
        }

        System.out.println("-1 -1 -1");
    }
}