import java.util.Scanner;
import java.util.Stack;

public class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		String X = in.next();
		in.close();
		Stack<Character> st = new Stack<>();
		for (int i = 0; i < X.length(); i++)
		{
			char c = X.charAt(i);
			if (c == 'S' || st.isEmpty())
			{
				st.push(c);
			} else//T??? ?? ????
			{
				if (st.peek() == 'S')
				{
					st.pop();//S????(T???)
				} else
				{
					st.push(c);//T?????
				}
			}
		}
		System.out.println(st.size());
	}
}