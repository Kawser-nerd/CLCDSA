import java.util.Scanner;
    
    class Main {
     
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int N = sc.nextInt();
            int K = sc.nextInt();
            sc.close();
            int comb = 1;
            for(int i = 1; i <= N - 1; i++ ) {
            	comb *= (K-1);
            }
            System.out.println(comb*K);
        }
    }