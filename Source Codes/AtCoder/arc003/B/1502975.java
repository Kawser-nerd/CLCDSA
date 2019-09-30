import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;


public class Main 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		Map<String, String> s_i = new HashMap<String, String>();
		for(int i=0;i<n;i++)
		{
			String tmp=sc.next();
			s_i.put(new StringBuffer(tmp).reverse().toString(),tmp);
		}
		
		//Map.Entry ???????
		List<Entry<String, String>> entries = new ArrayList<Entry<String, String>>(s_i.entrySet());

		//Comparator ? Map.Entry ?????
		Collections.sort(entries, new Comparator<Entry<String, String>>() {
		    //????
		    @Override
		    public int compare(Entry<String, String> o1, Entry<String, String> o2) {
		        return o1.getKey().compareTo(o2.getKey());    //??
//		        return o2.getValue().compareTo(o1.getKey());    //??
		    }
		});
		
		for (Entry<String, String> e : entries) {
		    System.out.println(e.getValue());
		}

	}

}