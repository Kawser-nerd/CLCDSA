import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        
        String zero = "";
        for (int i = 0; i < N; i++) {
        	zero += "0";
        }

        for (int i = 0; i < Math.pow(3, N); i++) {
        	String t = zero + Integer.toString(i,3);
        	
        	t = t.substring(t.length()-N);
        	
        	for (char c: t.toCharArray()) {
        		System.out.print((char)('a'+Character.getNumericValue(c)));
        	}
        	
        	System.out.println();
        }
        
    }
}