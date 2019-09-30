import java.util.*;

public class Main {    
    
    public static void main(String[] args){
       
        Scanner sc = new Scanner(System.in);
        
        int L = sc.nextInt();
        int R = sc.nextInt();
        
        int a[] = new int[L];
        int b[] = new int[R];
        
        HashMap<Integer , Integer> lmap = new HashMap<>();
        HashMap<Integer , Integer> rmap = new HashMap<>();
        
        
        for(int i = 0;i < L;i++){
            a[i] = sc.nextInt();
        }
                
        for(int i = 0;i < R;i++){
            b[i] = sc.nextInt();
        }
                
        Arrays.sort(a);
        Arrays.sort(b);
                        
        for(int i = 0;i < L;i++){
            if(lmap.containsKey(a[i])){
               int count = lmap.get(a[i]);
               count++;
               lmap.put(a[i],count);
            }else{
               lmap.put(a[i],1);
            } 
        }
            
        for(int i = 0;i < R;i++){
            if(rmap.containsKey(b[i])){
               int count = rmap.get(b[i]);
               count++; 
               rmap.put(b[i],count);
            }else{
               rmap.put(b[i],1); 
            }            
        }   
        
        List<Integer> list = new ArrayList<>();
        
        for(int num:a){
            if(!list.contains(num)){
                list.add(num);    
            }            
        }
        
        int count = 0;
        
        for(int i = 0;i < list.size();i++){
            int key = list.get(i);
            
            int lcount = lmap.get(key);
            
            int rcount = 0; 
            
            if(rmap.containsKey(key)){
               rcount = rmap.get(key);
            }
                                                
            if(lcount == 0 || rcount == 0)
               continue;
            
            int min = Math.min(lcount,rcount);
            
            count += min;            
        }

        System.out.println(count);
                
    }      
}