import java.util.Scanner;
    
    class Main {
     
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int A = sc.nextInt();
            int B = sc.nextInt();
            int C = sc.nextInt();
            int D = sc.nextInt();
            sc.close();
           if( A <= C && B <= D && C <= B) {
        	   System.out.println( B - C );
           }else if( A <= C && D <= B && A <= C ){
        	   System.out.println( D - C );
           }else if( C <= A && D <= B && A <= D) {
        	   System.out.println( D - A );
           }else if( C <= A && B <= D && B <= D ) {
        	   System.out.println( B - A );
           }
           else {
        	   System.out.println(0);
           }
        }
    }