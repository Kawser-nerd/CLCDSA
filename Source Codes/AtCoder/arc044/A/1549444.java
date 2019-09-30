import java.util.*;
 
class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
        
        if(n==1){
            System.out.println("Not Prime");
            return;
        }
        if(n==2 || n==3 || n==5){
            System.out.println("Prime");
            return;
        }
        if(n%2==0 || n%3==0 || n%5==0){
            System.out.println("Not Prime");
        } else {
            System.out.println("Prime");
        }
    }
}