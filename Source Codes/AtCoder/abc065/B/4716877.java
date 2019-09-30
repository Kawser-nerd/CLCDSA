import java.util.Scanner;
    
    class Main {
     
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int N = sc.nextInt();
            boolean[] n = new boolean[N+1];
            boolean isEnd = false;
            for(int i = 1; i <=N; i++) {
            	n[i] = false;
            }
            int[] a = new int[N+1];
            for(int i = 1; i <= N; i++) {
            	a[i] = sc.nextInt();
            }
            sc.close();
            
            int count = 0;
            int i = 1;
            
            while(true) {
            	if( n[i] == false ) {
            		n[i] = true;
            		count ++;
            		if( a[i] == 2 ) {
            			break;
            		}
            		i = a[i];
     			}else {
     				count = -1;
     				break;
             	}
            }
	         System.out.println(count);
;        }
    }