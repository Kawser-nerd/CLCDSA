import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String tmpS;
        int tmpP;
        int population=0;
        String largestTown=null;
        int largest=0;
        for(int i=0;i<n;i++){
            tmpS=sc.next();
            tmpP=sc.nextInt();
            population+=tmpP;
            if(largest<tmpP){
                largest=tmpP;
                largestTown=tmpS;
            }
        }
        System.out.println(population<largest*2?largestTown:"atcoder");
    }
}