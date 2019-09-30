import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class codejamp2 {
	public static char[] map;
	public static void main(String[] args) throws IOException{
		readFile();
	}

	public static String getResult(String input){
		int resultInt = 0;
		String[] splitResult = input.split(" ");
		int dancerCount = Integer.parseInt(splitResult[0]);
		int suprising = Integer.parseInt(splitResult[1]);
		int max = Integer.parseInt(splitResult[2]);
		for(int i = 3; i < dancerCount + 3; i++){
			int current = Integer.parseInt(splitResult[i]);
			int ave = current/3;
			int remain = current - 3*ave;
			int currentmax = ave + remain;
			if(remain == 0 && (max - currentmax == 1) && current!= 0){
				if(suprising > 0){
					suprising--;
					resultInt++;
				}
			}
			if(currentmax >= max){
				if(remain<=1){
					resultInt++;
				}
				else if(remain == 2){
					if(max - ave<=1){
						resultInt++;
					}
					else if(suprising > 0){
						suprising--;
						resultInt++;
					}
				}
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
          	  	System.out.println("Case #" + i + ": " + getResult(line));     	  	
          	  	out.write('\n' + "Case #" + i + ": " + getResult(line));
          	  	line = bufRead.readLine();
            }             
            bufRead.close();
            out.close();
	}
}
