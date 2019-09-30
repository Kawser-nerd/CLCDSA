import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int output=Integer.MAX_VALUE;
        for(int i=1;i<=n;i++){
            if(n%i+Math.abs(n/i-i)<output){
                output=n%i+Math.abs(n/i-i);
            }
        }
        System.out.println(output);
    }
}