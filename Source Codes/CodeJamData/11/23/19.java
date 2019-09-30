import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
public class HouseofKittens {
	public static void main(String[]args) throws IOException
	{
		Scanner in = new Scanner(System.in);
		int inputs=in.nextInt();
		int caseNum = 1;
		FileWriter fstream = new FileWriter("out.txt");
        BufferedWriter out = new BufferedWriter(fstream);
		while(inputs-->0)
		{ 
			int sides = in.nextInt();
			int numWalls = in.nextInt();
			
			
			int[] starts = new int[numWalls];
			int[] ends = new int[numWalls];
			
			int[] canUse = new int[sides+1];
			Arrays.fill(canUse, 1);
			
			Wall[] walls = new Wall[numWalls];
			
			for(int i = 0 ; i < numWalls;i++)
			{
				starts[i] = in.nextInt();
				canUse[starts[i]]++;
			}
			for(int i = 0; i < numWalls; i++)
			{
				ends[i] = in.nextInt();
				canUse[ends[i]]++;
			}
			for(int i = 0; i < numWalls; i++)
			{
				walls[i] = new Wall(starts[i],ends[i]);
			}
			Arrays.sort(walls);
			Room[] rooms = new Room[numWalls+1];
			for(int i = 0; i < numWalls+1;i++)
			{
				rooms[i] = new Room();
			}
			
			for(int i = 0 ; i < numWalls;i++)
			{
				for(int j = walls[i].start;j <= walls[i].end;j++)
				{
					if(canUse[j] != 0)
					{
						rooms[i].vals.add(j);
						canUse[j]--;
					}
				}
			}
			for(int j =1;j <= sides;j++)
			{
				if(canUse[j] != 0)
				{
					rooms[numWalls].vals.add(j);
					canUse[j]--;
				}
			}
			Arrays.sort(rooms);
			int[] colors = new int[sides+1];
			boolean[] isColored = new boolean[rooms.length];
			int smallest = rooms[0].vals.size();
			for(int i = 0 ; i < rooms.length;i++)
			{
				int minColors = Integer.MAX_VALUE;
				int minLocation = -1;
				for(int j = 0; j< rooms.length;j++)
				{
					if(!isColored[j])
					{
						int jColors = 0;
						for(int k = 0; k < rooms[j].vals.size();k++)
						{
							if(colors[rooms[j].vals.get(k)] == 0) jColors++;
						}
						boolean notWork=false;
						for(int w = 1; w <= smallest;w++)
						{
							for(int k = 0; k < rooms[j].vals.size()+1;k++)
							{
								if(rooms[j].vals.size() ==k)
									notWork = true;
								else if(colors[rooms[j].vals.get(k)] == w)
									break;
							}
						}
						if((notWork|| minLocation == -1) && jColors < minColors)
						{
							minColors = jColors;
							minLocation = j;
						}
					}
				}
				ArrayList<Integer> mColors = new ArrayList<Integer>();
				for(int c = 1; c <= smallest;c++)
				{
					boolean hasC = false;
					for(int q = 0; q < rooms[minLocation].vals.size();q++)
					{
						if(colors[rooms[minLocation].vals.get(q)] == c)
						{
							hasC = true;
						}
					}
					if(!hasC) mColors.add(c);
				}
				int on = 0;
				int count = 1;
				for(int q = 0; q < rooms[minLocation].vals.size();q++)
				{
					if(colors[rooms[minLocation].vals.get(q)] == 0)
					{
						if(on == mColors.size())
						{
						}
						else
						{
							colors[rooms[minLocation].vals.get(q)] = mColors.get(on);
							on++;
						}
					}
				}
				isColored[minLocation] = true;
				/*for(int t = 1 ; t<colors.length;t++)
				{
					if(t != colors.length -1)
						System.out.print(colors[t] + " ");
					else
						System.out.print(colors[t]);
				}
				System.out.println();*/
			}
			boolean notWork = false;
			for(int i = 0 ; i < rooms.length;i++)
			{
				for(int j = 1; j <= smallest;j++)
				{
					for(int k = 0; k < rooms[i].vals.size()+1;k++)
					{
						if(rooms[i].vals.size() ==k)
							notWork = true;
						else if(colors[rooms[i].vals.get(k)] == j)
							break;
					}
				}
			}
			/*for(int i = 0; i < rooms.length;i++)
			{
				for(int j = 0; j < rooms[i].vals.size();j++)
				{
					System.out.print(rooms[i].vals.get(j) + " ");
				}
				System.out.println();
			}*/
			 try{
				    // Create file 
				        out.write("Case #" + caseNum + ": " + smallest+"\n");
						for(int i = 1 ; i<colors.length;i++)
						{
							if(colors[i] == 0) colors[i] =1;
							if(i != colors.length -1)
								out.write(colors[i] + " ");
							else
								out.write(colors[i] + "\n");
						}
				    }catch (Exception e){//Catch exception if any
				      System.err.println("Error: " + e.getMessage());
				    }
			if(notWork)
				System.out.println("YIKES!AGASJDFHASJKFHASKDJFHASDJKFHASGJKSDHFASKDJ");
			caseNum++;
		}
		//Close the output stream
	    out.close();
	}
}

class Room implements Comparable<Room>
{
	ArrayList<Integer> vals = new ArrayList<Integer>();
	public Room()
	{
		
	}
	
	public int compareTo(Room a)
	{
		return this.vals.size() - a.vals.size();
	}
}

class Wall implements Comparable<Wall>
{
	int start;
	int end;
	int size;
	public Wall(int a, int b)
	{
		start = a;
		end = b;
		size = b-a+1;
	}
	
	
	public int compareTo(Wall other)
	{
		return this.size - other.size;
	}
	
}
