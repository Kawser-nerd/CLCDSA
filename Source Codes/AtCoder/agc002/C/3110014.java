import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int L = sc.nextInt();
        int[] a = new int[N+1];
        int[] knot = new int[N];
        for(int i=1;i<=N;i++) a[i]=sc.nextInt();
        for(int i=1;i<=N-1;i++){
            knot[i]=a[i]+a[i+1];
        }
        int max=0;
        int pos=-1;
        for(int i=1;i<N;i++){
            if(knot[i]>max){
                max = knot[i];
                pos=i;
            }
        }
        if(max<L){
            System.out.println("Impossible");
        }
        else{
            System.out.println("Possible");
            for(int i=1;i<pos;i++) System.out.println(i);
            for(int i=N-1;i>=pos+1;i--) System.out.println(i);
            System.out.println(pos);
        }
    }
}