import java.util.Scanner;

class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int Y = sc.nextInt();
        int x = 0;
        int y = 0;
        int z = 0;
      
            for ( int i = 0; i <= N; i++ ){
                for ( int j = 0; j <= N - i; j++ ){
                    int k = N - i - j;
                        int sum = (10000*i) + (5000*j) + (1000*k);
                        if( sum == Y ){
                            if( i + j + k == N ){
                                x = i;
                                y = j;
                                z = k;
                                System.out.println(x + " " + y + " " + z);
                                System.exit(0);
                            }
                        }else{
                            x = -1;
                            y = -1;
                            z = -1;
                        }       
                }    
            }
            System.out.println(x + " " + y + " " + z);
    }
}