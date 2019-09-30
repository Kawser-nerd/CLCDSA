import java.util.Scanner;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int ans = scan.nextInt();
        int tmp;

        for(int i = 0; i < N - 1; i++){
            tmp = scan.nextInt();
            if(ans > tmp){
                ans = tmp;
            }
        }
        System.out.println(ans);
    }
}