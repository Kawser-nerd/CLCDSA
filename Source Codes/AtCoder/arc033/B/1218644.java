import java.util.*;

public class Main {
	public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                
                int NA = sc.nextInt();
                int NB = sc.nextInt();                
                
                int a[] = new int[NA];
                int b[] = new int[NB];
                
                for(int i = 0 ;i < NA;i++){
                    a[i] = sc.nextInt();
                }
                
                for(int i = 0 ;i < NB;i++){
                    b[i] = sc.nextInt();
                }
                
                HashSet<Integer> set= new HashSet<>();
                
                for(int i = 0 ;i < NA;i++){
                    set.add(a[i]);
                }
                
                int cnt = 0;                                
                
                for(int i = 0 ;i < NB;i++){
                    if(set.contains(b[i])){
                        cnt++;
                    }else{
                        set.add(b[i]);
                    }                                        
                }
                                
                System.out.println((double)cnt/set.size());                
               
                }
}