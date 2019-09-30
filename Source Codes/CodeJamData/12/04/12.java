import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;


public class codejamp4 {
	public static char[] map;
	public static void main(String[] args) throws IOException{
		readFile();
	}

	public static int getTriple(int c, int a){
		return (int)Math.floor(Math.sqrt(Math.pow(c, 2)-Math.pow(a, 2)));
	}
	public static int calcGCF(int a, int b) {
		int s;
		if (a > b)
			s = b;
		else
			s = a;
		for (int i = s; i > 0; i--) {
			if ((a%i == 0) && (b%i == 0))
				return i;
		}
		return -1;
	}
	public static int mapSearch(char[][] map, int height, int width, int distance, int horizontal, int vertical,
			int posX, int posY,int dx,int dy){
		int x = 0;
		int y = 0;
		while(Math.pow(x, 2)+Math.pow(y, 2)<Math.pow(distance, 2)){
			if((x+0.5)*vertical<(y+0.5)*horizontal){
	            posX+=dx;
	            x+=1;
	            if(map[posX][posY]=='#'){
	                dx=-dx;
	                posX+=dx;
	            }
			}
			else if((x+0.5)*vertical>(y+0.5)*horizontal){
	            posY+=dy;
	            y+=1;
	            if(map[posX][posY]=='#'){
	                dy=-dy;
	                posY+=dy;
	            }
			}
	        else{
	            x+=1;
	            y+=1;
	            posX+=dx;
	            posY+=dy;
	            if(map[posX][posY]=='#'){
	                if(map[posX-dx][posY]=='#' && map[posX][posY-dy]=='#'){
	                    dx=-dx;
	                    dy=-dy;
	                    posX+=dx;
	                    posY+=dy;
	                }
	                else if(map[posX-dx][posY]=='#'){
	                    dy=-dy;
	                    posY+=dy;
	                }
	                else if(map[posX][posY-dy]=='#'){
	                    dx=-dx;
	                    posX+=dx;
	                }
	                else{ 
	                	return 0;
	                }
	            }
	        }
	        if(map[posX][posY]=='X' && y*horizontal==x*vertical && 
	        		Math.pow(x,2)+Math.pow(y,2)<=Math.pow(distance,2)){
	            return 1;
	        }
		}
		return 0;
	}
	public static int lineSearch(char[][] map, int height, int width, int distance,
			int posx, int posy, int dx, int dy){
		if(posx<0 || posy<0) 
			return 0;
	    for(int i=1; i<=distance; i++){
	        posx+=dx;
	        posy+=dy;
	        if(map[posx][posy]=='#'){
	            dx=-dx;
	            dy=-dy;
	            posx+=dx;
	            posy+=dy;
	        }
	        if(map[posx][posy]=='X'){
	            return 1;
	        }
	    }
	    return 0;
	}
	public static int getResult(char[][] map, int height, int width, int distance){
		int count=0;
	    int posx=-1;
	    int posy=-1;
	    for(int i = 0;i<height;i++){
	        if(posx!=-1) 
	        	break;
	        for(int j = 0; j<width; j++){
	            if(map[i][j]=='X'){ 
	                posx=i;
	                posy=j;
	                break;
	            }
	        }
	    }
	    ArrayList<ShadowPoint> exist=new ArrayList<ShadowPoint>();
	    for(int horizontal = 1; horizontal<distance;horizontal++){
	        for(int vertical = 1; vertical<=getTriple(distance,horizontal);vertical++){
	            int g=calcGCF(horizontal, vertical);
	            ShadowPoint current = new ShadowPoint(horizontal/g,vertical/g);
	            if(exist.contains(current))
	            	continue;
	            exist.add(current);
	            count+=mapSearch(map, height, width, distance, horizontal, vertical, posx, posy, 1, 1);
	            count+=mapSearch(map, height, width, distance, horizontal, vertical, posx, posy, 1, -1);
	            count+=mapSearch(map, height, width, distance, horizontal, vertical, posx, posy, -1, 1);
	            count+=mapSearch(map, height, width, distance, horizontal, vertical, posx, posy, -1, -1);
	        }
	    }
	    count+=lineSearch(map, height, width, distance, posx, posy, 1, 0);
	    count+=lineSearch(map, height, width, distance, posx, posy, 0, 1);
	    count+=lineSearch(map, height, width, distance, posx, posy, -1, 0);
	    count+=lineSearch(map, height, width, distance, posx, posy, 0, -1);
	    return count;
	}
	
	public static void readFile() throws IOException{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
            FileReader input = new FileReader("in.txt");
            BufferedReader bufRead = new BufferedReader(input);	
            String line = bufRead.readLine();
            int lineCount = 1;
            while (line != null){
            	String[] splitResult = line.split(" ");
            	int height = Integer.parseInt(splitResult[0]);
            	int width = Integer.parseInt(splitResult[1]);
            	int distance = Integer.parseInt(splitResult[2]);
            	char[][] map = new char[height][width];
            	for(int i=0;i<height;i++){
            		String currentLine = bufRead.readLine();
            		for(int j=0; j<width;j++){
            			map[i][j] = currentLine.charAt(j);
            		}
            	}
            	out.write("Case #" + lineCount + ": " + getResult(map,height,width,distance));
          	  	line = bufRead.readLine();
          	  	if(line!=null)
          	  		out.write('\n');
          	  	lineCount++;
            }             
            bufRead.close();
            out.close();
	}
}
