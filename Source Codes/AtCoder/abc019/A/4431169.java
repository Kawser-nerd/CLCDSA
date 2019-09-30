import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int a[] = new int[3],i,j;
        for(i=0;i<3;i++)
            a[i] = sc.nextInt();
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(a[i]<a[j]){
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
        System.out.println(a[1]);
    }
}