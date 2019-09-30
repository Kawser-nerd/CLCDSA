import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        boolean[] prime = new boolean[55_556];
        Arrays.fill(prime, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 0; i < prime.length; i++) {
        	if (prime[i]) {
        		for (int j = i+i; j < prime.length; j += i) {
        			prime[j] = false;
        		}
        	}
        }
        
        List<Integer> list = new ArrayList<>();
        for (int i = 6; i < prime.length; i++) {
        	if (prime[i] && i % 5 == 1) {
        		list.add(i);
        	}
        	
        	if (N <= list.size()) {
        		break;
        	}
        }
        
        list.stream().forEach(System.out::println);
    }
}