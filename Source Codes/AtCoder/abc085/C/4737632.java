import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int Y = scan.nextInt();
        int count = 0;
        int x = 0;
        int y = 0;

        for(x = 0; x <= N; x++){
            for(y = 0; y <= N-x; y++){
                if((Y == 10000*x + 5000 * y + 1000 * (N-x-y)) && (count == 0)){
                    System.out.println(x + " " + y + " " + (N - x- y));
                    count++;
                    break;
                }
            }
        }
        
        if(count == 0){            
            System.out.println("-1 -1 -1");
        }
    }
}