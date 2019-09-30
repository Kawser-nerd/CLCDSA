import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N+1];
        for(int i=1;i<=N;i++) A[i] = sc.nextInt();
        long min = 2;
        long max = 2;
        for(int i=N;i>=1;i--){
            if(min%A[i]!=0) min = min/A[i]*A[i]+A[i];
            max = max/A[i]*A[i]+A[i]-1;
            if(min>max){
                System.out.println(-1);
                System.exit(0);
            }
        }
        System.out.println(Long.toString(min)+" "+Long.toString(max));
    }
}