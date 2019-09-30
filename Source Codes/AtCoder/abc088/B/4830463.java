import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=Integer.parseInt(sc.next());
        Integer A[]=new Integer[n];
        for (int i=0;i<n;i++){
            A[i]=Integer.parseInt(sc.next());
        }
        Arrays.sort(A,Comparator.reverseOrder());
        int Alice=0;
        int Bob  =0;
        for (int i=0;i<n;i+=2){
            Alice+=A[i];
        }
        for (int i=1;i<n;i+=2){
            Bob+=A[i];
        }
        System.out.println(Alice-Bob);
    }
}