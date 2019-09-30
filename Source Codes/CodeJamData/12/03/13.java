import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;


public class codejamp3 {
	public static char[] map;
	public static void main(String[] args) throws IOException{
		readFile();
	}

	public static String getResult(String input){
		int resultInt = 0;
		Set<Integer> exist = new HashSet<Integer>();
		String[] splitResult = input.split(" ");
		int numberA = Integer.parseInt(splitResult[0]);
		int numberB = Integer.parseInt(splitResult[1]);
		for(int i = numberA; i < numberB; i++){
			int current = i;
			exist.clear();
			int length1 = String.valueOf(current).length();
			int j = 10;
			while(j<=current){
				int remain = current%j;
				int length2 = String.valueOf(j).length(); 
				double b = Math.pow(10, length2-1);
				double a = Math.pow(10,length1);
				int currentResult = (int)(remain*a/b+current/j);
				if(current == 2022){
					System.out.println(remain+":"+(length2-1)+":"+currentResult);
				}
				if(currentResult <= numberB && currentResult > current){
					if(!exist.contains(currentResult)){
						exist.add(currentResult);
						resultInt++;
					}
				}
				j = j*10;
			}
		}
		return ""+resultInt;
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
          	  	out.write('\n' + "Case #" + i + ": " + getResult(line));
          	  	line = bufRead.readLine();
            }             
            bufRead.close();
            out.close();
	}
}
