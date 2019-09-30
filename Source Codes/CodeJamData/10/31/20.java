import java.io.*;
import java.util.*;

public class Wires
{
	
	public static void main(String[] args)
	{
		try
		{
			BufferedReader BR = new BufferedReader(new FileReader("A-small.in"));
			PrintWriter PW = new PrintWriter(new FileWriter("A-small.out"));
			
			int T = Integer.parseInt(BR.readLine());
			for (int I = 0; I < T; I++)
			{
				int N = Integer.parseInt(BR.readLine());
				
				TreeList A = new TreeList();
				TreeList B = new TreeList();
				int[] As = new int[N];
				int[] Bs = new int[N];
				
				for (int i = 0; i < N; i++)
				{
					StringTokenizer ST = new StringTokenizer(BR.readLine());
					int Ai = Integer.parseInt(ST.nextToken());
					int Bi = Integer.parseInt(ST.nextToken());
					A.add(Ai); As[i] = Ai;
					B.add(Bi); Bs[i] = Bi;
				}
				
				int tot = 0;
				for (int i = 0; i < N; i++)
				{
					int aI = A.indexOf(As[i]);
					int bI = B.indexOf(Bs[i]);
					if (aI > bI) tot += (aI-bI);
					else tot += (bI-aI);
				}
				PW.println("Case #"+(I+1)+": "+(tot/2));
			}
			
			PW.flush(); PW.close(); BR.close();
		}
		catch (IOException ie)
		{
			
		}
	}
	
}

class TreeList
{

	private int index = 0, elem = -1;
	private TreeList left, right;
	
	public TreeList()
	{
		
	}
	private TreeList(int root, int baseIndex)
	{
		elem = root;
		index = baseIndex;
	}
	
	public void add(int obj)
	{
		if (elem == -1) elem = obj;
		else if (elem < obj)
		{
			if (right == null) right = new TreeList(obj, index+1);
			else right.add(obj);
		}
			
		else
		{
			if (left == null) left = new TreeList(obj, index);
			else left.add(obj);
			index++;
		}
	}

	public int indexOf(int obj)
	{
		if (obj == elem) return index;
		else if (obj < elem) return left.indexOf(obj);
		else return right.indexOf(obj);
	}
	
}