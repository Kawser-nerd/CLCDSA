import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;


public class AllYourBase {
	public static void main(String[] args){
	try {
		BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("x.txt"));

		Scanner scan = new Scanner(in);

		int T = scan.nextInt();
		scan.nextLine();
		for(int ii=0; ii<T; ii++)
		{
			String str = scan.nextLine();
			HashMap<Character, Integer> hm = new HashMap<Character, Integer>();
			
			hm.put(str.charAt(0), 1);
			int count = 1;
			while(count<str.length())
			{
				char c = str.charAt(count);
				if(!hm.containsKey(c))
				{
					hm.put(c, 0);
					break;
				}
				count++;
			}
			count++;
			int val = 2;
			while(count<str.length())
			{
				char c = str.charAt(count);
				if(!hm.containsKey(c))
				{
					hm.put(c, val++);
				}
				count++;
			}
			
			String tgt = "";
			for(int i=0; i<str.length(); i++)
			{
				tgt+=hm.get(str.charAt(i));
			}
			BigInteger x = new BigInteger(tgt, val);
			out.write("Case #"+(ii+1)+": "+x.toString()+"\n");
		}



		in.close();
		out.close();
	} catch (IOException e) {
		e.printStackTrace();
	}
}
}



