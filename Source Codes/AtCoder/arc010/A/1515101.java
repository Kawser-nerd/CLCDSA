import java.util.Scanner;

class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), 
            a = in.nextInt(), b = in.nextInt();
        
        for(int i = 0; i < m; i++){
            int c = in.nextInt();
            if(n <= a){
                n += b;
            }
            if(n < c){
                System.out.println(i + 1);
                return;
            }
            n -= c;
        }
        System.out.println("complete");
    }
}