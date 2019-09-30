import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class codejam {
	public static char[] map;
	public static void main(String[] args) throws IOException{
		map = new char[1000];
		getInfo("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
		getInfo("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities");
		getInfo("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up");
		
		readFile();
	}
	public static void getInfo(String codeString, String matching){
		for(int i = 0; i< codeString.length(); i++){
			char a = codeString.charAt(i);
			char b = matching.charAt(i);
			map[a] = b;
		}
	}
	public static String getResult(String input){
		String result = new String("");
		for(int i = 0; i< input.length(); i++){
			char a = input.charAt(i);
			char b = map[a];
			result = result + b;
		}
		return result;
	}
	public static void readFile() throws IOException{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
            FileReader input = new FileReader("in.txt");
            BufferedReader bufRead = new BufferedReader(input);	
            String line = bufRead.readLine();
            String current = getResult(line);
            int i = 1;
            out.write("Case #" + i + ": " + current);
            line = bufRead.readLine();
            while (line != null){
            	i++;
          	  	System.out.println("Case #" + i + ": " + getResult(line));     	  	
          	  	out.write('\n' + "Case #" + i + ": " + getResult(line));
          	  	line = bufRead.readLine();
            }             
            bufRead.close();
            out.close();
	}
}
