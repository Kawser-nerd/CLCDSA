import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner reader= new Scanner(System.in);
        int num=reader.nextInt();
        int[] A= new int[100001];
        for(int i=0; i<num; i++){
            int x= reader.nextInt();
            if (x==0){
                A[0]++;
                A[1]++;
            }
            else
            {if(x==9999){
                A[9999]++;
                A[9998]++;
            }
            else{
                A[x]++;
                A[x+1]++;
                A[x-1]++;
            }}}
            int max=A[0];
            for (int j=1; j<100001; j++){
                if (A[j]>max)
                    max=A[j];
            }
            System.out.println(max);
        }

    }