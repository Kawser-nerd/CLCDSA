import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
     
class Main{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();
        String A = sc.nextLine();
        Integer[] a = new Integer[N]; 

        sc.close();

        for(int i = 0; i < N; i++) {
            String[] s = A.split(" ");
            a[i] = Integer.parseInt(s[i]);
        }
        
        System.out.println(calc(a));    
    }
    
    public static int calc(Integer[] a) {
        int Alice = 0;
        int Bob = 0;
        
        Arrays.sort(a, Comparator.reverseOrder());

        for(int i = 0; i < a.length; i++){
            if(i % 2 == 0){
                Alice += a[i];
            }else{
                Bob += a[i];
            }
        }
		return Alice - Bob;
    }
}