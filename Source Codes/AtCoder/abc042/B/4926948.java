import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextInt();
        String[] inputs=new String[n];
        for(int i=0;i<n;i++){
            inputs[i]=sc.next();
        }
        String tmp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(inputs[j].compareTo(inputs[j+1])>0){
                    tmp=inputs[j];
                    inputs[j]=inputs[j+1];
                    inputs[j+1]=tmp;
                }
            }
        }
        for(String a:inputs){
            System.out.print(a);
        }
        System.out.println();
    }
    
 
}