import java.util.*;
import java.io.*;
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String strOri = "our language is impossible to understand"+
"there are twenty six factorial possibilities"+
"so it is okay if you want to just give up";
		String strEnc = "ejp mysljylc kd kxveddknmc re jsicpdrysi"+
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+
"de kr kd eoya kw aej tysr re ujdr lkgc jv";
		Map<Character, Character> map = new TreeMap<Character, Character>();
		strOri = strOri.replace(" ","");
		strEnc = strEnc.replace(" ", "");
		for(int i=0; i<strOri.length(); i++)
			map.put(strOri.charAt(i), strEnc.charAt(i));
		//'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'. This means that "a zoo" will become "y qee". 
		map.put('z', 'q');
		map.put('o', 'e');
		map.put('a', 'y');
		
		map.put(notIn(map.keySet()), notIn(map.values()));
//		System.out.println(map.size());
//		for(Character key:map.keySet())
//			System.out.println(key+" "+map.get(key));
		FileInputStream fis = new FileInputStream(new File("in.txt"));
		FileOutputStream fos = new FileOutputStream(new File("out.txt"));
		Scanner sc = new Scanner(fis);
		PrintWriter out = new PrintWriter(fos);
		int cases = sc.nextInt();
		sc.nextLine();
		Map<Character, Character> map2 = new TreeMap<Character, Character>();
		for(Character c:map.keySet())
			map2.put(map.get(c), c);
		for(int cs = 1; cs<=cases; cs++)
		{
			String line = sc.nextLine();
			String output ="";
			for(Character c:line.toCharArray())
			{
				if(c == ' ')
					output+=c;
				else
					output+=map2.get(c);
			}
			out.println("Case #"+cs+": "+output);
		}
		out.close();
		fis.close();
	}

	private static Character notIn(Collection<Character> values) {
		for(char i = 'a'; i<='z'; i++)
			if(!values.contains(i))
				return i;
		return 0;
	}

}
