import java.io.*;
import java.util.*;

public class Magicka
{
	
	public static void main(String[] args)
	{
		try
		{
			// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
			int T = Integer.parseInt(br.readLine());
			// PrintWriter pw = new PrintWriter(System.out);
			PrintWriter pw = new PrintWriter(new FileWriter("output"));

			int[] basemap = new int[256];
			basemap['Q'] = 0;
			basemap['W'] = 1;
			basemap['E'] = 2;
			basemap['R'] = 3;
			basemap['A'] = 4;
			basemap['S'] = 5;
			basemap['D'] = 6;
			basemap['F'] = 7;
			
			for (int I = 1; I <= T; I++)
			{
				StringTokenizer st = new StringTokenizer(br.readLine(), " ", false);
				int C = Integer.parseInt(st.nextToken());
				char[][] combo = new char[8][8];
				for (int i = 0; i < C; i++)
				{
					char[] arr = st.nextToken().toCharArray();
					combo[basemap[arr[0]]][basemap[arr[1]]] = arr[2];
					combo[basemap[arr[1]]][basemap[arr[0]]] = arr[2];
				}
				boolean[][] opposed = new boolean[8][8];
				int D = Integer.parseInt(st.nextToken());
				for (int i = 0; i < D; i++)
				{
					char[] arr = st.nextToken().toCharArray();
					opposed[basemap[arr[0]]][basemap[arr[1]]] = true;
					opposed[basemap[arr[1]]][basemap[arr[0]]] = true;
				}
				
				Stack<Character> stack = new Stack<Character>();
				st.nextToken(); // don't need it
				char[] process = st.nextToken().toCharArray();

				int recID = -1;
				boolean[] killSwitch = new boolean[8];
				for (char ch : process)
				{
					int id = basemap[ch];
					if (recID != -1)
					{
						char combine = combo[id][recID];
						if (combine != 0)
						{
							stack.pop();
							stack.push(new Character(combine));
							recID = -1;
							continue;
						}
						else for (int k = 0; k < 8; k++) if (opposed[recID][k])
							killSwitch[k] = true;
					}
					if (killSwitch[id])
					{
						stack.clear();
						for (int k = 0; k < 8; k++) killSwitch[k] = false;
						recID = -1;
					}
					else
					{
						recID = id;
						stack.push(new Character(ch));
					}
				}
				
				pw.println("Case #"+I+": "+(new ArrayList<Character>(stack)));
			}
			
			br.close();
			pw.flush(); pw.close();
		}
		catch (IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
}