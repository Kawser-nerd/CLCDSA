import java.util.Scanner;
     
    class Main{
    	public static void main(String arg[]) {
    		Scanner sc = new Scanner(System.in);
    		int N = sc.nextInt();
    		int[] a = new int[N+1];
    		
;    		for(int i = 1; i <= N; i++) {
				a[i] = sc.nextInt();
			}
    		sc.close();
    		int count = 0;
    		
    		int i = 1;
    		boolean[] isON = new boolean[N+1];
    		while(true) {
    			if(a[i] == 2 ) {
    				count++;
    				break;
    			}
    			if(isON[i] == true) {
    				count = -1;
    				break;
    			}
    			count++;
    			isON[i] = true;
    			i = a[i];
    		}
    		System.out.println(count);
    	}
    }