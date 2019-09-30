import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a   = scan.nextInt();
        int b[] = new int[a];
        int stop = 0;
        int count = 0;

        for (int i = 0; i < a; i++) {
            b[i] = scan.nextInt();
        }

        do{

            for (int x = 0; x < a; x++) {
                
                if(b[x] % 2 == 0 ){
                    b[x] = b[x]/2 ;
                }

                else{
                    stop = 1;
                }
            }

            if(stop == 0){
                count++;
            }
            
        }while( stop == 0 );

        System.out.println(count);
    }
}