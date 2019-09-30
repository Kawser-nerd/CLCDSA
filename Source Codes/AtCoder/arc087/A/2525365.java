import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        HashMap<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i < n; i++)
        {
            int a = sc.nextInt();
            m.put(a, m.containsKey(a) ? m.get(a) + 1 : 1);
        }
        
        int s = 0;
        
        for(Entry<Integer, Integer> e : m.entrySet())
        {
        	int k = e.getKey();
        	int v = e.getValue();
        	if(k <= v)
        	{
        		s += v - k;
        	}
        	else
        	{
        		s += v;
        	}
        }
        
        System.out.println(s);
  	}
}