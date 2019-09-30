import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if(a==b){
            System.out.println("Draw");
        }else if(a==1){
            System.out.println("Alice");
        }else if(b==1){
            System.out.println("Bob");
        }else if(a>b){
            System.out.println("Alice");
        }else{
            System.out.println("Bob");
        }
    }
}