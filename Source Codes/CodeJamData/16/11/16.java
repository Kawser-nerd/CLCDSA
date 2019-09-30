import java.util.*;
import java.io.*;

public class buf{

	public static void main(String[] args) throws IOException{
	
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		String cass = in.readLine();
		int cas = Integer.parseInt(cass);
		for(int c = 0; c < cas; c++)
		{
			System.out.print("Case #" + (c+1) + ": ");
			char[] bleh = in.readLine().toCharArray();
			int count = bleh.length;
			int countSav = count;
			boolean[] chosen = new boolean[count];
			char[] output = new char[count];
			int outIn = 0;
			while(true){
				char best = 'A'- 1;
				int index = -1;
				for(int j = count-1; j >= 0; j--)
				{
					if(bleh[j] > best)
					{
						//System.out.println("SELECTING " + bleh[j] + " INDEX " + j);
						best = bleh[j];
						index = j;
					}
				}
				//System.out.println("BEST WAS " + best + " INDEX " + index);
				output[outIn++] = best;
				chosen[index] = true;
				count = index;
				if(index == 0) break;
			}
			for(int m = 0; m < outIn; m++)
			{
				System.out.print(output[m]);
			}
			for(int m = 0; m < countSav; m++)
			{
				if(!chosen[m])
					System.out.print(bleh[m]);
			}
			System.out.println();
		}
	}
}