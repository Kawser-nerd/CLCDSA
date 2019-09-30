import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int[] stones=new int[n+1];
        int q=sc.nextInt();
        for(int i=0;i<q;i++){
            stones[sc.nextInt()-1]++;
            stones[sc.nextInt()]--;
        }
        for(int i=1;i<n;i++){
            stones[i]+=stones[i-1];
        }
        for(int i=0;i<n;i++){
            System.out.print(stones[i]%2);
        }
        System.out.println();
    } 
}