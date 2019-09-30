import java.util.*;

public class Main{

    public static void main(String[] args){
           
             Scanner sc = new Scanner(System.in);
                   
             int K = sc.nextInt();
            
             char[] s = sc.next().toCharArray();
            
             Koshi koshi = new Koshi(0,0);                                 
             koshi.reLink();
		
	     for(int i = 0; i < K; i++){
			switch (s[i]) {
			case 'L':
				koshi = koshi.left;
				break;
			case 'R':
				koshi = koshi.right;
				break;
			case 'U':
				koshi = koshi.up;
				break;
			case 'D':
				koshi = koshi.down;
				break;
			}
			koshi.reLink();
             }
             
             System.out.println(koshi.x + " "+ koshi.y);
    
    }       
        
    static class Koshi{
    
	static HashMap<String, Koshi> map = new HashMap<String, Koshi>();
	
	Koshi up, down, left, right;        
	int x, y;
	
	Koshi(int x, int y){
		this.x = x;
		this.y = y;
		map.put(hash(), this);
	}
	
	void reLink(){
		if(left == null)   left = get(x-1, y);
		if(right == null) right = get(x+1, y);
		if(up == null)       up = get(x, y+1);
		if(down == null)   down = get(x, y-1);
		
		left.right = right;
		right.left = left;
		up.down = down;
		down.up = up;
	}
	
	String hash(){
		return x + " " + y;
	}
	
	String hash(int x, int y){
		return x + " " + y;
	}
	
	Koshi get(int x, int y){
		if(map.containsKey(hash(x, y))){
			return map.get(hash(x, y));
		}
		return new Koshi(x, y);
        }      
        
    }    
    
}