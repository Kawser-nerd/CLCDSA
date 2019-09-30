import java.util.Scanner;

/**
 *
 * @author cs18097
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int answer = 0;
        int max = 0;
        int allsum =0;
        int[] a = new int[number];
        for(int i= 0; i < number;i++){
            a[i] = sc.nextInt();
            if(a[i] >max){
                max = a[i];
            }
            allsum +=a[i];
        }
        max--;
        for(int j = 0; j < number;j++){
            answer += a[j]%max;
        }
        //System.out.print(answer);
        System.out.print(allsum -number);
    }
    
}