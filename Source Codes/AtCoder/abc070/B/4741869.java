import java.util.Scanner;
     
    class Main{
    	public static void main(String arg[]) {
    		Scanner sc = new Scanner(System.in);
    		int A = sc.nextInt();
    		int B = sc.nextInt();
    		int C = sc.nextInt();
    		int D = sc.nextInt();
    		sc.close();
    		int[] Alice = new int[102];
    		int[] Bob = new int[102];
    		int count = 0;
    		
    		for(int i = 0; i <= 100; i++ ) {
    			if( i < A || i >= B) {
    				Alice[i] = 999;
    			}else {
    				Alice[i]= i; 
    			}
    		}
    		
    		for(int i = 0; i <= 100; i++ ) {
    			if( i < C || i >= D) {
    				Bob[i] = 998;
    			}else {
    				Bob[i]= i; 
    			} 
    		}
    		
    		for(int i = 0; i <= 100; i++) {
    			if(Alice[i] == Bob[i]) {
    				count++;
    			}
    		}
    		System.out.println(count);
    	}
    }