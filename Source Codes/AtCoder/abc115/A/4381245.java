import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        
        switch(D){
            case 25:
                System.out.println("Christmas");
                break;
            case 24:
                System.out.println("Christmas Eve");
                break;
            case 23:
                System.out.println("Christmas Eve Eve");
                break;
            case 22:
                System.out.println("Christmas Eve Eve Eve");
                break;
        }
    }
}