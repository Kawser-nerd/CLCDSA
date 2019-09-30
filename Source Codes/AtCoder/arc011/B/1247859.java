import java.util.*;

public class Main {   
    
	public static void main(String[] args) {
              Scanner sc = new Scanner(System.in);                                                                                     
         
              HashMap<Character,Character> map = new HashMap<Character,Character>();   
              map.put('b','1');
              map.put('c','1');
              map.put('d','2');
              map.put('w','2');
              map.put('t','3');
              map.put('j','3');
              map.put('f','4');
              map.put('q','4');
              map.put('l','5');
              map.put('v','5');
              map.put('s','6');
              map.put('x','6');
              map.put('p','7');
              map.put('m','7');
              map.put('h','8');
              map.put('k','8');
              map.put('n','9');
              map.put('g','9');
              map.put('z','0');
              map.put('r','0');
              
              int N = sc.nextInt();
              
              List<String> result = new ArrayList<String>();

              char w[][] = new char[N][];
              for(int i = 0 ;i < N;i++){
                   w[i] = sc.next().toLowerCase().toCharArray();
              }              
              
              for(int i = 0 ;i< w.length;i++){                                                                      
                   StringBuilder sb = new StringBuilder();
                   for(char c: w[i]){
                       Character num = map.get(c);
                       if(num != null){
                            sb.append(num);
                       }
                   }
                   if(sb.length() > 0){
                          result.add(sb.toString());
                   }
              }
                            
              System.out.println(String.join(" ",result));
                            
        }        
}