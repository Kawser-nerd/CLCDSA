import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long p = 1l;
        for (int i = 0;i < n; i++){
            p = p*(i+1) % 1000000007;
        }
        System.out.println(p);
    }     
}