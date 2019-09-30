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
    		
    		int ans = Math.min(B, D) - Math.max(A, C);
          	if(ans >= 0){
            	System.out.println( ans );
            }else{
              	System.out.println( 0 );
            }
    	}
    }