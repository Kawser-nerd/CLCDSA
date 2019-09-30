import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {           
    public static void main(String[] args) {		        
      Scanner sc = new Scanner(System.in);                                       
         
      String alphabet[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};         
    
    HashMap<String,Integer> map = new HashMap<>();                            

    int N = sc.nextInt();
    
    String target[] = new String[N];
    
    for(int i = 0;i < N;i++){
        target[i] = sc.next();
    }
    
    
    for(int j = 0; j < 26;j++){          
       int min = Integer.MAX_VALUE;
       for(int i = 0;i < N;i++){                 
          String item   =  alphabet[j];         
          Pattern  p = Pattern.compile(item);
          Matcher m = p.matcher(target[i]);         

          int count = 0;
          int s = 0;                  
          
          while (m.find(s)) {
           count++;
           s = m.end();
          }         
          
          min = Math.min(count,min);
          
          map.put(item,min);                                      
       }            
    }        
    
        
    StringBuilder ans = new StringBuilder();    
    
    for (String key : map.keySet()){        
        for(int i = 0;i < map.get(key);i++){
          ans.append(key);
        }          
    }  

    System.out.println(ans.toString());

    
  }
}