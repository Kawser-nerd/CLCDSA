import java.util.*;


public class Main{    
    
    public static void main(String[] args){            
       
        Scanner sc = new Scanner(System.in);        
                      
        int N = sc.nextInt();
        
        char a[][] = new char[N][];
        
        for(int i = 0 ;i < N;i++){
             a[i] = sc.next().toCharArray();
        }
        
        long count = 0;
        char[] prev = new char[9];
        
        for(int i = 0 ;i < N;i++){
            for(int j = 0;j < 9;j++){
                if(a[i][j] == 'x'){
                   count++;
                }else if(a[i][j] == 'o' && prev[j] != 'o'){
                   count++;
                }
                prev[j] = a[i][j];
            }
        }
        
        System.out.print(count);        
                        
    }                                       
}