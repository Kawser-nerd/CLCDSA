import java.util.*;

public class Main{
            
	public static void main(String[] args) {
		
           Scanner sc = new Scanner(System.in);                                                            
           
           String first = sc.next();
			String last = sc.next();
			
			int n = sc.nextInt();
			String[] tango = new String[n+2];
			for(int i = 1; i < n+1; i++){
				tango[i] = sc.next();
			}
			tango[0] = first;
			tango[n+1] = last;
			
			ArrayList<Integer> list = new ArrayList<Integer>();
			int[] check = new int[n+2];
			Arrays.fill(check, -2);
			
			list.add(0);
			check[0] = -1;
			int t = -1;
			while(list.size() != 0){
				int word = list.get(0);
				list.remove(0);
				if(tango[word].equals(last)){
					t = word;
					break;
				}
				for(int i = 1; i < n+2; i++){
					if(check(tango[word], tango[i]) && check[i] == -2) {
						list.add(i);
						check[i] = word; 
					}
				}
			}
			
			if(first.equals(last)) {
				System.out.println(0);
				System.out.println(first);
				System.out.println(last);
			}
			else if(t == -1) System.out.println(-1);
			
			else{
				ArrayList<String> ans = new ArrayList<String>();
				boolean tt = true;
				while(tt){
					ans.add(0, tango[t]);
					t = check[t];
					if(t == -1) tt = false;
				}
				
				System.out.println(ans.size() - 2);
				for(int i = 0; i < ans.size(); i++){
					System.out.println(ans.get(i));
				}
			}
	}
        
        static public boolean check(String a1,String a2){
          int t = 0;
          
          for(int i = 0;i < a1.length();i++){
              if(a1.charAt(i) != a2.charAt(i))t++;    
          }
          
          if(t == 1) return true; 
          else return false;
          
        }        
        
}