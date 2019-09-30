import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i = 2; i < (int)(Math.sqrt(n) + 1); i++){
            if(n % i == 0){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}